// Assuming numbers starting from 1,2..................N

#include <iostream>
using namespace std;

class UnionFind{
private:
  int *p;
  int array_size;
  
public:
  UnionFind(int N){
    
    array_size = N;
    p = new int[N];
    for(int i=0; i<N; i++){
      *(p+i) = i;
    }
  }

  void makeUnion(int num1, int num2){
    if(*(p + num1 - 1)==*(p + num2 - 1)){
      cout << "numbers " << num1 << " and " << num2 << " are already connected." << endl;
    }
    else{
      int id_num1 = *(p + num1 -1);
      int id_num2 = *(p + num2 - 1);
      for(int j=0; j < array_size; j++){
	if(*(p+j)==id_num1){
	  *(p+j) = id_num2;
	}
      }
    }
  }


  bool connected(int num1, int num2){
    if(*(p + num1 - 1)==*(p + num2 - 1)){
      return true;
    }
    return false;
  }

  ~UnionFind(){
    cout << "deleting the heap memory in destructor" << endl;
    delete p;
  }
  
};


  int main(){
    UnionFind uf(10);
    uf.makeUnion(1, 2);
    uf.makeUnion(2, 3);
    uf.makeUnion(1, 3);
    uf.makeUnion(3, 4);
    cout << uf.connected(2,5) << endl;
    return 0;
  }
