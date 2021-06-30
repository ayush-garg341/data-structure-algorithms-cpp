using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));
    int profit = solveKnapsackRecursive(dp, profits,weights, capacity, 0);
    return profit;
  }

private:
  int solveKnapsackRecursive(vector<vector<int>>dp, const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex){
    
    if(capacity<=0 || currentIndex >= profits.size()){
      return 0;
    }

    if(dp[currentIndex][capacity]!=-1){
      return dp[currentIndex][capacity];
    }
    
    int profit1 = 0;
    if(weights[currentIndex] <= capacity){
      profit1 = profits[currentIndex] + solveKnapsackRecursive(dp, profits, weights, capacity-weights[currentIndex], currentIndex);
    }

    int profit2 = solveKnapsackRecursive(dp, profits, weights, capacity, currentIndex+1);

    dp[currentIndex][capacity] = max(profit1, profit2);
    
    return  dp[currentIndex][capacity];
    
  }
  
  
};

int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 65};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;

  delete ks;
}
