#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val){
    this->val = val;
    next=nullptr;
  }
};



class Solution{
private:
  ListNode* midNode(ListNode* head, ListNode* tail){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next!=tail && fast!=tail){
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  ListNode* Merge(ListNode* firstHalf, ListNode* secondHalf){
    ListNode* result = nullptr;
    if(firstHalf==nullptr){
      return secondHalf;
    }
    if(secondHalf==nullptr){
      return firstHalf;
    }

    if(firstHalf->val > secondHalf->val){
      result = secondHalf;
      result->next = Merge(firstHalf, secondHalf->next);
    }
    else{
      result = firstHalf;
      result->next = Merge(firstHalf->next, secondHalf);
    }

    return result;
    
  }
  
public:
  ListNode* MergeSortLL(ListNode* head, ListNode* tail){
    if(head==tail){
      return new ListNode(head->val);
    }

    ListNode* mid = midNode(head, tail);
    ListNode* firstHalf = MergeSortLL(head, mid);
    ListNode* secondHalf = MergeSortLL(mid->next, tail);
    ListNode* completeList = Merge(firstHalf, secondHalf);

    return completeList;
  }
};



int main(){
  struct ListNode* temp;
  struct ListNode* tail;
  struct ListNode* head = new ListNode(30);
  tail = head;
  struct ListNode* temp1 = new ListNode(50);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(10);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(60);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(20);
  temp = temp1;
  temp1->next = head;
  head = temp;


  Solution soln;
  ListNode* front  = soln.MergeSortLL(head, tail);
  while(front!=nullptr){
    cout << front->val << " ";
    front = front->next;
  }
  cout << endl;
  
  return 0;
  
}
