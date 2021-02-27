#include<iostream>
#include <string>

using namespace std;

class Node{
public:
  string item;
  Node* next;
};

class LinkedListStack{
private:		   
  Node* first = NULL;
  
public:
  bool isEmpty(){
    return first == NULL;
  }

  void push(string str){
    Node* tempNode = new Node();
    tempNode->next=first;
    tempNode->item=str;
    first = tempNode;
  }
  
  string pop(){
    string item = first->item;
    first = first->next;
    return item;
  }
    
};


int main(){
  LinkedListStack llStack;

  cout << llStack.isEmpty() << endl;
  
  llStack.push("ayush");
  llStack.push("garg");
  llStack.push("full stack developer");


  cout << llStack.isEmpty() << endl;

  cout << llStack.pop() << endl;

  cout << llStack.isEmpty() << endl;

  cout << llStack.pop() << endl;

  cout << llStack.isEmpty() << endl;

  cout << llStack.pop() << endl;

  cout << llStack.isEmpty() << endl;

  
  return 0;
}
