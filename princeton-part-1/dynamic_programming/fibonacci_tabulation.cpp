using namespace std;

#include<iostream>
#include<vector>

class Fibonacci{
public:
  virtual int CalculateFibonacci(int n){

    if(n == 0){
      return 0;
    }
    
    int n1, n2, temp;
    n1 = 0;
    n2 = 1;
    for(int i = 2 ; i<=n; i++){
      temp = n1 + n2;
      n1 = n2;
      n2 = temp;
    }

    return temp;
    
  }
  
};


int main(){
  Fibonacci* fib = new Fibonacci();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  delete fib;

  return 0;
}
