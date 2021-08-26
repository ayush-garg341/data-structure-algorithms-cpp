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

class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(true){
      fast = fast -> next;
      slow = slow -> next;
      if(fast!=nullptr && fast->next!=nullptr){
	fast = fast -> next;
      }
      if(fast->next==nullptr){
	return slow;
      }
    }
    
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next->next->next = new ListNode(8);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;
}
