using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {
public:
  int countMinJumps(const vector<int> &jumps) {
    return countMinJumpsRecursive(jumps, 0);
  }

  int countMinJumpsRecursive(const vector<int> &jumps, int currentIndex){
    if(currentIndex == jumps.size()-1){
      return 0;
    }

    if(jumps[currentIndex]==0){
      return numeric_limits<int>::max();
    }

    int startIndex = currentIndex + 1;
    int totalJumps = numeric_limits<int>::max();
    int endIndex = currentIndex + jumps[currentIndex];
    
    while(startIndex <= endIndex && startIndex < jumps.size()){
      int minJumps = countMinJumpsRecursive(jumps, startIndex++);
      if(minJumps != numeric_limits<int>::max()){
	totalJumps = min(totalJumps, minJumps+1);
      }
    }
    return totalJumps;
    
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
