#include<stdio.h>
#include<bits/stdc++.h>


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *temp = head;
      int size = 0;
      while(temp!=NULL){
	temp = temp -> next;
	size++;
      }

      int index_front = size - n + 1;

      if(index_front<=0 || head==NULL){
	return NULL;
      }
      
      if(index_front==1){
	head = head -> next;
	return head;
      }
      
      int count = 0;
      ListNode *temp2 = head;
      while(temp2!=NULL){
	count++;
	if(count < index_front-1){
	  temp2 = temp2 -> next;
	}
	else{
	  ListNode *remove = temp2->next;
	  temp2->next = remove->next;
	  delete remove;
	  break;
	}
      }

      return head;
      
    }
};

// int main(){
//   Solution soln;
//   soln.removeNthFromEnd();
// }
