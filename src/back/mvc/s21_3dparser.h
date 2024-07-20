#ifndef SRC_3DPARSER_H
#define SRC_3DPARSER_H

#ifndef M_PI
/**
 * @brief Definition for Valgrind memory testing on Linux distribution,
 * where M_PI is not defined in C standard
 */
#define M_PI 3.14159265358979323846
#endif

#define MAX_NAME_LENGTH 100
#define COORDS 3

namespace s21 {

/**
 * @brief Структура для хранения элементов фигуры
 */
typedef struct {
  char modelName[MAX_NAME_LENGTH];            /**< Имя модели*/
  char fileName[MAX_NAME_LENGTH];             /**< Имя файла*/
  unsigned countV; /**< Количество вершин */  //-3441
  unsigned countVertexes; /**< Количество координат вершин */
  double* vertexes; /**< Массив координат вершин фигуры */
  unsigned countLines; /**< Количество ребер */
  unsigned countL; /**< Количество сегментов парами */
  unsigned* lines; /**< Массив ребер, где сегменты идут парами */
  int fflag; /**< Индикатор отрицательных индексов. 0 индексов нет, 1 - есть
                хотя бы 1 отрицательный индекс */
  double scale; /**< Масштаб фигуры */
  double angles[COORDS]; /**< Углы вращения относительно трех осей */
  double shifts[COORDS]; /**< Сдвиг по трем координатным осям */

  double absolute_translation[3];

} Shape;

/**
 * @brief Структура для хранения элементов полигонов
 */
typedef struct {
  unsigned mask; /**< Маска заполненности данных */
  long long v;   /**< Список геометрических вершин */
  long long vt;  /**< Текстурные координаты */
  long long vn;  /**< Нормали */
} FrameElement;

/**
 * @brief Перечислимый тип для координатных осей
 */
typedef enum Axis_ { AXIS_X, AXIS_Y, AXIS_Z } s21_Axis;


}
#endif  // SRC_3DPARSER_H
