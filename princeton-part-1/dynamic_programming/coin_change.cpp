using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
public:
  int countChange(const vector<int> &denominations, int total) {

    vector<vector<int>>dp(denominations.size(), vector<int>(total+1, -1));
    
    int count = countChangeRecursive(dp, denominations, total, 0);
    return count;
  }

private:
  int countChangeRecursive(vector<vector<int>>dp, const vector<int> &denominations, int total, int currentIndex){
    if(total==0){
      return 1;
    }

    if(currentIndex >= denominations.size()){
      return 0;
    }

    int count = 0;
    if(dp[currentIndex][total]==-1){
      if(denominations[currentIndex] <= total){
	count += countChangeRecursive(dp, denominations, total - denominations[currentIndex], currentIndex);
      }
      count += countChangeRecursive(dp, denominations, total, currentIndex + 1);

      dp[currentIndex][total] = count;
    }
    return dp[currentIndex][total];
  }
  
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}
