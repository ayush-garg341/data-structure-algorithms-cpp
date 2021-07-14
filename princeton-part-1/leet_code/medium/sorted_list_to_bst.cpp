#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val){
    this->val = val;
    next=nullptr;
  }
};


struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    this->val = val;
    left=nullptr;
    right=nullptr;
  }
};



class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    ListNode* tail = head;
    TreeNode* rootNode = nullptr;
    if(tail==nullptr){
      return nullptr;
    }

    rootNode = sortedListToBSTRecursive(head, nullptr);

    return rootNode;
    
  }

  TreeNode* sortedListToBSTRecursive(ListNode* head, ListNode* tail){
    if(head==tail){
      return nullptr;
    }
    if(head->next==tail){
      return new TreeNode(head->val);
    }

    ListNode* mid = midNode(head, tail);

    TreeNode* root = new TreeNode(mid->val);
    root -> left = sortedListToBSTRecursive(head, mid);
    root -> right = sortedListToBSTRecursive(mid->next, tail);
    
    return root;

    
  }
  
  ListNode* midNode(ListNode* head, ListNode* tail){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next!=tail){
      fast = fast->next;
      slow = slow->next;
      if(fast->next!=tail){ // this condition ensures that we are never taking mid into account, since mid will be our root node i.e. ( head - mid-1 ) & ( mid+1 - tail)
	fast = fast->next;
      }
    }
    return slow;
  }
};


int main(){
  struct ListNode* temp;
  struct ListNode* head = new ListNode(9);
  struct ListNode* temp1 = new ListNode(5);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(0);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(-3);
  temp = temp1;
  temp1->next = head;
  head = temp;

  temp1 = new ListNode(-10);
  temp = temp1;
  temp1->next = head;
  head = temp;

  // while(head!=nullptr){
  //   cout << head->val << " ";
  //   head = head->next;
  // }

  // cout << endl;

  

  Solution soln;
  TreeNode* root  = soln.sortedListToBST(head);

  cout << root->val << endl;
  cout << root->right->val << endl;
  cout << root->right->left->val << endl;
  
  return 0;
  
}
