#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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


  vector<int> preOrder(TreeNode* root){
    vector<int>elts;
    stack<TreeNode*>order;
    order.push(root);
    elts.push_back(root->val);
    while(!order.empty() || root->left!=nullptr){
      if(root->left!=nullptr){
	root = root -> left;
	order.push(root);
	elts.push_back(root->val);
      }
      else{
	TreeNode* temp = order.top();
	order.pop();
	if(temp->right!=nullptr){
	  root = temp -> right;
	  order.push(root);
	  elts.push_back(root->val);
	}
      }
    }

    // TreeNode* temp;
    // while(!order.empty()){
    //   temp = order.front();
    //   elts.push_back(temp->val);
    //   order.pop();
    // }
    
    return elts;
  };
  
};



int main(){
  struct TreeNode* root = new TreeNode(3);
  root->left        = new TreeNode(9);
  root->left->right = new TreeNode(10);
  root->right       = new TreeNode(20);
  root->right->left  = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution soln;
  //vector<int>inorder = soln.inOrder(root);

  vector<int>preorder = soln.preOrder(root);
  
  for(int i=0; i < preorder.size(); i++){
    cout << " " << preorder[i];
  }

  cout << endl;
  
  return 0;
}
