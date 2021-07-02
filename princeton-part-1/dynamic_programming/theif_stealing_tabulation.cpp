using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) {
    vector<int>dp(wealth.size());
    if(wealth.size()==0){
      return 0;
    }
    
    if(wealth.size()==1){
      return wealth[0];
    }

    dp[0] = wealth[0];
    dp[1] = max(wealth[0], wealth[1]);                 

    for (int i = 2; i < wealth.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i-2] + wealth[i]);
    }
    
    return dp[wealth.size()-1]; 
  }
  
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{15, 25};
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}
