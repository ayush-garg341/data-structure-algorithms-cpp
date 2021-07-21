#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    next = nullptr;
  }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int lenA = 0, lenB = 0, lenDiff = 0;
      ListNode* tempA = headA;
      ListNode*  tempB = headB;

      ListNode* bigHead;
      ListNode* smallHead;
      
      if(tempA==tempB){
	return tempA;
      }
      if(tempA==nullptr || tempB==nullptr){
	return nullptr;
      }

      while(tempA!=nullptr){
	lenA += 1;
	tempA = tempA -> next;
      }

      while(tempB!=nullptr){
	lenB += 1;
	tempB = tempB -> next;
      }

      //cout << lenA <<  " " << lenB << endl;
      
      if(lenA >= lenB){
	lenDiff = lenA-lenB;
	bigHead = headA;
	smallHead = headB;
      }

      else{
	lenDiff = lenB - lenA;
	bigHead = headB;
	smallHead = headA;
      }

      //cout << "len diff" << lenDiff;

      while(lenDiff!=0){
	bigHead = bigHead -> next;
	lenDiff = lenDiff - 1;
      }

      while(bigHead!=nullptr){
	if(bigHead == smallHead){
	  return bigHead;
	}
	bigHead = bigHead -> next;
	smallHead = smallHead -> next;
      }

      return nullptr;
      
    }
};


int main(){
  struct ListNode* temp;
  struct ListNode* headA = new ListNode(5);
  struct ListNode* temp1 = new ListNode(4);
  temp = temp1;
  temp1->next = headA;
  headA = temp;

  temp1 = new ListNode(8);
  temp = temp1;
  temp1->next = headA;
  headA = temp;

  temp1 = new ListNode(1);
  temp = temp1;
  temp1->next = headA;
  headA = temp;

  temp1 = new ListNode(4);
  temp = temp1;
  temp1->next = headA;
  headA = temp;


  struct ListNode* headB = new ListNode(5);
  temp1 = new ListNode(4);
  temp = temp1;
  temp1->next = headB;
  headB = temp;


  temp1 = new ListNode(8);
  temp = temp1;
  temp1->next = headB;
  headB = temp;


  temp1 = new ListNode(1);
  temp = temp1;
  temp1->next = headB;
  headB = temp;

  temp1 = new ListNode(6);
  temp = temp1;
  temp1->next = headB;
  headB = temp;

  temp1 = new ListNode(5);
  temp = temp1;
  temp1->next = headB;
  headB = temp;

  // cout << "list A " << endl;
  // while(headA!=nullptr){
  //   cout << headA->val << " - >";
  //   headA = headA -> next;
  // }

  // cout << endl;

  // cout << "list B " << endl;
  // while(headB!=nullptr){
  //   cout << headB -> val << " - > ";
  //   headB = headB -> next;
  // }

  // cout << endl;
  
  Solution soln;

  ListNode* intersection = soln.getIntersectionNode(headA, headB);
  if(intersection!=nullptr){
    cout << intersection -> val << endl;
  }
  
  return 0;
}
