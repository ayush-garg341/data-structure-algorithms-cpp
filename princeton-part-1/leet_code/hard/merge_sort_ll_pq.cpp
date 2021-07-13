#include<iostream>
#include<vector>
#include <bits/stdc++.h>

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
public:
  ListNode* sortListPQ(ListNode* head){
    if(head==nullptr || head->next==nullptr){
      return head;
    }
    priority_queue <int>pq;
    while(head!=nullptr){
      pq.push(head->val);
      head=head->next;
    }

    ListNode* front = nullptr;
    ListNode* temp = nullptr;
    while(pq.size()!=0){
      if(front==nullptr){
	front = new ListNode(pq.top());
	pq.pop();
      }
      else{
	ListNode* temp1 = new ListNode(pq.top());
	pq.pop();
	temp = front;
	front = temp1;
	temp1->next = temp;
      }
    }
    
    return front;
  }
};


int main(){
  struct ListNode* temp;
  struct ListNode* head = new ListNode(30);
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
  ListNode* front  = soln.sortListPQ(head);
  while(front!=nullptr){
    cout << front->val << " ";
    front = front->next;
  }
  cout << endl;
  
  return 0;
}
