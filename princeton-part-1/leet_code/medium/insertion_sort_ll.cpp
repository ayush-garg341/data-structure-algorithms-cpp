#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val=val;
    next=nullptr;
  }
};

class Solution{
public:
  ListNode* insertionSortList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
      return head;
    }

    ListNode* sortedList = nullptr;
    
    while(head!=nullptr){
      if(sortedList==nullptr){
	sortedList = new ListNode(head->val);
	head = head->next;
      }
      else{
        if(head->val <= sortedList->val){
	  ListNode* temp1;
	  ListNode* temp = new ListNode(head->val);
	  temp1 = temp;
	  temp->next = sortedList;
	  sortedList = temp1;
	}
	else{
	  ListNode* tempHead = sortedList;
	  ListNode* prevNode = nullptr;
	  ListNode* temp1;
	  while(tempHead!=nullptr && head->val > tempHead->val){
	    prevNode = tempHead;
	    tempHead = tempHead->next;
	  }
	  ListNode* temp = new ListNode(head->val);
	  temp1 = temp;
	  temp->next = prevNode->next;
	  prevNode->next = temp1;
	}
	head = head->next;
      }
    }

    return sortedList;
    
  }
};

int main(int argc, char *arv[]){
  struct ListNode* temp;
  struct ListNode* head = new ListNode(0);
  struct ListNode* temp1 = new ListNode(4);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(3);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(5);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(-1);
  temp = temp1;
  temp1->next = head;
  head = temp;
  
  Solution soln;
  
  ListNode* front = soln.insertionSortList(head);

  while(front!=nullptr){
    cout << front->val << " ";
    front = front->next;
  }

  cout << endl;

  return 0;
}
