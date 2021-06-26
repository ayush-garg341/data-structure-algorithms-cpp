using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    if(capacity==0){
      return 0;
    }
    int max_profit = 0;
    int size = profits.size();
    int profit = 0;
    
    for(int i = 0; i < size-1; i++){
      for(int j = i+1; j < size ; j++){
	if(weights[i] + weights[j] <= capacity){
	  profit = profits[i] + profits[j];
	  if(profit > max_profit){
	    max_profit = profit;
	  }
	}
      }
    }
    
    return max_profit;
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
