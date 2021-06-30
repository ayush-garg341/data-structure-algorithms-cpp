using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int profit = solveKnapsackRecursive(profits,weights, capacity, 0);
    return profit;
  }

private:
  int solveKnapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex){
    
    if(capacity<=0 || currentIndex >= profits.size()){
      return 0;
    }

    int profit1 = 0;
    if(weights[currentIndex] <= capacity){
      profit1 = profits[currentIndex] + solveKnapsackRecursive(profits, weights, capacity-weights[currentIndex], currentIndex);
    }

    int profit2 = solveKnapsackRecursive(profits, weights, capacity, currentIndex+1);

    return max(profit1, profit2);
    
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
