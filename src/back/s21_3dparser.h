#ifndef SRC_3DPARSER_H
#define SRC_3DPARSER_H
#define _GNU_SOURCE

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#ifndef M_PI
/**
 * @brief Definition for Valgrind memory testing on Linux distribution,
 * where M_PI is not defined in C standard
 */
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Добавление элемента в массив с перераспределением памяти
 *
 * @param array Указатель на массив
 * @param count Счетчик элементов в массиве
 * @param elem Добавляемый элемент
 */
#define S21_ADD_ELEM(array, count, elem) \
  do {                                   \
    (count)++;                           \
    (array)[(count)-1] = (elem);         \
  } while (0)

/**
 * @brief Исправление отрицательных целых чисел в массиве ребер
 *
 * @param lines Указатель на массив ребер
 * @param countLines Счетчик элементов в массиве
 * @param countV Счетчик вершин в фигуре
 */
#define S21_CHECK_AND_FIX(elem, flag, countV) \
  do {                                        \
    if ((flag) == 1 && (countV) != 0) {       \
      (elem) += (countV + 1);                 \
    }                                         \
  } while (0)

#define MAX_NAME_LENGTH 100
#define COORDS 3

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
typedef enum Axis_ { AXIS_X, AXIS_Y, AXIS_Z } Axis;

/**
 * @brief Функция чтения файла объекта и инициализации структуры фигуры
 *
 * @param shape Указатель на структуру, в которую будет записано содержимое
 * фигуры
 * @param file Имя файла .obj для чтения
 * @return int 0 - успешно
 * @return int 1 - ошибка
 */
int s21_initShape(Shape* shape, const char* file);

/**
 * @brief Функция обнуления структуры
 *
 * @param shape Указатель на структуру фигуры
 */
void s21_zeroingShape(Shape* shape);

/**
 * @brief Добавление названия модели
 *
 * @param shape Указатель на структуру фигуры
 * @param s Одна строка из файла
 */
void s21_addNameFile(Shape* shape, const char* s);

/**
 * @brief Добавление названия файла
 *
 * @param filePath Указатель на имя файла
 * @param fileName Указатель на строку для записи имени
 */
void s21_extractFileName(const char* filePath, char* fileName);

/**
 * @brief Добавление вершины в структуру фигуры
 *
 * @param shape Указатель на структуру фигуры
 * @param s Одна строка из файла
 */
void s21_addV(Shape* shape, char* s);

/**
 * @brief Добавление ребер в структуру фигуры
 *
 * @param shape Указатель на структуру фигуры
 * @param s Одна строка из файла
 */
void s21_addF(Shape* shape, char* s);

/**
 * @brief Чтение координаты вершины полигона
 *
 * @param elem Структура, в которую будет записана координата полигона
 * @param s Указатель на часть строки
 * @return int 0 - успешно
 * @return int 1 - ошибка
 */
int s21_readPolygon(FrameElement* elem, char** s, Shape* shape);

/**
 * @brief Преобразование координат для попадания в область 1 < x, y, z < -1
 *
 * @param shape Указатель на структуру фигуры
 */
void s21_centring(Shape* shape);

/**
 * @brief Установка масштаба объекта
 *
 * @param shape Указатель на структуру фигуры
 * @param scale Масштаб фигуры
 * @return int 0 - успешно
 * @return int 1 - ошибка
 */
int s21_setScale(Shape* shape, double scale);

/**
 * @brief Выполняет сдвиг вершин вдоль одной из осей
 *
 * @param shape Указатель на структуру фигуры
 * @param coord Число, на которое сдвигается каждая координата определенной оси
 * @param axis Одна из трех координатных осей
 * @return int 0 - успешно
 * @return int 1 - ошибка
 */
int s21_shifting(Shape* shape, double coord, Axis axis);

/**
 * @brief Функция освобождения памяти
 *
 * @param shape Указатель на структуру фигуры
 */
void s21_clearShape(Shape* shape);

void matrix(double matrix[COORDS][COORDS], double angulus_x, double angulus_y,
            double angulus_z);
/**
 * @brief Функция для вычисления новой точки на координатной плоскости
 *
 * @param vertexes Массив с координатами вершин
 * @param rotation_matrix Матрица поворота
 */
void rotate_point_with_matrix(double* vertexes,
                              double rotation_matrix[COORDS][COORDS]);

/**
 * @brief Функция для печати содержимого структуры
 *
 * @param shape Структура obj файла
 * @param angulus_x Угол поворота по оси x
 * @param angulus_y Угол поворота по оси y
 * @param angulus_z Угол поворота по оси z
 */
void figure_rotation(Shape* shape, double angulus_x, double angulus_y,
                     double angulus_z);
// void figure_rotation(Shape *object_3d, double angle_x, double angle_y,
//                      double angle_z);

#endif  // SRC_3DPARSER_H
