#include<iostream>
#include<vector>

using namespace std;

class Staircase {

public:
  int findMinFee(const vector<int> &fee) { 
    int result = findMinFeeRecursive(fee, 0);
    return result;
  }

  int findMinFeeRecursive(const vector<int>&fee, int currentIndex){
    if(currentIndex>=fee.size()){
      return 0;
    }
    int min1 = fee[currentIndex] + findMinFeeRecursive(fee, currentIndex+1);
    int min2 = fee[currentIndex] + findMinFeeRecursive(fee, currentIndex+2);
    int min3 = fee[currentIndex] + findMinFeeRecursive(fee, currentIndex+3);

    return min(min(min1, min2), min3);
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  vector<int> fee = {1, 2, 5, 2, 1, 2};
  cout << sc->findMinFee(fee) << endl;
  fee = vector<int>{2, 3, 4, 5};
  cout << sc->findMinFee(fee) << endl;

  delete sc;

  return 0;
}
