#include<iostream>
#include<vector>
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


class Solution{
public:
  int nodeDepths(Node* root){
    int sum = 0;
    int p = 0;
    nodeDepthsRecursive(root, sum, p);
    return p;
  }

  void nodeDepthsRecursive(Node* root, int sum, int &p){
    if(root==nullptr){
      return ;
    }

    if(root->left!=nullptr){
      sum+=1;
      p += sum;
      nodeDepthsRecursive(root->left, sum, p);
      sum -= 1;
    }
    if(root->right!=nullptr){
      sum += 1;
      p += sum;
      nodeDepthsRecursive(root->right, sum, p);
    }

  }

  
  
};

int main(){
  struct Node* root = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(3);
  root->left->left  = new Node(4);
  root->left->right = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  root->left->left->left  = new Node(8);
  root->left->left->right  = new Node(9);
  // root->left->right->left = new Node(10);
 
  // root->right->left->left  = new Node(11); 
  // root->right->left->right  = new Node(12);
  
  Solution soln;

  //soln.rootToLeafPaths(root);
  int sum  = soln.nodeDepths(root);

  cout << sum << endl;
  
  return 0;
}
