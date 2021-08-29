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
    
    while(temp->val != p){
      prev_to_start = temp;
      temp = temp -> next;
    }

    ListNode* start = temp;

    while(temp->val!=q){
      temp = temp->next;
    }

    ListNode* end = temp;
    next_to_end = end->next;
    end->next = nullptr;

    ListNode* reverseHead = reverseList(start);

    printList(reverseHead);
    
    prev_to_start -> next = reverseHead;

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
  
  Solution soln;

  soln.printList(head);

  int p = 2, q = 6;
  
  ListNode* newHead = soln.reverseSubList(head, p, q);

  soln.printList(newHead);
  
  return 0;
}
