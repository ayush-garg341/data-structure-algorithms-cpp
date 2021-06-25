#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    ListNode *temp = head;
    ListNode *last;
    int length = 0;
    while(temp!=NULL){
      length += 1;
      last = temp;
      temp = temp->next;
    }

    if(length==0 || length ==1){
      return head;
    }

    int rotateFactor = k % length;
    int fromBegin = length - rotateFactor;
    int count = 0;

    temp = head;
    while(count!=fromBegin-1){
      temp = temp -> next;
      count++;
    }

    last -> next = head;
    head = temp -> next;
    temp -> next = NULL;
    
    return head;
  }

  
};


int main(){
  
  return 0;
}
