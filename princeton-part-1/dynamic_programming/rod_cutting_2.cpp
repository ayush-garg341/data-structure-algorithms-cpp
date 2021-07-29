#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class RodCutting{
public:
  int solveRodCutting(vector<int> &prices, int n) {
    vector<int> dp(prices.size(), -1);
    int max_price = solveRodCuttingRecursive(dp, prices, n);
    for(int i = 0; i < dp.size(); i++){
      cout << dp[i] << " ";
    }
    cout << endl;
    return max_price;
  }

  int solveRodCuttingRecursive(vector<int>&dp, vector<int>&prices, int n){
    if(dp[n-1] >= 0){
      return dp[n-1];
    }

    int q = INT_MIN;
    if (n==0){
      return 0;
    }

    for(int i = 1; i <=n; i++){
      q = max(q, prices[i-1] + solveRodCuttingRecursive(dp,  prices, n-i));
      //cout << q << endl;
    }

    dp[n-1] = q;

    return q;
    
  }
  
  
};

int main(){
  RodCutting *rc = new RodCutting();
  //vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = rc->solveRodCutting(prices, 5);

  cout  << maxProfit << endl;
  
  return 0;
}
