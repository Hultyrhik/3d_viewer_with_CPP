#include "s21_3dparser.h"

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

int s21_countInit(Shape* shape, const char* file) {
  FILE* fp = fopen(file, "r");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }
  char s[200];
  s21_zeroingShape(shape);
  while (fgets(s, 200, fp) && s[0]) {
    char c = 0;
    int shift = 0;
    sscanf(s, " %c%n", &c, &shift);
    if (c == 'v' && s[shift] == ' ')
      shape->countVertexes += 3;
    else if (c == 'f' && s[shift] == ' ') {
      if (s[shift + 1] == '-') {
        shape->fflag = 1;
      }
      s21_addF(shape, s + 1);
    }
  }

  fclose(fp);
  return 0;
}

int s21_allocateShape(Shape* shape, const char* file) {
  s21_extractFileName(file, shape->fileName);
  FILE* fpi = fopen(file, "r");
  if (!fpi) {
    perror("Error opening file");
    return 1;
  }

  if (!shape->countVertexes) {
    perror("Incorrect file");
    return 1;
  }
  shape->vertexes = calloc(sizeof(double), shape->countVertexes);
  shape->countV = shape->countVertexes / 3;
  shape->lines = calloc(sizeof(unsigned), shape->countLines);
  shape->countL = shape->countLines / 6;

  char si[200];
  shape->countLines = 0;
  shape->countVertexes = 0;
  while (fgets(si, 200, fpi) && si[0]) {
    char c = 0;
    int shift = 0;
    sscanf(si, " %c%n", &c, &shift);
    if ((c == 'o') && si[shift] == ' ' && shape->modelName[0] == 0)
      s21_addNameFile(shape, si);
    else if (c == 'v' && si[shift] == ' ')
      s21_addV(shape, si + 1);
    else if (c == 'f' && si[shift] == ' ')
      s21_addF(shape, si + 1);
  }

  fclose(fpi);
  return 0;
}

int s21_initShape(Shape* shape, const char* file) {
  /* Проверка входных ошибок */
  if (!shape || !file) return 1;

  int counter_init = s21_countInit(shape, file);
  if (!counter_init) counter_init = s21_allocateShape(shape, file);
  if (counter_init) return counter_init;

  s21_centring(shape);

  return 0;
}

void s21_zeroingShape(Shape* shape) {
  memset(shape->modelName, 0, sizeof(shape->modelName));
  memset(shape->fileName, 0, sizeof(shape->fileName));
  shape->countLines = 0;
  shape->countL = 0;
  shape->countVertexes = 0;
  shape->countV = 0;
  shape->lines = NULL;
  shape->vertexes = NULL;
  shape->fflag = 0;
  shape->scale = 1;
  for (int i = 0; i < 3; ++i) {
    shape->angles[i] = 0;
    shape->shifts[i] = 0;
    shape->absolute_translation[i] = 0;
  }
}

void s21_extractFileName(const char* filePath, char* fileName) {
  const char* lastSlash = strrchr(filePath, '/');
  const char* lastBackslash = strrchr(filePath, '\\');
  const char* lastSeparator =
      lastSlash > lastBackslash ? lastSlash : lastBackslash;

  if (lastSeparator) {
    strcpy(fileName, lastSeparator + 1);
  } else {
    strcpy(fileName, filePath);
  }
  char* lastDot = strrchr(fileName, '.');
  if (lastDot) {
    *lastDot = '\0';
  }
}

void s21_addNameFile(Shape* shape, const char* s) {
  char type;
  char name[MAX_NAME_LENGTH];
  int n;

  sscanf(s, " %c %n", &type, &n);

  if (type == 'o') {
    sscanf(s + n, "%s", name);
    strncpy(shape->modelName, name, MAX_NAME_LENGTH);
    shape->modelName[MAX_NAME_LENGTH - 1] = '\0';
  }
}

void s21_addV(Shape* shape, char* s) {
  double coord;
  int shift;
  for (int i = 0; i < 3; ++i) {
    sscanf(s, "%lf%n", &coord, &shift);
    s21_add_elem_double(shape->vertexes, shape->countVertexes, coord);
    s += shift;
  }
}

void s21_addF(Shape* shape, char* s) {
  FrameElement elem, firstElem;
  if (shape->vertexes != NULL) {
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

  if (sscanf(*s, "%lld%n", &elem->v, &shift) == 1) {
    s21_check_and_fix(elem->v, shape->fflag, (shape->countVertexes / 3));
    elem->mask = 4;
    *s += shift;
  }

  if (elem->mask == 4 &&
      sscanf(*s, "/%lld/%lld%n", &elem->vt, &elem->vn, &shift) == 2) {
    s21_check_and_fix(elem->vt, shape->fflag, (shape->countVertexes / 3));
    s21_check_and_fix(elem->vn, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 7;
  }

  if (elem->mask == 4 && sscanf(*s, "//%lld%n", &elem->vn, &shift) == 1) {
    s21_check_and_fix(elem->vn, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 5;
  }

  if (elem->mask == 4 && sscanf(*s, "/%lld%n", &elem->vt, &shift) == 1) {
    s21_check_and_fix(elem->vt, shape->fflag, (shape->countVertexes / 3));
    *s += shift;
    elem->mask = 6;
  }

  return elem->mask;
}

void s21_centring(Shape* shape) {
  double minCoord[COORDS] = {shape->vertexes[0], shape->vertexes[1],
                             shape->vertexes[2]};
  double maxCoord[COORDS] = {shape->vertexes[0], shape->vertexes[1],
                             shape->vertexes[2]};
  // поиск мин и макс координат
  for (unsigned i = 0; i < shape->countVertexes; ++i) {
    if (shape->vertexes[i] < minCoord[i % 3])
      minCoord[i % 3] = shape->vertexes[i];
    if (shape->vertexes[i] > maxCoord[i % 3])
      maxCoord[i % 3] = shape->vertexes[i];
  }
  // поиск центра и шкалы
  double center[COORDS], minScale = 1, maxScale = 1;
  for (int i = 0; i < 3; ++i) {
    center[i] = (maxCoord[i] + minCoord[i]) / 2;
    maxCoord[i] -= center[i];
    minCoord[i] -= center[i];
    minScale = minScale > fabs(maxCoord[i]) ? fabs(maxCoord[i]) : minScale;
    minScale = minScale > fabs(minCoord[i]) ? fabs(minCoord[i]) : minScale;
    maxScale = maxScale < fabs(maxCoord[i]) ? fabs(maxCoord[i]) : maxScale;
    maxScale = maxScale < fabs(minCoord[i]) ? fabs(minCoord[i]) : maxScale;
  }
  // шкалирование
  shape->scale = maxScale >= 1 || minScale < 1e-6 ? 1 / maxScale : 1 / minScale;
  for (unsigned i = 0; i < shape->countVertexes; ++i)
    shape->vertexes[i] =
        (shape->vertexes[i] - center[i % 3]) * shape->scale * 0.8;
  shape->scale = 1;
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

int s21_shifting(Shape* shape, double coord, Axis axis) {
  if (!shape) return 1;
  double shift = coord - shape->shifts[axis];
  for (unsigned i = 0; i < shape->countVertexes; i += 3)
    shape->vertexes[i + axis] += shift;
  shape->shifts[axis] = coord;
  return 0;
}

int s21_shifting_my(Shape* shape, double coord, Axis axis) {
  if (!shape) return 1;

  for (unsigned i = 0; i < shape->countVertexes; i += 3)
    shape->vertexes[i + axis] += coord;

  return 0;
}

void s21_clearShape(Shape* shape) {
  if (shape->vertexes != NULL) free(shape->vertexes);
  if (shape->lines != NULL) free(shape->lines);
}

void matrix(double matrix[COORDS][COORDS], double angulus_x, double angulus_y,
            double angulus_z) {
  matrix[0][0] = cos(angulus_y) * cos(angulus_z);
  matrix[0][1] = -sin(angulus_z) * cos(angulus_y);
  matrix[0][2] = sin(angulus_y);
  matrix[1][0] = sin(angulus_x) * sin(angulus_y) * cos(angulus_z) +
                 sin(angulus_z) * cos(angulus_x);
  matrix[1][1] = -sin(angulus_x) * sin(angulus_y) * sin(angulus_z) +
                 cos(angulus_x) * cos(angulus_z);
  matrix[1][2] = -sin(angulus_x) * cos(angulus_y);
  matrix[2][0] = sin(angulus_x) * sin(angulus_z) -
                 sin(angulus_y) * cos(angulus_x) * cos(angulus_z);
  matrix[2][1] = sin(angulus_x) * cos(angulus_z) +
                 sin(angulus_y) * sin(angulus_z) * cos(angulus_x);
  matrix[2][2] = cos(angulus_x) * cos(angulus_y);
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
