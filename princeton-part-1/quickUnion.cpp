// Assuming numbers starting from 0,1,2..................N

#include<iostream>
using namespace std;

class QuickUnion{
private:
  int *p;

public:
  QuickUnion(int N){
    p = new int[N];
    for(int i=0; i<N; i++){
      *(p+i) = i;
    }
  }

  int root(int num1){
    while(num1 != *(p + num1)){
      num1 = *(p + num1);
    }
    return num1;
  }

  void makeuUnion(int num1 , int num2){
    if(root(num1) == root(num2)){
      cout << "Already connected " << endl;
    }
    else{
      int i = root(num1);
      int j = root(num2);
      *(p + i) = j;
    }
  }

  bool connected(int num1, int num2){
    if(root(num1) == root(num2)){
      return true;
    }
    return false;
  }

  ~QuickUnion(){
    cout << "Freeing up heap memory" << endl;
    delete p;
  }
  
};

int main(){
  QuickUnion qu(10);
  qu.makeuUnion(4, 3);
  qu.makeuUnion(3, 8);
  qu.makeuUnion(6, 5);
  qu.makeuUnion(9, 4);
  qu.makeuUnion(2, 1);
  cout << qu.connected(3, 9) << endl;
  return 0;
}
