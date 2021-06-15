#include<iostream>
#include<vector>


class Solution {
public:

  struct mycmp{
    bool operator()(ListNode *a, ListNode *b){
      return a->val > b->val;
    }
  };
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      ListNode * head = nullptr;
      ListNode * temp = head;
      
      int k = lists.size();
      priority_queue <ListNode*, vector<ListNode *>, mycmp> pq;
      for(int i = 0; i<k; i++){
	if(lists[i]!=nullptr){
	  pq.push(lists[i]);
	}
      }

      while(!pq.empty()){
	ListNode *current = pq.top();
	pq.pop();

	ListNode *t = new ListNode(current -> val);
	
	if(head!=nullptr){
	  temp -> next = t;
	  temp = temp -> next;
	}
	else{
	  head = temp = t;
	}

	if(current->next!=nullptr){
	  pq.push(current->next);
	}
	
      }

      return head;
      
    }
  
};


// int main(){

// }
