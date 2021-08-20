#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
  int getSingleDigitSum(int N){
    int sum = 0;
    int prod = (int)pow(2, N);
    cout << "prod out " << prod << endl;
    while(true){
      sum = 0;
      while(prod != 0){
	int rem = prod % 10;
	sum += rem;
	prod /= 10;
      }

      cout << "sum " << sum << endl;

      prod = sum;

      if(prod == 10){
	return 1;
      }
      else if(prod < 10){
	return prod;
      }
    }
    
    return sum;
  }
};


int main(){
  Solution *soln = new Solution();
  int sum = soln -> getSingleDigitSum(22);
  cout << sum << endl;
  return 0;
}
