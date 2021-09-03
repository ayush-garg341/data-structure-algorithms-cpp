using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
   // TODO: Write your code here
    queue<TreeNode*>q;
    q.push(root);
    bool find = false;
    while(!q.empty()){
      int size = q.size();
      while(size!=0){
	TreeNode* front = q.front();
	int val = front->val;

	if(find == true){
	  return front;
	}
	
	if(val == key){
	  find = true;
	}
	q.pop();
	size--;

	if(front->left!=nullptr){
	  q.push(front->left);
	}

	if(front->right!=nullptr){
	  q.push(front->right);
	}
      }
    }
    
    return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }

  return 0;
}
