using namespace std;

#include <iostream>
#include<vector>

class Staircase {
public:
  int CountWays(int n) {

    int n1, n2, n3, temp;
    n1 = 1;
    n2 = 1;
    n3 = 2;

    if(n < 0){
      return 0;
    }
    
    if(n<2){
      return n1;
    }

    if(n==2){
      return n3;
    }
    
    for(int i = 3; i <= n; i++){
      temp = n1 + n2 + n3;
      n1 = n2;
      n2 = n3;
      n3 = temp;
    }
    
    return temp;
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
