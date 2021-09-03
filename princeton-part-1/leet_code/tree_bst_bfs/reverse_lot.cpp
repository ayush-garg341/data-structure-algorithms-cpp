using namespace std;

#include<deque>
#include <stack>
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

class ReverseLevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>>result;
    stack<vector<int>>reverse_level;

    // deque<vector<int>>result = deque<vector<int>>();   no need of stack data structure, if we use dequeue and push_front the current level, rather than push_back

    if(root==nullptr){
      return {{}};
    }

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
      int size = q.size();

      vector<int>level_val;
      
      while(size != 0){
	TreeNode* top = q.front();
	q.pop();
	size--;
	level_val.push_back(top->val);

	if(top->left!=nullptr){
	  q.push(top->left);
	}

	if(top -> right != nullptr){
	  q.push(top->right);
	}
	
      }
      reverse_level.push(level_val);

      // append the current level at the beginning
      // result.push_front(level_val);
      
    }

    while(!reverse_level.empty()){
      vector<int>level = reverse_level.top();
      result.push_back(level);
      reverse_level.pop();
    }
    
    return result;
  }
};
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}
