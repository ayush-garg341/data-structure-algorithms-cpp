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
  vector<int> branchSums(Node* root){
    vector<int>path_sum;
    int sum = root->data;
    branchSumsRecursive(root, path_sum, sum);

    return path_sum;
  }

  void branchSumsRecursive(Node* root, vector<int>&path_sum, int sum){
    if(root->left==nullptr && root->right==nullptr){
      path_sum.push_back(sum);
      sum -= root->data;
      return;
    }

    if(root->left!=nullptr){
      sum += root->left->data;
      branchSumsRecursive(root->left, path_sum, sum);
      sum -= root->left->data;
    }
    if(root->right!=nullptr){
      sum += root->right->data;
      branchSumsRecursive(root->right, path_sum, sum);
      sum -= root->right->data;
    }

    return;
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
  root->left->right->left = new Node(10);
 
  root->right->left->left  = new Node(11); 
  root->right->left->right  = new Node(12);
  
  Solution soln;

  //soln.rootToLeafPaths(root);
  vector<int> path_sum  = soln.branchSums(root);

  for(int i = 0; i < path_sum.size(); i++){
    cout << path_sum[i] << " -> ";
  }
  cout << endl;
  return 0;
}
