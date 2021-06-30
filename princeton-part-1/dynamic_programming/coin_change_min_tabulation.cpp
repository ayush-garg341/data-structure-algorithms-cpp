#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class CoinChange {
public:
  int countChangeMin(const vector<int>&denominations, int total){
    int n = denominations.size();
    vector<vector<int>>dp(n, vector<int>(total+1, numeric_limits<int>::max()));

    for(int i = 0; i < n; i++){
      dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++){
      for(int t = 1; t <= total; t++){
	if(i > 0){
	  dp[i][t] = dp[i-1][t];
	}
	if(t >= denominations[i]){
	  if(dp[i][t - denominations[i]]!=numeric_limits<int>::max()){
	    dp[i][t] = min(dp[i][t],  1 + dp[i][t-denominations[i]]);
	  }
	}
      }
    }

    return dp[n-1][total]==numeric_limits<int>::max() ? -1 : dp[n-1][total];
  }
};


int main(int argc, char *argv[]){
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {408, 186, 83, 419};
  cout << cc->countChangeMin(denominations, 6249) << endl;
  delete cc;
  
  return 0;
}
