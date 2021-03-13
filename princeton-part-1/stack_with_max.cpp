#include<iostream>
using namespace std;

class Node{
public:
  int item;
  Node* next;
};


class StackMax{
public:
  int item;
  StackMax* next;
};


class StackWithMax{
private:		   
  Node* first = NULL;
  StackMax* firstStackMax = NULL;
  int maxElement = 0;
  
public:
  bool isEmpty(){
    return first == NULL;
  }
  
  void push(int element){
    Node* tempNode = new Node();
    tempNode->next=first;
    tempNode->item=element;
    first = tempNode;
    
    StackMax* tempMaxNode = new StackMax();

    if(firstStackMax == NULL){
      maxElement = element;
    }
    else if(element > maxElement){
      maxElement = element;
    }

    tempMaxNode->next=firstStackMax;
    tempMaxNode->item=maxElement;
    firstStackMax = tempMaxNode;
  }
  
  int pop(){
    int item = first->item;
    first = first->next;
    firstStackMax = firstStackMax -> next;
    return item;
  }

  int findMaxElement(){
    return firstStackMax->item;
  }
  
};


int main(){

  StackWithMax swm;
  swm.push(6);
  swm.push(9);
  swm.push(4);
  swm.push(15);
  swm.push(23);
  swm.push(11);

  cout << "max element so far ========  " << swm.findMaxElement() << endl;

  cout << "popping elements ========= " << swm.pop() << endl;
  cout << "popping elements ========= " << swm.pop() << endl;

  cout << "max element so far ========  " << swm.findMaxElement() << endl;
  
  cout << "popping elements ========= " << swm.pop() << endl;

  cout << "max element so far ========  " << swm.findMaxElement() << endl;
  
  return 0;
}
