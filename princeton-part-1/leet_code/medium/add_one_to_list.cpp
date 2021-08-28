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
  ListNode* addOneToList(ListNode *head) {

    ListNode* reverseHead = reverseList(head);

    int carry = 0;
    int rem = 0;
    bool first_val = true;
    ListNode* traverseHead = reverseHead;
    ListNode* prevHead = traverseHead;
    while(traverseHead!=nullptr){
      int val = traverseHead -> val;
      if(first_val){
	rem =  ( val + carry + 1 ) % 10;
	carry = ( val + carry + 1 ) / 10;

	first_val = false;
      }
      else{
	rem =  ( val + carry ) % 10;
	carry = ( val + carry ) / 10;
      }
      traverseHead -> val = rem;

      prevHead = traverseHead;

      traverseHead = traverseHead -> next;
    }

    cout << carry << endl;
    
    if(carry != 0){
      prevHead -> next = new ListNode(carry);
    }

    head = reverseList(reverseHead);
    
    return head;
  }

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
  
  ListNode* newHead = soln.addOneToList(head);

  soln.printList(newHead);
  
  return 0;
}
