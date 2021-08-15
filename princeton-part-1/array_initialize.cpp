#include <iostream>
using namespace std;

class Something {
private:
  
  int myArray[10];
  
  // int myArray[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }; will give complier error
  
public:
  
  // Something() {
  //   //myArray[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }; // will give error.
  //   myArray{5, 5, 5, 5, 5, 5, 5, 5, 5, 5}; // will also give error
  // }

  Something()
    : myArray { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }
  {
  }
  
  int ShowThingy(int what) {
    return myArray[what];
  }
  
  ~Something() {}
};

int main () {
  Something Thing;
  std::cerr << Thing.ShowThingy(3) << endl;
  return 0;
}
