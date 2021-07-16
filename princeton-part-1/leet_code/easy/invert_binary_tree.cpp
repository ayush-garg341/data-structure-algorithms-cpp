#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int data){
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};


class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    
    if(root==nullptr){
      return root;
    }
    
    invertTreeRecursive(root->left, root->right, root);

    return root;
    
  }

  void invertTreeRecursive(TreeNode* lRoot, TreeNode* rRoot, TreeNode* root){

    if(lRoot==nullptr && rRoot==nullptr){
      return;
    }
    else{
      root->left = rRoot;
      root->right = lRoot;
    }
    
    if(lRoot!=nullptr)
      invertTreeRecursive(lRoot->left, lRoot->right, lRoot);
    if(rRoot!=nullptr)
      invertTreeRecursive(rRoot->left, rRoot->right, rRoot);
    
  }
  
};

int main(int argc, char* argv[]){

  struct TreeNode* root = new TreeNode(4);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(7);
  root->left->left  = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left  = new TreeNode(6);
  root->right->right = new TreeNode(9);
  
  Solution soln;

  TreeNode* new_root  = soln.invertTree(root);
  cout << new_root->data << endl;
  cout << new_root -> left -> data << endl;
  cout << new_root -> right -> data << endl;
  cout << new_root -> left -> left -> data << endl;
  cout << new_root -> left -> right -> data << endl;
  cout << new_root->right->left->data << endl;
  cout << new_root->right->right->data << endl;
  
  return 0;
}
