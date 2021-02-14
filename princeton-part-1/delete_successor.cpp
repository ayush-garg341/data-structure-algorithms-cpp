#include<iostream>
using namespace std;

class SuccessorDelete{
private:
  int array_size;
  int *p;
  int *actualList;
  int *size_tree;

public:
  SuccessorDelete(int N){
    array_size = N;
    p = new int(N);
    actualList = new int(N);
    size_tree = new int(N);
    for(int i=0; i<N; i++){
      *(p+i) = i;
      *(actualList + i) = i;
      *(size_tree + i) = 1;
    }
  }

  int root(int num1){
    while(num1 != *(p + num1)){
      num1 = *(p + num1);
    }
    return num1;
  }

  void makeuUnion(int num1, int num2){
    int i = root(num1);
    int j = root(num2);
    if(*(size_tree + i) > *(size_tree + j)){
      *(p + j) = i;
      *(size_tree + i) += *(size_tree + j);
      *(actualList + i) = j; 
    }
    else{
      *(p + i) = j;
      *(size_tree + j) += *(size_tree + i); 
    }
  }

  void remove(int num1){
    makeuUnion(num1, num1+1);
  }

  int findSuccessor(int num){
    return *(actualList+ root(num+1));
  }

  bool existNum(int num){
    return num == *(actualList + root(num));
  }

  void getConnectedComponents(){
    for(int i=0; i< array_size ; i++){
      cout << i << " ";
    }

    cout << "\n";
    
    for(int i=0; i< array_size ; i++){
      cout << *(p+i) << " ";
    }
  }
};


int main(){
  SuccessorDelete sd(10);
  sd.remove(4);
  sd.remove(6);
  sd.remove(5);
  sd.remove(7);
  
  cout << sd.findSuccessor(3) << endl;
  cout << sd.findSuccessor(8) << endl;
  cout << sd.existNum(4) << endl;
  cout << sd.existNum(5) << endl;
  cout << sd.existNum(6) << endl;
  cout << sd.existNum(7) << endl;
  cout << sd.existNum(8) << endl;
  cout << sd.existNum(9) << endl;
  sd.getConnectedComponents();
  cout << endl;
  return 0;
  
}
