#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // //vector<int>dp(prices.size()+1);
    // int min_so_far = prices[0];
    // //dp[0] = 0;
    // int max_profit = 0;
    // for(int i = 1; i <= prices.size(); i++){
    //   max_profit = max(max_profit, prices[i-1]-min_so_far);
    //   min_so_far = min(min_so_far, prices[i-1]);
    // }

    // //return dp[prices.size()];
    // return max_profit;

    /* second approach using changes in prices and computing max sub-array sum */

    vector<int>change_price(prices.size()-1);
    for(int i = 1; i < prices.size(); i++){
      change_price.push_back(prices[i] - prices[i-1]);
    }

    /* use kadane's algorithm to find max. sub-array sum to find the max. profit */
    int max_sum = 0;
    int find_negative = 0;
    for(int i = 0; i < change_price.size(); i++){
      if(change_price[i] <= find_negative + change_price[i]){
	find_negative += change_price[i];
      }
      else{
	find_negative = change_price[i];
      }

      if(find_negative > max_sum){
	max_sum = find_negative;
      }
    }

    return max_sum;
    
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
