using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    int result = this->countChangeRecursive(denominations, total, 0);
    return (result == numeric_limits<int>::max() ? -1 : result);
  }

private:
  int countChangeRecursive(const vector<int> &denominations, int total, int currentIndex) {
    // base check
    if (total == 0) {
      return 0;
    }

    if (denominations.empty() || currentIndex >= denominations.size()) {
      return numeric_limits<int>::max();
    }

    // recursive call after selecting the coin at the currentIndex
    // if the coin at currentIndex exceeds the total, we shouldn't process this
    int count1 = numeric_limits<int>::max();
    if (denominations[currentIndex] <= total) {
      int res =
	countChangeRecursive(denominations, total - denominations[currentIndex], currentIndex);
      if (res != numeric_limits<int>::max()) {
        count1 = res + 1;
      }
    }
    
    // recursive call after excluding the coin at the currentIndex
    int count2 = countChangeRecursive(denominations, total, currentIndex + 1);
    return min(count1, count2);
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1};
  cout << cc->countChange(denominations, 5) << endl;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
  return 0;
}
