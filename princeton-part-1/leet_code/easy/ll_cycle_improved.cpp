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
  bool hasCycle(ListNode *head) {
    
    if(head==nullptr || head->next==nullptr){
      return false;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next!=nullptr){
      fast = fast -> next;
      slow = slow -> next;
      if(fast->next!=nullptr){
	if(fast->next==slow){
	  return true;
	}
	else{
	  fast = fast->next;
	}
      }
      else{
	return false;
      }
    }

    return false;
  }
};



int main(){
  struct ListNode* temp;
  struct ListNode* head = new ListNode(-4);
  struct ListNode* temp1 = new ListNode(0);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(2);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(3);
  temp = temp1;
  temp1->next = head;
  head = temp;

  Solution soln;
  
  bool exist = soln.hasCycle(head);

  cout << exist << endl;

  return 0;
}
