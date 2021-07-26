#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    //vector<int>dp(prices.size()+1);
    int min_so_far = prices[0];
    //dp[0] = 0;
    int max_profit = 0;
    for(int i = 1; i <= prices.size(); i++){
      max_profit = max(max_profit, prices[i-1]-min_so_far);
      min_so_far = min(min_so_far, prices[i-1]);
    }

    //return dp[prices.size()];
    return max_profit;
  }
};


int main(){
  Solution *soln = new Solution();
  vector<int> prices  = {7, 1, 5, 3, 6, 4};
  cout << soln -> maxProfit(prices) << endl;
  prices = {7, 6, 4, 3, 1};
  cout << soln -> maxProfit(prices) << endl;
  return 0;
}
