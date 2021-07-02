using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {
public:
  int countMinJumps(const vector<int> &jumps) {
    int result = countMinJumpsRecursive(jumps,  0);
    return result;
  }

  int countMinJumpsRecursive(const vector<int> &jumps,  int currentIndex){
    
    if(currentIndex >= jumps.size()){
      return 0;
    }
    
    int nextIndex = currentIndex + jumps[currentIndex];
    int count = 0;
    if(nextIndex <= jumps.size()-1){
      count += 1 + countMinJumpsRecursive(jumps,  nextIndex);
    }
    return count;
    
  }
  
};

int main(int argc, char *argv[]) {
  ArrayJump *aj = new ArrayJump();
  vector<int> jumps = {2, 1, 1, 1, 4};
  cout << aj->countMinJumps(jumps) << endl;
  jumps = vector<int>{1, 1, 3, 6, 9, 3, 0, 1, 3};
  cout << aj->countMinJumps(jumps) << endl;

  delete aj;
}
