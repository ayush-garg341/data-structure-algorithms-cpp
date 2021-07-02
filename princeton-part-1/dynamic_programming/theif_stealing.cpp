using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) {

    vector<int>dp(wealth.size());
    
    int result = findMaxStealReursive(dp, wealth, 0);
    return result; 
  }


  int findMaxStealReursive(vector<int>dp, const vector<int> &wealth, int currentIndex){
    if(currentIndex >= wealth.size()){
      return 0;
    }

    if(dp[currentIndex]){
      return dp[currentIndex];
    }

    
    int steal1 = wealth[currentIndex] + findMaxStealReursive(dp, wealth, currentIndex + 2);

    // The below line might give heap buffer overflow.
    // int steal2 = wealth[currentIndex+1] + findMaxStealReursive(wealth, currentIndex + 3);

    int steal2 = findMaxStealReursive(dp, wealth, currentIndex+1);

    dp[currentIndex] = max(steal1, steal2);
    
    return dp[currentIndex];
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
