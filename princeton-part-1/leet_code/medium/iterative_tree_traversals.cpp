#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    this -> val = val;
    left = nullptr;
    right = nullptr;
  };
};

class Solution{
public:
  vector<int> inOrder(TreeNode *root){
    vector<int>elts;
    stack<TreeNode*>order;
    order.push(root);
    while(!order.empty() || root->left!=nullptr){
      if(root->left!=nullptr){
	root = root -> left;
	order.push(root);
      }
      else{
	TreeNode* temp = order.top();
	order.pop();
	elts.push_back(temp->val);
	if(temp->right!=nullptr){
	  root = temp -> right;
	  order.push(root);
	}
      }
    }

    return elts;
  };
};



int main(){
  struct TreeNode* root = new TreeNode(3);
  root->left        = new TreeNode(9);
  root->right       = new TreeNode(20);
  root->right->left  = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution soln;
  vector<int>inorder = soln.inOrder(root);

  for(int i=0; i < inorder.size(); i++){
    cout << " " << inorder[i];
  }

  cout << endl;
  
  return 0;
}
