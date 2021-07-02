using namespace std;

#include <iostream>
#include<vector>

class Staircase {
public:
  int CountWays(int n) {
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    if(n < 0){
      return 0;
    }
    
    if(n<=2){
      return dp[n];
    }

    for(int i = 3; i <=n; i++){
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
    
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
