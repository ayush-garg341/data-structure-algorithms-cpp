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
    //nodeDepthsRecursiveTwo(root, sum, p);
    //return p;
    sum = nodeDepthsRecursiveThree(root, 0);
    return sum;
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

  
  void nodeDepthsRecursiveTwo(Node* root, int sum, int &p){

    if(root==nullptr){
      return;
    }

    if(root->left!=nullptr || root->right!=nullptr){
      sum += 1;
    }

    if(root->left!=nullptr){
      p += sum;
      nodeDepthsRecursiveTwo(root->left, sum, p);
    }
    
    if(root->right!=nullptr){
      p += sum;
      nodeDepthsRecursiveTwo(root->right, sum, p);
    }
    
  }


  int nodeDepthsRecursiveThree(Node *root, int depth){
    if(root==nullptr){
      return 0;
    }

    return depth + nodeDepthsRecursiveThree(root->left, depth+1) + nodeDepthsRecursiveThree(root->right, depth+1);
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
