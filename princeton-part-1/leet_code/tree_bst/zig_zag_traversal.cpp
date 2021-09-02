using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode*>q;
    q.push(root);

    int level_count = 0;

    while(!q.empty()){
      level_count += 1;
      vector<int>temp;
      int size = q.size();
      while(size!=0){
	TreeNode* front = q.front();
	q.pop();
	size--;
	temp.push_back(front->val);
        
	if(front->left!=nullptr){
	  q.push(front->left);
	}
	if(front->right!=nullptr){
	  q.push(front->right);
	}	
      }

      vector<int>reverse_temp;
      if(level_count % 2 == 0){
	while(!temp.empty()){
	  int top = temp.back();
	  reverse_temp.push_back(top);
	  temp.pop_back();
	}
	result.push_back(reverse_temp);
      }
      else{
	result.push_back(temp);
      }
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
