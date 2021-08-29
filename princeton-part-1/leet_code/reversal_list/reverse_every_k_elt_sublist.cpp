#include<iostream>
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
  ListNode* reverseSubList(ListNode* head, int p, int q){
    ListNode* temp = head;
    ListNode* next_to_end = head;
    ListNode* prev_to_start = head;

    int count_p = 1;
    int count_q = 1;
    
    while(count_p != p){
      count_p++;
      prev_to_start = temp;
      temp = temp -> next;
    }

    ListNode* start = temp;

    temp = head;
    
    
    while(count_q != q){
      count_q++;
      temp = temp->next;
    }

    ListNode* end = temp;
    next_to_end = end->next;
    end->next = nullptr;

    ListNode* reverseHead = reverseList(start);

    printList(reverseHead);

    if(p == 1){
      prev_to_start = reverseHead;
      head = prev_to_start;
    }
    else{
      prev_to_start -> next = reverseHead;
    }
    
    while(prev_to_start -> next!=nullptr){
      prev_to_start = prev_to_start -> next;
    }
    prev_to_start->next = next_to_end;

    return head;
  }


  ListNode* reverseList(ListNode* head){
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;

    while(currentNode!=nullptr){
      ListNode* temp = currentNode;
      currentNode = currentNode->next;
      temp -> next = prevNode;
      prevNode = temp;
    }

    currentNode = prevNode;

    head = currentNode;

    return head;
  }


  void printList(ListNode* head){
    while(head!=nullptr){
      cout << head->val << " ";
      head = head -> next;
    }
    cout << endl;
  }
  
  
};



int main(){
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  //head->next->next->next->next->next->next->next->next = new ListNode(9);
  
  int k = 3;
  
  Solution soln;

  soln.printList(head);

  ListNode* temp = head;
  int len = 0;
  while(temp != nullptr){
    len++;
    temp = temp -> next;
  }

  int count = 0;
  int start = 1;
  int end = 0;
  while(count < len){
    count++;
    if(count % k == 0){
      end = count;
      head = soln.reverseSubList(head, start, end);
      start = count + 1;
    }
  }

  cout << count << endl;

  if(count % k !=0 ){
    head = soln.reverseSubList(head, start, count);
  }
  
  soln.printList(head);
  
  return 0;
}
