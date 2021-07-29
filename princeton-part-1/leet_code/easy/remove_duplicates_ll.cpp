#include<iostream>
#include<unordered_map>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    next = nullptr;
  };
};


class Solution {
public:
  ListNode* removeDuplicates(ListNode* head){
    unordered_map<int, int>umap;
    if(head==NULL){
      return head;
    }
    ListNode* newNode = head;
    ListNode* temp = newNode;
    umap[head->val]++;
    head = head -> next;
    while(head!=NULL){
      if(umap.find(head->val) != umap.end()){ 
	head = head -> next;
      }
      else{
	newNode -> next = head;
	umap[head->val]++;
	head = head -> next;
	newNode = newNode->next;
      }
    }
    newNode->next = head;
    return temp;
  }
};



int main(){

  struct ListNode* start = new ListNode(1);
  start->next = new ListNode(2);
  start->next->next = new ListNode(3);
  start->next->next->next = new ListNode(4);
  start->next->next->next->next = new ListNode(4);
  start->next->next->next->next->next = new ListNode(3);
  start->next->next->next->next->next->next = new ListNode(2);
  start->next->next->next->next->next->next->next = new ListNode(1);
  
  // 10 12 11 11 12 11 10
  
  Solution *soln;

  ListNode* head = soln->removeDuplicates(start);

  while(head!=nullptr){
    cout << head->val << " ";
    head = head -> next;
  }

  cout << endl;
  
  return 0;
}
