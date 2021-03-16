#include<iostream>
#include<string>

using namespace std;

class Stack1{
public:
  string item;
  Stack1* next;
};

class QueueTwoStacks{
private:		   
  Stack1* first = NULL;
  string deqElt;

public:

  bool isEmpty(){
    return first == NULL;
  };


  void enqueue(string item){
    Stack1* tempNode = new Stack1();
    tempNode->next=first;
    tempNode->item=item;
    first = tempNode;
  };


  string dequeue(){
    string res = first->item;
    first = first->next;
    if(isEmpty()){
      deqElt = res;
      return res;
    };
    dequeue();
    enqueue(res);

    return deqElt;
  };


  void printAll(){
    Stack1* tempNode = first;
    while(tempNode!=NULL){
      cout << tempNode->item << endl;
      tempNode = tempNode->next;
    }
  }
  
};


int main(){
  QueueTwoStacks qts;

  cout << qts.isEmpty() << endl;
  
  qts.enqueue("ayush");
  qts.enqueue("garg");
  qts.enqueue("software");
  qts.enqueue("engineer");
  qts.enqueue("full stack");

  
  cout << "=========================" << endl;
  qts.printAll();
  
  cout << "=========================" << endl;
  
  cout << qts.dequeue() << endl;

  cout << "=========================" << endl;
  
  qts.printAll();

  cout << "=========================" << endl;
  
  cout << qts.dequeue() << endl;

  cout << "=========================" << endl;

  qts.printAll();
  
  return 0;
}
