using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {

    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1));

    if(capacity<=0 || profits.size()!=weights.size() || profits.empty()){
      return 0;
    }

    int n = profits.size();

    for(int i = 0; i < n; i++){
      dp[i][0] = 0;
    }

    for(int c=0; c <= capacity; c++){
      if(weights[0] <= c){
	dp[0][c] = profits[0];
      }
    }

    for(int i = 1; i < n; i++){
      for(int c = 1; c <= capacity; c++){
	int profit1 = 0, profit2 = 0;

	if(weights[i] <= c){
	  profit1 = profits[i] + dp[i-1][c-weights[i]];
	}

	profit2 = dp[i-1][c];

	dp[i][c] = max(profit1, profit2);
      }
    }

    printSelectedItems(dp, profits, weights, capacity);

    return dp[profits.size()-1][capacity];
  }

private:
  void printSelectedItems(vector<vector<int>>dp, const vector<int>& profits, const vector<int>& weights, int capacity){
    cout << "Selected weights:";
    int totalProfit = dp[weights.size() - 1][capacity];
    for (int i = weights.size() - 1; i > 0; i--) {
      if (totalProfit != dp[i - 1][capacity]) {
        cout << " " << weights[i];
        capacity -= weights[i];
        totalProfit -= profits[i];
      }
    }

    if (totalProfit != 0) {
      cout << " " << weights[0] << endl;
    }
    cout << "" << endl;
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}
