using namespace std;

#include <iostream>
#include <unordered_set>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    ListNode* pointer1 = head;
    ListNode* pointer2 = head;

    int len = cycleLength(head);

    while(len>0){
      pointer2 = pointer2 -> next;
      len--;
    }

    while(pointer1!=pointer2){
      pointer1 = pointer1 -> next;
      pointer2 = pointer2 -> next;
    }
    
    return pointer1;
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


  // will use extra space, we can also detect the cycle using the same approach but would not be efficient in terms of space.
  static ListNode *findCycleStartWithSet(ListNode *head) {
    unordered_set<ListNode*>list_set;
    ListNode* pointer = head;
    while(true){
      if(list_set.find(pointer)==list_set.end()){
	list_set.insert(pointer);
	pointer = pointer -> next;
      }
      else{
	return pointer;
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
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStartWithSet(head)->value << endl;
  
  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStartWithSet(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStartWithSet(head)->value << endl;
  
  return 0;
}
