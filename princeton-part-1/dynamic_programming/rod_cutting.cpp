using namespace std;

#include <iostream>
#include <vector>

class RodCutting {

public:
  int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
    vector<vector<int>> dp(prices.size(), vector<int>(n + 1, -1));
    int profit = solveRodCuttingRecursive(dp, lengths, prices, n, 0);
    return profit;
  }

private:
  int solveRodCuttingRecursive(vector<vector<int>>dp, const vector<int> &lengths, vector<int> &prices, int n, int currentIndex){

    if(n<=0 || currentIndex >= prices.size()){
      return 0;
    }

    if(dp[currentIndex][n]!=-1){
      return dp[currentIndex][n];
    }
    
    int profit1 = 0;
    if( n >= lengths[currentIndex]){
      profit1 = prices[currentIndex] + solveRodCuttingRecursive(dp, lengths, prices, n-lengths[currentIndex], currentIndex);
    }

    int profit2 = solveRodCuttingRecursive(dp, lengths, prices, n, currentIndex + 1);

    dp[currentIndex][n] = max(profit1, profit2);
    
    return dp[currentIndex][n];
    
  }
  
};

int main(int argc, char *argv[]) {
  RodCutting *rc = new RodCutting();
  vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = rc->solveRodCutting(lengths, prices, 5);
  cout << maxProfit << endl;

  delete rc;
}
