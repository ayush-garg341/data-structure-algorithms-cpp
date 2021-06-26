using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    return this->solveKnapsackRecursive(profits, weights, capacity, 0);
  }

  int solveKnapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex){
    if(capacity<=0 || currentIndex >= profits.size()){
      return 0;
    }

    int profit1 = 0;
    
    if(weights[currentIndex] <= capacity){
      profit1 = profits[currentIndex] + solveKnapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }

    int profit2  = solveKnapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return max(profit1, profit2);
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
