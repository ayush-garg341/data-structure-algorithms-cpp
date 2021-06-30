using namespace std;

#include <iostream>
#include <vector>

class RodCutting {

public:
  int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
    
    int p = prices.size();
    int l = lengths.size();

    vector<vector<int>> dp(p, vector<int>(n + 1, 0));

    if(l==0 || p == 0 || l!=p){
      return 0;
    }

    for(int i = 0; i < l; i++){
      dp[i][0] = 0;
    }

    for(int i = 0; i < l; i++){
      for(int j = 1; j <= n; j++){
	int profit1=0, profit2=0;
	if(j >= lengths[i]){
	  profit1 = prices[i] + dp[i][j-lengths[i]];
	}
	if( i > 0){
	  profit2 = dp[i-1][j];
	}

	dp[i][j] = max(profit1, profit2);
      }
    }
    
    return dp[p-1][n];
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
