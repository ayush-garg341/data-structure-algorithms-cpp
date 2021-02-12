// Assuming numbers starting from 0,1,2..................N

#include<iostream>
using namespace std;

class WeightedQuickUnion{
private:
  int *p;
  int *size_tree;
  int array_size;

public:
  WeightedQuickUnion(int N){
    array_size = N;
    p = new int[N];
    size_tree = new int[N];
    for(int i=0; i<N; i++){
      *(p+i) = i;
      *(size_tree + i) = 1;
    }
  }

  int root(int num1){
    while(num1 != *(p + num1)){
      *(p+num1) = *(p+ *(p+num1));
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
      if(*(size_tree + i) > *(size_tree + j)){
	*(p + j) = i;
	*(size_tree + i) += *(size_tree + j); 
      }
      else{
	*(p + i) = j;
	*(size_tree + j) += *(size_tree + i); 
      }
    }
  }

  bool connected(int num1, int num2){
    if(root(num1) == root(num2)){
      return true;
    }
    return false;
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

  void getRootNodeSubTreeSize(){
    cout << "root node sizes" << endl;
    for(int i=0; i< array_size ; i++){
      cout << i << " ";
    }

    cout << "\n";
    
    for(int i=0; i< array_size ; i++){
      cout << *(size_tree+i) << " ";
    }
  }
  
  ~WeightedQuickUnion(){
    cout << "Freeing up heap memory" << endl;
    delete p;
  }
  
};

int main(){
  WeightedQuickUnion wqu(10);
  wqu.makeuUnion(4, 3);
  wqu.makeuUnion(3, 8);
  wqu.makeuUnion(6, 5);
  wqu.makeuUnion(9, 4);
  wqu.makeuUnion(2, 1);
  wqu.makeuUnion(6, 8);
  cout << "before compressing path " << endl;
  wqu.getConnectedComponents();
  cout << "\n";
  cout << wqu.connected(3, 9) << endl;
  cout << wqu.connected(6, 9) << endl;
  cout << "after compressing path " << endl;
  wqu.getConnectedComponents();
  cout << "\n";
  wqu.getRootNodeSubTreeSize();
  cout << "\n";
  return 0;
}
