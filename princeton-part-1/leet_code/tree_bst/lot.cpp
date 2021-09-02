using namespace std;

#include <iostream>
#include <queue>
#include<vector>

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    
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
      result.push_back(level_val);
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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
