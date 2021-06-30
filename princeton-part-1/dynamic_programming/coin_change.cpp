using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
public:
  int countChange(const vector<int> &denominations, int total) {
    int count = countChangeRecursive(denominations, total, 0);
    return count;
  }

private:
  int countChangeRecursive(const vector<int> &denominations, int total, int currentIndex){
    if(total==0){
      return 1;
    }

    if(currentIndex >= denominations.size()){
      return 0;
    }

    int count = 0;
    if(denominations[currentIndex] <= total){
      count += countChangeRecursive(denominations, total - denominations[currentIndex], currentIndex);
    }

    count += countChangeRecursive(denominations, total, currentIndex + 1);

    return count;
  }
  
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}
