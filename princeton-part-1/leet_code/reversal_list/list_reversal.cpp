#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    next=nullptr;;
  }
};


class Solution{
public:
  ListNode* reverseList(ListNode* head){
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;

    while(currentNode!=nullptr){
      ListNode* temp = currentNode;
      currentNode = currentNode->next;
      temp -> next = prevNode;
      prevNode = temp;
    }

    currentNode = prevNode;

    head = currentNode;

    return head;
  }


  void printList(ListNode* head){
    while(head!=nullptr){
      cout << head->val << " ";
      head = head -> next;
    }

    cout << endl;
  }
  
  
};



int main(){
  struct ListNode* temp;
  struct ListNode* head = new ListNode(9);
  struct ListNode* temp1 = new ListNode(9);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(9);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(7);
  temp = temp1;
  temp1->next = head;
  head = temp;

  Solution soln;

  soln.printList(head);
  
  ListNode* newHead = soln.reverseList(head);

  soln.printList(newHead);
  
  return 0;
}
