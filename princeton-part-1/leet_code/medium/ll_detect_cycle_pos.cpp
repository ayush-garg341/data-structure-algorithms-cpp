#include<iostream>
#include<unordered_map>
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
  ListNode* detectCycle(ListNode *head) {

    unordered_map<ListNode*, int>umap;
    
    if(head==nullptr || head->next==nullptr){
      return nullptr;
    }

    while(head!=nullptr){
      if(umap.find(head)==umap.end()){
	umap[head]++;
	head = head->next;
	
      }
      else{
	return head;
      }
    }

    return nullptr;
    
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
