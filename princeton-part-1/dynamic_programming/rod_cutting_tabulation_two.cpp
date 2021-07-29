#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class RodCutting{
public:
  int solveRodCutting(vector<int>&prices, int n){
    vector<int>dp(prices.size()+1, 0);
    for(int i = 1 ; i <= n; i++){
      int q = INT_MIN;
      for(int j = 1 ; j <= i; j++){
	q = max(q, prices[j-1] + dp[i-j]);
      }

      dp[i] = q;
    }

    return dp[n];
  }
};


int main(){
  RodCutting *rc = new RodCutting();
  //vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13, 14};
  int maxProfit = rc->solveRodCutting(prices, 6);
  cout << maxProfit << endl;
  return 0;
}
