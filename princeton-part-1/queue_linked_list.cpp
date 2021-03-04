#include<iostream>
#include<string>

using namespace std;

class Node{
public:
  string item;
  Node* next;
};


class QueueLinkedList{
private:
  Node* head = NULL;
  Node* last = NULL;
  
public:

  bool isEmpty(){
    return head==NULL;
  }


  void enqueue(string item){
    cout << "========== enqueuing ======== " << item << endl;
    Node* newLast = new Node();
    newLast->item=item;
    newLast->next = NULL;
    if(head==NULL){
      head = newLast;
    }

    if(last==NULL){
      last = newLast;
    }
    else{
      last->next=newLast;
      last = newLast;
    }
    
  }


  string dequeue(){
    cout << "====== dequeuing ======== " << endl;
    if(head==NULL){
      return "empty queue";
    }
    Node* tempNode = head;
    head = tempNode->next;
    return tempNode->item;
  }
  

  void printRemaining(){
    cout << "===================== printing elements =============== " << endl;
    Node* tempNode = head;
    if(tempNode!=NULL){
      while(tempNode!=NULL){
	cout << tempNode->item << endl;
	tempNode = tempNode->next;
      }
    }
    else{
      cout << "empty queue" << endl;
    }
    
  }
  
};


int main(){
  QueueLinkedList qll;
  qll.enqueue("hey");
  qll.enqueue("this");
  qll.enqueue("is");
  qll.enqueue("ayush");
  qll.enqueue("garg");

  qll.printRemaining();
  
  cout << qll.dequeue() << endl;
  cout << qll.dequeue() << endl;

  qll.printRemaining();
  
  return 0;
}
