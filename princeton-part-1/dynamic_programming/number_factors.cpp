using namespace std;

#include <iostream>
#include<vector>

class ExpressNumber {

public:
  int CountWays(int n) {
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    int result = CountWaysRecursive(dp, n);
    return result;
  }

  int CountWaysRecursive(vector<int>dp, int n){

    if(dp[n]){
      return dp[n];
    }

    dp[n] = CountWaysRecursive(dp, n-1) + CountWaysRecursive(dp, n-3) + CountWaysRecursive(dp, n-4);

    return dp[n];
  }
  
};

int main(int argc, char *argv[]) {
  ExpressNumber *en = new ExpressNumber();
  cout << en->CountWays(4) << endl;
  cout << en->CountWays(5) << endl;
  cout << en->CountWays(6) << endl;

  delete en;
}
