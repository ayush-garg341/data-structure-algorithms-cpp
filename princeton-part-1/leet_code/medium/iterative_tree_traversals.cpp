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
    return elts;
  };


  vector<int> postOrder(TreeNode* root){
    vector<int>elts;
    stack<int>reverse;
    stack<TreeNode*>order;
    order.push(root);

    while(!order.empty()){
      TreeNode* temp = order.top();
      order.pop();
      reverse.push(temp->val);
      if(temp->left!=nullptr){
	order.push(temp->left);
      }
      if(temp->right!=nullptr){
	order.push(temp->right);
      }
    }

    while(!reverse.empty()){
      elts.push_back(reverse.top());
      reverse.pop();
    }
    
    return elts;
  };
  
  
};



int main(){
  struct TreeNode* root = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->left->right = new TreeNode(5);
  root->left->left  = new TreeNode(4);
  root->right  = new TreeNode(3);

  vector<int>order;
  Solution *soln;
  //order = soln -> inOrder(root);
  //order = soln -> preOrder(root);

  order = soln -> postOrder(root);
  
  for(int i=0; i < order.size(); i++){
    cout << " " << order[i];
  }

  cout << endl;

  delete soln;
  
  return 0;
}
