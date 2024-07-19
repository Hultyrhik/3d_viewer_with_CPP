#ifndef S21_MODEL_H
#define S21_MODEL_H

#include <string>

#include "s21_3dparser.h"

namespace s21 {

class Model {
 private:
  Shape* shape_;
  std::string path_of_file_;

 public:
  Model(Shape* ptr) : shape_{ptr} {}
  ~Model();

  void set_path_of_file(std::string path);

  int s21_countInit();

  void s21_zeroingShape();

  int s21_allocateShape();

  int s21_initShape();

  void s21_centring();

  void s21_clearModelShape();

};  // class Model

void s21_clearShape(Shape* shape);

void s21_add_elem_double(double* array, unsigned int& count, double elem);

void s21_add_elem_int(unsigned int* array, unsigned int& count, double elem);

void s21_check_and_fix(long long int& elem, int flag, unsigned int countV);

void s21_extractFileName(const char* filePath, char* fileName);

void s21_addNameFile(Shape* shape, const char* s);

void s21_addV(Shape* shape, char* s);

void s21_addF(Shape* shape, char* s);

int s21_readPolygon(FrameElement* elem, char** s, Shape* shape);

int s21_setScale(Shape* shape, double scale);

int s21_shifting(Shape* shape, double coord, s21_Axis axis);

int s21_shifting_my(Shape* shape, double coord, s21_Axis axis);

void matrix(double matrix[COORDS][COORDS], double angulus_x, double angulus_y,
            double angulus_z);

void rotate_point_with_matrix(double* vertexes,
                              double rotation_matrix[COORDS][COORDS]);

void figure_rotation(Shape* shape, double angulus_x, double angulus_y,
                     double angulus_z);

}  // namespace s21

#endif