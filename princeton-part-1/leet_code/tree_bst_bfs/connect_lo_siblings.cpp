using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // level order traversal using 'next' pointer
  virtual void printLevelOrder() {
    TreeNode *nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode *current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << endl;
    }
  }
};

class ConnectLevelOrderSiblings {
 public:
  static void connect(TreeNode *root) {
    // TODO: Write your code here

    queue<TreeNode*>q;
    q.push(root); 
    while(!q.empty()){
      TreeNode* prevNode = nullptr;
      TreeNode* currentNode = nullptr;
      int size = q.size();
      while(size!=0){
	TreeNode* front = q.front();
	currentNode = front;
	if(prevNode==nullptr){
	  prevNode = front;
	}
	else{
	  prevNode -> next = currentNode;
	  prevNode = currentNode;
	}
	q.pop();
	size-- ;
	if(front->left!=nullptr){
	  q.push(front->left);
	}
	if(front->right!=nullptr){
	  q.push(front->right);
	}
      }
      currentNode -> next = nullptr;
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectLevelOrderSiblings::connect(root);
  cout << "Level order traversal using 'next' pointer: " << endl;
  root->printLevelOrder();
}
