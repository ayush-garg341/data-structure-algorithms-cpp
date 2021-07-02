using namespace std;

#include <iostream>
#include<vector>

class Staircase {

public:
  int CountWays(int n) {
    vector<int>memoize(n+1, 0);
    memoize[0] = 1;
    memoize[1] = 1;
    memoize[2] = 2;

    int result  = CountWaysRecursive(memoize, n);
    return result;
  }

private:
  int CountWaysRecursive(vector<int>memoize, int n){
    if(memoize[n]){
      return memoize[n];
    }

    memoize[n] = CountWaysRecursive(memoize, n-1) + CountWaysRecursive(memoize, n-2) + CountWaysRecursive(memoize, n-3);

    return memoize[n];
  }
  
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
