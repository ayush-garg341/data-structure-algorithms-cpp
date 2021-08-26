using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycle {
 public:
  static bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(true){
      fast = fast -> next;
      slow = slow -> next;
      if(fast!=nullptr && fast->next!=nullptr){
	fast = fast->next;
      }
      else {
	return false;
      }
      if(fast==slow){
	return true;
      }
    }
    
    return false;
  }

  

  static int cycleLength(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* meet_point = head;

    while(true){
      fast = fast -> next;
      slow = slow -> next;
      if(fast!=nullptr && fast->next!=nullptr){
	fast = fast->next;
      }
      else {
	return -1;
      }
      if(fast==slow){
	meet_point = slow;
	break;
      }
    }

    int len = 0;
    while(meet_point->next!=slow){
      len += 1;
      meet_point = meet_point -> next;
    }
    return len + 1;
  }


  
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
  cout << "LinkedList has cycle of length: " << LinkedListCycle::cycleLength(head) << endl;
  
  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
  cout << "LinkedList has cycle of length: " << LinkedListCycle::cycleLength(head) << endl;

  return 0;
}
