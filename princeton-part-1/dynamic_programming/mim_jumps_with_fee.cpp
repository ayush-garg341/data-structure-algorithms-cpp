#include<iostream>
#include<vector>

using namespace std;

class Staircase {

public:
  int findMinFee(const vector<int> &fee) {
    vector<int>dp(fee.size(), 0);
    int result = findMinFeeRecursive(dp, fee, 0);
    return result;
  }

  int findMinFeeRecursive(vector<int>dp, const vector<int>&fee, int currentIndex){
    if(currentIndex>=fee.size()){
      return 0;
    }

    if(dp[currentIndex]){
      return dp[currentIndex];
    }
    
    int min1 = fee[currentIndex] + findMinFeeRecursive(dp, fee, currentIndex+1);
    int min2 = fee[currentIndex] + findMinFeeRecursive(dp , fee, currentIndex+2);
    int min3 = fee[currentIndex] + findMinFeeRecursive(dp, fee, currentIndex+3);

    dp[currentIndex] = min(min(min1, min2), min3);
    
    return dp[currentIndex];
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
