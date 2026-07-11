#ifndef S21_MODEL_H
#define S21_MODEL_H

#include <string>

#include "factory_adding/element_adder.h"
#include "s21_3dparser.h"

namespace s21 {

/**
 * @brief Class representing the Model in the MVC pattern.
 *
 * This class is responsible for storing the shape data and providing methods
 * for initializing, modifying, and manipulating the shape. It uses the Shape
 * class to store the shape data and provides methods to access and modify the
 * shape.
 */
class Model {
 private:
  Shape* shape_;             /**< Pointer to the shape object. */
  std::string path_of_file_; /**< Path of the file. */

 public:
  /**
   * @brief Constructs the Model object.
   *
   * @param ptr Pointer to the Shape object.
   */
  Model(Shape* ptr) : shape_{ptr} {}

  /**
   * @brief Destroys the Model object.
   */
  ~Model();

  /**
   * @brief Sets the path of the file.
   *
   * @param path Path of the file.
   */
  void set_path_of_file(std::string path);

  /**
   * @brief Counts the number of vertices in the shape file.
   *
   * @return 0 if successful, 1 otherwise.
   */
  int s21_countInit();

  /**
   * @brief Zeroes the shape data.
   */
  void s21_zeroingShape();

  /**
   * @brief Allocates memory for the shape data.
   *
   * @return 0 if successful, 1 otherwise.
   */
  int s21_allocateShape();

  /**
   * @brief Initializes the shape from the shape file.
   *
   * @return 0 if successful, 1 otherwise.
   */
  int s21_initShape();

  /**
   * @brief Centers the shape.
   */
  void s21_centring();

  /**
   * @brief Clears the model shape.
   */
  void s21_clearModelShape();

};  // class Model

/**
 * @brief Clears the shape data.
 *
 * @param shape The shape to be cleared.
 */
void s21_clearShape(Shape* shape);

/**
 * @brief Checks if the element is within the range of valid indices and fixes
 *        it if it is not.
 *
 * @param elem The element to be checked and fixed.
 * @param flag The flag indicating which type of index to check for.
 * @param countV The number of vertices in the shape.
 */
void s21_check_and_fix(long long int& elem, int flag, unsigned int countV);

/**
 * @brief Extracts the file name from the given file path.
 *
 * @param filePath The file path.
 * @param fileName The buffer to store the file name.
 */
void s21_extractFileName(const char* filePath, char* fileName);

/**
 * @brief Adds a name to the shape based on the given string.
 *
 * @param shape The shape to be modified.
 * @param s The string containing the name.
 */
void s21_addNameFile(Shape* shape, const char* s);

/**
 * @brief Adds a vertex to the shape based on the given string.
 *
 * @param shape The shape to be modified.
 * @param s The string containing the vertex data.
 */
void s21_addV(Shape* shape, char* s);

/**
 * @brief Adds a face to the shape based on the given string.
 *
 * @param shape The shape to be modified.
 * @param s The string containing the face data.
 */
void s21_addF(Shape* shape, char* s);

/**
 * @brief Reads a polygon from the given string and stores it in the given
 *        element.
 *
 * @param elem The element to store the polygon in.
 * @param s The string containing the polygon data.
 * @param shape The shape being read from.
 *
 * @return The number of elements successfully read.
 */
int s21_readPolygon(FrameElement* elem, char** s, Shape* shape);

/**
 * @brief Sets the scale of the shape.
 *
 * @param shape The shape to be modified.
 * @param scale The scale to be set.
 *
 * @return 0 if successful, 1 otherwise.
 */
int s21_setScale(Shape* shape, double scale);

/**
 * @brief Shifts the shape in the given direction by the given amount.
 *
 * @param shape The shape to be shifted.
 * @param coord The amount to shift by.
 * @param axis The axis to shift along.
 *
 * @return 0 if successful, 1 otherwise.
 */
int s21_shifting(Shape* shape, double coord, s21_Axis axis);

/**
 * @brief Shifts the shape in the given direction by the given amount without
 *        changing the center of the shape.
 *
 * @param shape The shape to be shifted.
 * @param coord The amount to shift by.
 * @param axis The axis to shift along.
 *
 * @return 0 if successful, 1 otherwise.
 */
int s21_shifting_my(Shape* shape, double coord, s21_Axis axis);

/**
 * @brief Calculates a rotation matrix based on the given Euler angles.
 *
 * @param matrix The rotation matrix to be filled.
 * @param angulus_x The rotation angle around the X-axis.
 * @param angulus_y The rotation angle around the Y-axis.
 * @param angulus_z The rotation angle around the Z-axis.
 *
 * The Euler angles are in radians. The rotation matrix is calculated in the
 * following order: Z-axis, then Y-axis, then X-axis.
 */
void matrix(double matrix[COORDS][COORDS], double angulus_x, double angulus_y,
            double angulus_z);

/**
 * @brief Rotates a point using the given rotation matrix.
 *
 * @param vertexes The point to be rotated.
 * @param rotation_matrix The rotation matrix to apply to the point.
 *
 * @return void
 *
 * @throws None
 */
void rotate_point_with_matrix(double* vertexes,
                              double rotation_matrix[COORDS][COORDS]);

/**
 * @brief Rotates a shape in 3D space.
 *
 * @param shape The shape to rotate.
 * @param angulus_x The rotation angle in the x-axis.
 * @param angulus_y The rotation angle in the y-axis.
 * @param angulus_z The rotation angle in the z-axis.
 *
 * @throws None
 */
void figure_rotation(Shape* shape, double angulus_x, double angulus_y,
                     double angulus_z);

}  // namespace s21

#endif