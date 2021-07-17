#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};


class Solution {
public:
  bool isBalanced(Node* root) {

    if(root==nullptr || root->left==nullptr || root->right==nullptr){
      return true;
    }
    
    bool balanced = isBalancedRecursive(root);

    return balanced;
  }

  bool isBalancedRecursive(Node* root){

    if(root==nullptr){
      return 1;
    }

    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);

    int l = isBalancedRecursive(root->left);
    int r = isBalancedRecursive(root->right);
    
    if(abs(leftSubtreeHeight - rightSubtreeHeight)<=1 && l && r){
      return 1;
    }

    return 0;
    
  }

  int height(Node* root){
    if(root==nullptr){
      return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + max(leftH, rightH);
  }
  
};

int main(int argc, char* argv[]){

  struct Node* root = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->left->right = new Node(3);
  //root->right->left  = new Node(15);
  //root->right->right = new Node(7);

  root->left->left->left = new Node(4);
  root->left->left->right = new Node(4);
  
  
  Solution soln;

  bool balanced  = soln.isBalanced(root);

  cout << balanced << endl;

  return 0;
}
