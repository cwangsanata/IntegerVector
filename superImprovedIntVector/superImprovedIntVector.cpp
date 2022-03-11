/*
* Christopher Wangsanata
* Stalica
* COMSC-165
* November 16, 2021
*/

#include <iostream>
using namespace std;

class IntVector {
protected:
  int* numbers;
  int length;

public:
  IntVector() {
    numbers = nullptr;
    length = 0;
  }

  IntVector(int n, int val) {
    length = n;
    numbers = new int[length];
    for (int i = 0; i < n; i++)
      numbers[i] = val;
  }

  // Copy Constructor
  IntVector(const IntVector& temp) {
    length = temp.length;
    numbers = new int[length];
    for (int i = 0; i < length; i++)
      numbers[i] = temp.numbers[i];

  }

  ~IntVector() { if (length > 0) delete[] numbers; }

  int& at(int pos) const { return numbers[pos]; }

  int size() const { return length; }

  void push_back(int val) {
    int* tempNumbers = new int[++length];

    for (int i = 0; i < length - 1; i++)
      tempNumbers[i] = numbers[i];

    tempNumbers[length - 1] = val;

    delete[] numbers;
    numbers = tempNumbers;
  }

  // Overload ==
  bool operator== (const IntVector& right) { return length == right.length; }

  // Overload <
  bool operator< (const IntVector& right) { return length < right.length; }

  //Overload postfix ++
  IntVector operator++(int) {
    IntVector temp(*this);
    for (int i = 0; i < length; i++)
      numbers[i] = numbers[i] + 1;

    return temp;
  }

  // Overload [] 
  int& operator[] (const int& index) { return numbers[index]; }

  // Overload << 
  friend ostream& operator<< (ostream& os, const IntVector& vec) {
    os << "[";
    for (int i = 0; i < vec.length - 1; i++)
      os << vec.numbers[i] << ", ";
    os << vec.numbers[vec.length - 1] << "]";
    return os;
  }

  // Overload =
  const IntVector operator=(const IntVector& rhs)
  {
    if (this != &rhs)
    {
      if (rhs.numbers == nullptr)
      {
        numbers = nullptr;
        length = 0;
      }
      else
      {
        if (numbers != nullptr)
          delete[] numbers;
        length = rhs.length;
        numbers = new int[length];
        for (int i = 0; i < length; i++)
          numbers[i] = rhs.numbers[i];
      }
    }
    return *this;
   }
};

/*
* EnhancedIntVector is a derived class from IntVector.
* Adds basic search algorithms.
*/
class EnhancedIntVector : public IntVector {
  public:
    double getAverage() const {
      double total = -1;
      if (numbers != nullptr) {
        total = 0;
        for (int i = 0; i < length; i++) 
          total += numbers[i];
        total /= length;
      }
      return total;
    }

    int getHighest() const {
      int max = -1;
      if (numbers != nullptr) { 
        max = numbers[0];
        for (int i = 0; i < length; i++)
          if (numbers[i] > max)
            max = numbers[i];
      }
      return max;
    }

    int getLowest() const {
      int min = -1;
      if (numbers != nullptr) {
        min = numbers[0];
        for (int i = 0; i < length; i++)
          if (numbers[i] < min)
            min = numbers[i];
      }
      return min;
    }

    int first() const {
      if (numbers != nullptr)
        return numbers[0];
      return -1;
    }

    int last() const {
      if (numbers != nullptr)
        return numbers[length - 1];
      return -1;
    }

    bool find(int val) const {
      bool found = false;
      for (int i = 0; i < length; i++) 
        if (numbers[i] == val)
          found = true;
      return found;
    }
};

int main()
{
  EnhancedIntVector eiv;
  eiv.push_back(42);
  eiv.push_back(68);
  eiv.push_back(35);
  eiv.push_back(1);
  eiv.push_back(70);
  eiv.push_back(25);
  eiv.push_back(79);
  eiv.push_back(59);
  eiv.push_back(63);
  eiv.push_back(65);

  cout << eiv.getHighest() << endl;
  cout << eiv.getLowest() << endl;
  cout << eiv.getAverage() << endl;
  cout << eiv.first() << endl;
  cout << eiv.last() << endl;
  cout << eiv.find(25) << endl;
}
