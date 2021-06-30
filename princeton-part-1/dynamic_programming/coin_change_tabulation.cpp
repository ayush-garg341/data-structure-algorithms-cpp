using namespace std;

#include<iostream>
#include<vector>

class CoinChange {
public:
  int countChange(const vector<int>&denominations, int total){
    int n = denominations.size();
    vector<vector<int>>dp(n, vector<int>(total+1, 0));

    for(int i = 0; i < n; i++){
      dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) {
          dp[i][t] = dp[i - 1][t];
        }
        if (t >= denominations[i]) {
          dp[i][t] += dp[i][t - denominations[i]];
        }
      }
    }

    return dp[n-1][total];
  }
};


int main(int argc, char *argv[]){
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  delete cc;
  
  return 0;
}
