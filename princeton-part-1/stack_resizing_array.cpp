#include<iostream>
#include<string>

using namespace std;

class LinkedListResizeArray{
private:
  string* str;
  int keepCount;
  int N=0;

public:
  LinkedListResizeArray(){
    str = new string[1];
    keepCount = 1;
  }

  void push(string item){
    if(N==keepCount){
      // cout << "resizing array ========== " << item << endl;
      keepCount = 2*N;
      resizeArray(2*N);
    }
    str[N++] = item;
  }

  string pop(){
    if(N == keepCount/4){
      resizeArray(N/2);
      keepCount = N/2;
    }
    string item = str[--N];
    return item;
  }


  void resizeArray(int capacity){
    string* copy = new string[capacity];
    for(int i=0; i<N; i++){
      copy[i] = str[i];
    }
    str = copy;
  }

  bool isEmpty(){
    return N==0;
  }
  
};

int main(){
  LinkedListResizeArray llArray;

  cout << llArray.isEmpty() << endl;

  llArray.push("ayush");
  llArray.push("kumar");
  llArray.push("garg");
  llArray.push("full stack");
  llArray.push("engineer");

  cout << llArray.pop() << endl;

  cout << llArray.pop() << endl;

  llArray.push("sde");

  llArray.push("developer");

  cout << llArray.pop() << endl;

  cout << llArray.pop() << endl;

  cout << llArray.isEmpty() << endl;
  
  return 0;
}
