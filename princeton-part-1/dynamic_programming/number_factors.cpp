using namespace std;

#include <iostream>
#include<vector>

class ExpressNumber {

public:
  int CountWays(int n) {
    vector<int>dp(n+1, 0);
    if(n < 0){
      return 0;
    }
    if(n <= 2){
      return 1;
    }
    if(n == 3){
      return 2;
    }
    int result = CountWays(n-1) + CountWays(n-3) + CountWays(n-4);
    return result;
  }
  
};

int main(int argc, char *argv[]) {
  ExpressNumber *en = new ExpressNumber();
  cout << en->CountWays(4) << endl;
  cout << en->CountWays(5) << endl;
  cout << en->CountWays(6) << endl;

  delete en;
}
