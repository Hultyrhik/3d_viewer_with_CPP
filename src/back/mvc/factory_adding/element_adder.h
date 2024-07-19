#ifndef S21_ELEMENT_ADDER_H_
#define S21_ELEMENT_ADDER_H_
namespace s21 {
template <typename T>
class ElementAdderBase {
 public:
  void addElementToArray(T* array, unsigned int& count, T elem) {
    addElement(array, count, elem);
  }

 protected:
  virtual void addElement(T* array, unsigned int& count, T elem) = 0;
};

class DoubleElementAdder : public ElementAdderBase<double> {
 protected:
  void addElement(double* array, unsigned int& count, double elem) override {
    array[count] = elem;
    count++;
  }
};

class IntElementAdder : public ElementAdderBase<unsigned int> {
 protected:
  void addElement(unsigned int* array, unsigned int& count,
                  unsigned int elem) override {
    array[count] = elem;
    count++;
  }
};

}  // namespace s21

#endif  // S21_ELEMENT_ADDER_H_