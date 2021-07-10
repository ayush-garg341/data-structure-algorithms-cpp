#include<iostream>
#include<queue>

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
  bool isSymmetric(Node* root) {
    
    if(root==nullptr){
      return true;
    }
    if(root->left==nullptr && root->right==nullptr){
      return true;
    }

    bool isSym = isSymmetricRecursive(root->left, root->right);

    return isSym;
    
  }

  bool isSymmetricRecursive(Node* lRoot, Node* rRoot){
    
    if(lRoot==nullptr && rRoot==nullptr){
      return true;
    }
    
    if(lRoot && rRoot && lRoot->data==rRoot->data){
      return isSymmetricRecursive(lRoot->left, rRoot->right) && isSymmetricRecursive(lRoot->right, rRoot->left);
    }

    return false;
    
  }
  
};

int main(int argc, char* argv[]){

  struct Node* root = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->left->right = new Node(4);
  root->right->left  = new Node(4);
  root->right->right = new Node(3);
  
  Solution soln;

  bool symmetric  = soln.isSymmetric(root);

  cout << symmetric << endl;

  return 0;
}
