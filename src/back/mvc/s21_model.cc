#include "s21_model.h"

#include <cstdio>
#include <cstring>
#include <cmath>


namespace s21 {
    
int Model::s21_countInit() {
  FILE* fp = std::fopen(this->path_of_file_.c_str(), "r");
  if (!fp) {
    std::perror("Error opening file");
    return 1;
  }
  char s[200]{};
  this->s21_zeroingShape();
  while (fgets(s, 200, fp) && s[0]) {
    char c = 0;
    int shift = 0;
    std::sscanf(s, " %c%n", &c, &shift);
    if (c == 'v' && s[shift] == ' ')
      this->shape_->countVertexes += 3;
    else if (c == 'f' && s[shift] == ' ') {
      if (s[shift + 1] == '-') {
         this->shape_->fflag = 1;
      }
      s21_addF( this->shape_, s + 1);
    }
  }
  return 0;
}

Model::~Model (){
}

void Model::set_path_of_file(std::string path){
  this->path_of_file_ = path;
}

void Model::s21_zeroingShape() {
  std::memset(this->shape_->modelName, 0, sizeof(this->shape_->modelName));
  std::memset(this->shape_->fileName, 0, sizeof(this->shape_->fileName));
  this->shape_->countLines = 0;
  this->shape_->countL = 0;
  this->shape_->countVertexes = 0;
  this->shape_->countV = 0;
  this->shape_->lines = nullptr;
  this->shape_->vertexes = nullptr;
  this->shape_->fflag = 0;
  this->shape_->scale = 1;
  for (int i = 0; i < 3; ++i) {
    this->shape_->angles[i] = 0;
    this->shape_->shifts[i] = 0;
    this->shape_->absolute_translation[i] = 0;
  }
}

int Model::s21_allocateShape() {
  s21_extractFileName(this->path_of_file_.c_str(), this->shape_->fileName);
  FILE* fpi = std::fopen(this->path_of_file_.c_str(), "r");
  if (!fpi) {
    std::perror("Error opening file");
    return 1;
  }

  if (!this->shape_->countVertexes) {
    std::perror("Incorrect file");
    return 1;
  }
  this->shape_->vertexes = new double[this->shape_->countVertexes]();
  this->shape_->countV = this->shape_->countVertexes / 3;
  this->shape_->lines = new unsigned int[this->shape_->countLines]();
  this->shape_->countL = this->shape_->countLines / 6;

  char si[200];
  this->shape_->countLines = 0;
  this->shape_->countVertexes = 0;
  while (std::fgets(si, 200, fpi) && si[0]) {
    char c = 0;
    int shift = 0;
    std::sscanf(si, " %c%n", &c, &shift);
    if ((c == 'o') && si[shift] == ' ' && this->shape_->modelName[0] == 0)
      s21_addNameFile(this->shape_, si);
    else if (c == 'v' && si[shift] == ' ')
      s21_addV(this->shape_, si + 1);
    else if (c == 'f' && si[shift] == ' ')
      s21_addF(this->shape_, si + 1);
  }

  std::fclose(fpi);
  return 0;
}

int Model::s21_initShape() {
  /* Проверка входных ошибок */
  if (!this->shape_ || !this->path_of_file_.c_str()) return 1;

  int counter_init = this->s21_countInit();
  if (!counter_init) counter_init = this->s21_allocateShape();
  if (counter_init) return counter_init;

  this->s21_centring();

  return 0;
}

void Model::s21_centring() {
  double minCoord[COORDS] = {this->shape_->vertexes[0], this->shape_->vertexes[1],
                             this->shape_->vertexes[2]};
  double maxCoord[COORDS] = {this->shape_->vertexes[0], this->shape_->vertexes[1],
                             this->shape_->vertexes[2]};
  // поиск мин и макс координат
  for (unsigned i = 0; i < this->shape_->countVertexes; ++i) {
    if (this->shape_->vertexes[i] < minCoord[i % 3])
      minCoord[i % 3] = this->shape_->vertexes[i];
    if (this->shape_->vertexes[i] > maxCoord[i % 3])
      maxCoord[i % 3] = this->shape_->vertexes[i];
  }
  // поиск центра и шкалы
  double center[COORDS], minScale = 1, maxScale = 1;
  for (int i = 0; i < 3; ++i) {
    center[i] = (maxCoord[i] + minCoord[i]) / 2;
    maxCoord[i] -= center[i];
    minCoord[i] -= center[i];
    minScale = minScale > std::fabs(maxCoord[i]) ? std::fabs(maxCoord[i]) : minScale;
    minScale = minScale > std::fabs(minCoord[i]) ? std::fabs(minCoord[i]) : minScale;
    maxScale = maxScale < std::fabs(maxCoord[i]) ? std::fabs(maxCoord[i]) : maxScale;
    maxScale = maxScale < std::fabs(minCoord[i]) ? std::fabs(minCoord[i]) : maxScale;
  }
  // шкалирование
  this->shape_->scale = maxScale >= 1 || minScale < 1e-6 ? 1 / maxScale : 1 / minScale;
  for (unsigned i = 0; i < this->shape_->countVertexes; ++i)
    this->shape_->vertexes[i] =
        (this->shape_->vertexes[i] - center[i % 3]) * this->shape_->scale * 0.8;
  this->shape_->scale = 1;
}


void s21_extractFileName(const char* filePath, char* fileName) {
  const char* lastSlash = std::strrchr(filePath, '/');
  const char* lastBackslash = std::strrchr(filePath, '\\');
  const char* lastSeparator =
      lastSlash > lastBackslash ? lastSlash : lastBackslash;

  if (lastSeparator) {
    std::strcpy(fileName, lastSeparator + 1);
  } else {
    std::strcpy(fileName, filePath);
  }
  char* lastDot = std::strrchr(fileName, '.');
  if (lastDot) {
    *lastDot = '\0';
  }
}

void Model::s21_clearModelShape() {
  if (this->shape_->vertexes != nullptr) delete[] this->shape_->vertexes;
  if (this->shape_->lines != nullptr) delete[] this->shape_->lines;
}

void s21_clearShape(Shape* shape) {
  if (shape->vertexes != nullptr) delete[] shape->vertexes;
  if (shape->lines != nullptr) delete[] shape->lines;
}

void matrix(double matrix[COORDS][COORDS], double angulus_x, double angulus_y,
            double angulus_z) {
  matrix[0][0] = std::cos(angulus_y) * std::cos(angulus_z);
  matrix[0][1] = -std::sin(angulus_z) * std::cos(angulus_y);
  matrix[0][2] = std::sin(angulus_y);
  matrix[1][0] = std::sin(angulus_x) * std::sin(angulus_y) * std::cos(angulus_z) +
                 std::sin(angulus_z) * std::cos(angulus_x);
  matrix[1][1] = -std::sin(angulus_x) * std::sin(angulus_y) * std::sin(angulus_z) +
                 std::cos(angulus_x) * std::cos(angulus_z);
  matrix[1][2] = -std::sin(angulus_x) * std::cos(angulus_y);
  matrix[2][0] = std::sin(angulus_x) * std::sin(angulus_z) -
                 std::sin(angulus_y) * std::cos(angulus_x) * std::cos(angulus_z);
  matrix[2][1] = std::sin(angulus_x) * std::cos(angulus_z) +
                 std::sin(angulus_y) * std::sin(angulus_z) * std::cos(angulus_x);
  matrix[2][2] = std::cos(angulus_x) * std::cos(angulus_y);
}

void rotate_point_with_matrix(double* vertexes,
                              double rotation_matrix[COORDS][COORDS]) {
  double x = vertexes[0];
  double y = vertexes[1];
  double z = vertexes[2];

  vertexes[0] = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y +
                rotation_matrix[0][2] * z;
  vertexes[1] = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y +
                rotation_matrix[1][2] * z;
  vertexes[2] = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y +
                rotation_matrix[2][2] * z;
}

void figure_rotation(Shape* shape, double angulus_x, double angulus_y,
                     double angulus_z) {
  double factor = 0.0;

  if (shape->absolute_translation[AXIS_X] != 0 ||
      shape->absolute_translation[AXIS_Y] != 0 ||
      shape->absolute_translation[AXIS_Z] != 0) {
    factor = shape->scale / 1;
    factor = 1.0;

    if (shape->absolute_translation[AXIS_X] != 0) {
      s21_shifting_my(shape, factor * -1 * shape->absolute_translation[AXIS_X],
                      AXIS_X);
    }
    if (shape->absolute_translation[AXIS_Y] != 0) {
      s21_shifting_my(shape, factor * -1 * shape->absolute_translation[AXIS_Y],
                      AXIS_Y);
    }
    if (shape->absolute_translation[AXIS_Z] != 0) {
      s21_shifting_my(shape, factor * -1 * shape->absolute_translation[AXIS_Z],
                      AXIS_Z);
    }
  }

  double result_matrix[COORDS][COORDS] = {
      0,
  };
  matrix(result_matrix, angulus_x * M_PI / 180, angulus_y * M_PI / 180,
         angulus_z * M_PI / 180);
  for (unsigned i = 0; i + 3 <= shape->countVertexes; i += 3) {
    rotate_point_with_matrix(shape->vertexes + i, result_matrix);
  }

  if (shape->absolute_translation[AXIS_X] != 0 ||
      shape->absolute_translation[AXIS_Y] != 0 ||
      shape->absolute_translation[AXIS_Z] != 0) {
    if (shape->absolute_translation[AXIS_X] != 0) {
      s21_shifting_my(shape, factor * shape->absolute_translation[AXIS_X],
                      AXIS_X);
    }
    if (shape->absolute_translation[AXIS_Y] != 0) {
      s21_shifting_my(shape, factor * shape->absolute_translation[AXIS_Y],
                      AXIS_Y);
    }
    if (shape->absolute_translation[AXIS_Z] != 0) {
      s21_shifting_my(shape, factor * shape->absolute_translation[AXIS_Z],
                      AXIS_Z);
    }
  }
}

void s21_addNameFile(Shape* shape, const char* s) {
  char type;
  char name[MAX_NAME_LENGTH];
  int n;

  std::sscanf(s, " %c %n", &type, &n);

  if (type == 'o') {
    std::sscanf(s + n, "%s", name);
    std::strncpy(shape->modelName, name, MAX_NAME_LENGTH);
    shape->modelName[MAX_NAME_LENGTH - 1] = '\0';
  }
}

void s21_addV(Shape* shape, char* s) {
  double coord;
  int shift;
  for (int i = 0; i < 3; ++i) {
    std::sscanf(s, "%lf%n", &coord, &shift);
    s21_add_elem_double(shape->vertexes, shape->countVertexes, coord);
    s += shift;
  }
}

void s21_addF(Shape* shape, char* s) {
  FrameElement elem, firstElem;
  if (shape->vertexes != nullptr) {
    if (s21_readPolygon(&firstElem, &s, shape)) {
      s21_add_elem_int(shape->lines, shape->countLines, firstElem.v - 1);
    }
    while (s21_readPolygon(&elem, &s, shape)) {
      s21_add_elem_int(shape->lines, shape->countLines, elem.v - 1);
      s21_add_elem_int(shape->lines, shape->countLines, elem.v - 1);
    }
    if (firstElem.mask) {
      s21_add_elem_int(shape->lines, shape->countLines, firstElem.v - 1);
    }
  } else {
    if (s21_readPolygon(&firstElem, &s, shape)) {
      shape->countLines++;
    }
    while (s21_readPolygon(&elem, &s, shape)) {
      shape->countLines += 2;
    }
    if (firstElem.mask) {
      shape->countLines++;
    }
  }
}

int s21_readPolygon(FrameElement* elem, char** s, Shape* shape) {
  int shift = 0;
  elem->mask = 0;

  if (std::sscanf(*s, "%lld%n", &elem->v, &shift) == 1) {
    s21_check_and_fix(elem->v, shape->fflag, (shape->countVertexes / 3));
    elem->mask = 4;
    *s += shift;
  }

  if (elem->mask == 4 &&
      std::sscanf(*s, "/%lld/%lld%n", &elem->vt, &elem->vn, &shift) == 2) {
    s21_check_and_fix(elem->vt, shape->fflag, (shape->countVertexes / 3));
    s21_check_and_fix(elem->vn, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 7;
  }

  if (elem->mask == 4 && std::sscanf(*s, "//%lld%n", &elem->vn, &shift) == 1) {
    s21_check_and_fix(elem->vn, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 5;
  }

  if (elem->mask == 4 && std::sscanf(*s, "/%lld%n", &elem->vt, &shift) == 1) {
    s21_check_and_fix(elem->vt, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 6;
  }

  return elem->mask;
}

int s21_setScale(Shape* shape, double scale) {
  if (!shape) return 1;
  double shift = scale / shape->scale;
  for (unsigned i = 0; i < shape->countVertexes; ++i) {
    shape->vertexes[i] *= shift;
  }
  shape->scale = scale;
  return 0;
}

int s21_shifting(Shape* shape, double coord, s21_Axis axis) {
  if (!shape) return 1;
  double shift = coord - shape->shifts[axis];
  for (unsigned i = 0; i < shape->countVertexes; i += 3)
    shape->vertexes[i + axis] += shift;
  shape->shifts[axis] = coord;
  return 0;
}

int s21_shifting_my(Shape* shape, double coord, s21_Axis axis) {
  if (!shape) return 1;

  for (unsigned i = 0; i < shape->countVertexes; i += 3)
    shape->vertexes[i + axis] += coord;

  return 0;
}

void s21_add_elem_double(double* array, unsigned int& count, double elem){
    count++;                           
    array[count-1] = elem;         
}

void s21_add_elem_int(unsigned int* array, unsigned int& count, double elem){
    count++;                           
    array[count-1] = elem;  
}

void s21_check_and_fix(long long int& elem, int flag, unsigned int countV) {                              
    if (flag == 1 && countV != 0) {       
      elem += countV + 1;                 
    }                                         
}

}  // namespace s21