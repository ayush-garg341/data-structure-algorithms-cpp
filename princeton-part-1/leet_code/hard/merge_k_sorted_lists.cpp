#include<iostream>
#include<vector>


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *temp = NULL;
      int n = lists.size();

      if(n==0){
	return {};
      }
      
      if(n==1){
	return lists[0];
      }

      temp = lists[0];
      
      for(int i = 1; i < n; i++){
	temp = mergeTwoLists(temp, lists[i]);
      }

      return temp;
      
    }


  ListNode* mergeTwoLists(ListNode *list1, ListNode* list2){
    ListNode *temp = new ListNode;
    ListNode *ans = temp;
    while(list1!=NULL && list2 != NULL){
      if(list1->val < list2->val){
	temp -> next = list1;
	list1 = list1->next;
      }
      else{
	temp -> next = list2;
	list2 = list2->next;	
      }
      temp = temp->next;
    }

    temp -> next = (list1==NULL) ? list2: list1;

    return ans->next;
  }
  
};


// int main(){

// }
