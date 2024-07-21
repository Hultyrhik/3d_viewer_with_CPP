#ifndef S21_ELEMENT_ADDER_H_
#define S21_ELEMENT_ADDER_H_
namespace s21 {
/**
 * @brief Base class for adding elements to an array.
 *
 * @tparam T The type of elements in the array.
 */
template <typename T>
class ElementAdderBase {
 public:
  /**
   * @brief Adds an element to the array.
   *
   * @param array The array to add the element to.
   * @param count The current count of elements in the array.
   * @param elem The element to add to the array.
   */
  void addElementToArray(T* array, unsigned int& count, T elem) {
    addElement(array, count, elem);
  }

 protected:
  /**
   * @brief Adds an element to the array.
   *
   * @param array The array to add the element to.
   * @param count The current count of elements in the array.
   * @param elem The element to add to the array.
   */
  virtual void addElement(T* array, unsigned int& count, T elem) = 0;
};

/**
 * @brief A class for adding double elements to an array.
 */
class DoubleElementAdder : public ElementAdderBase<double> {
 protected:
  /**
   * @brief Adds a double element to the array.
   *
   * @param array The array to add the element to.
   * @param count The current count of elements in the array.
   * @param elem The element to add to the array.
   */
  void addElement(double* array, unsigned int& count, double elem) override {
    array[count] = elem;
    count++;
  }
};

/**
 * @brief A class for adding integer elements to an array.
 */
class IntElementAdder : public ElementAdderBase<unsigned int> {
 protected:
  /**
   * @brief Adds an integer element to the array.
   *
   * @param array The array to add the element to.
   * @param count The current count of elements in the array.
   * @param elem The element to add to the array.
   */
  void addElement(unsigned int* array, unsigned int& count,
                  unsigned int elem) override {
    array[count] = elem;
    count++;
  }
};

}  // namespace s21

#endif  // S21_ELEMENT_ADDER_H_