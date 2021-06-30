using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, 0));

    int p = profits.size();

    for(int i = 0; i < p; i++){
      dp[i][0] = 0;
    }
    

    for(int i = 0; i < p; i++){
      for(int c = 1; c <= capacity; c++){

	int profit1=0, profit2=0;
	
	if(c>=weights[i]){
	  profit1 = profits[i] + dp[i][c-weights[i]];
	}
	if(i > 0){
	  profit2 = dp[i-1][c];
	}

	dp[i][c] = max(profit1, profit2);
      }
    }
    
    return dp[p-1][capacity];
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
