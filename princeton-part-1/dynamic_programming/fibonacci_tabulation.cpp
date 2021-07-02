using namespace std;

#include<iostream>
#include<vector>

class Fibonacci{
public:
  virtual int CalculateFibonacci(int n){

    if(n == 0){
      return 0;
    }
    
    vector<int>dp(3);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){

      dp[i] = dp[i-1] + dp[i-2];
      
    }

    return dp[n];
    
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
