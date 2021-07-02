using namespace std;

#include <iostream>

class Staircase {

public:
  int CountWays(int n) {
    if(n < 0){
      return 0;
    }
    if(n<=1){
      return 1;
    }
    if(n==2){
      return 2;
    }
    int result = CountWays(n-1) + CountWays(n-2) + CountWays(n-3);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
