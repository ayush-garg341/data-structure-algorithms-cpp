using namespace std;

#include <iostream>
#include<vector>

class ExpressNumber {

public:
  int CountWays(int n) {
    if( n <= 2 ) return 1;
    if( n == 3 ) return 2;
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
    }

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
