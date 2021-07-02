#include<iostream>
#include<vector>

using namespace std;

class Staircase {

public:
  int findMinFee(const vector<int> &fee) {
    vector<int>dp(fee.size()+1, 0);
    dp[0] = 0;
    dp[1] = fee[0];
    dp[2] = fee[0];

    if(fee.size()<=2){
      return fee[0];
    }
    
    for(int i = 2; i < fee.size(); i++){
      dp[i+1] = min(min(dp[i]+fee[i], dp[i-1]+fee[i-1]), dp[i-2]+fee[i-2]);
    }
    
    return dp[fee.size()];
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
