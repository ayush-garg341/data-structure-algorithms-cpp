#include<iostream>
#include<vector>


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *temp = NULL;
      int n = lists.size();

      if(n==1){
	return lists[0];
      }
      
      
      for(int i = 1; i < n; i++){
	if(temp==NULL){
	  ListNode *list1 = lists[i-1];
	  ListNode *list2 = lists[i];
	  ListNode *merged_list_head = mergeTwoLists(list1, list2);
	  temp = merged_list_head;
	}
	else{
	  ListNode *list1 = temp;
	  ListNode *list2 = lists[i];
	  ListNode *merged_list_head = mergeTwoLists(list1, list2);
	  temp = merged_list_head;
	}
      }

      return temp;
      
    }


  ListNode* mergeTwoLists(ListNode *list1, ListNode* list2){
    ListNode *merged_list = NULL;
    ListNode *prev_merged = NULL;
    while(list1!=NULL && list2 != NULL){
      ListNode *temp = new ListNode;
      if(list1->val < list2->val){
	temp -> val = list1->val;
	temp -> next = NULL;
	list1 = list1->next;
      }
      else{
	temp -> val = list2->val;
	temp -> next = NULL;
	list2 = list2->next;	
      }

      if(merged_list==NULL && prev_merged==NULL){
	merged_list = temp;
	prev_merged = temp;
      }
      else{
	prev_merged->next = temp;
	prev_merged = temp;
      }
    }

    while(list1 != NULL){
      ListNode *temp = new ListNode;
      temp -> val = list1->val;
      temp -> next = NULL;
      list1 = list1->next;
      if(merged_list==NULL && prev_merged==NULL){
	merged_list = temp;
	prev_merged = temp;
      }
      else{
	prev_merged->next = temp;
	prev_merged = temp;
      }
    }

    while(list2 != NULL){
      ListNode *temp = new ListNode;
      temp -> val = list2->val;
      temp -> next = NULL;
      list2 = list2->next;
      if(merged_list==NULL && prev_merged==NULL){
	merged_list = temp;
	prev_merged = temp;
      }
      else{
	prev_merged->next = temp;
	prev_merged = temp;
      }
    }

    return merged_list;
  }
  
};


// int main(){

// }
