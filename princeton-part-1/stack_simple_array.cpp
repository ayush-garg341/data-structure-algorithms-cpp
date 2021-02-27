#include<iostream>
#include<string>

using namespace std;

class LinkedListArray{
private:
  string* str;
  int N=0;

public:
  LinkedListArray(int capacity){
    str = new string[capacity];
  }

  void push(string item){
    str[N++] = item;
  }

  string pop(){
    string item = str[--N];
    //str[N] = NULL;
    return item;
  }

  bool isEmpty(){
    return N==0;
  }
  
};

int main(){
  LinkedListArray llArray(5);

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
