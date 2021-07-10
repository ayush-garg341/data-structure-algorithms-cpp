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
    vector<int> levelOrder(Node* root) {

      vector<int>level_order;
      
      queue<Node *>q;
      q.push(root);
      while(!q.empty()){
	struct Node* root = q.front();
	level_order.push_back(root->data);
	q.pop();
	if(root->left!=nullptr){
	  q.push(root->left);
	}
	if(root->right!=nullptr){
	  q.push(root->right);
	}
      }

      return level_order;
      
    }
};

int main(int argc, char* argv[]){

  struct Node* root = new Node(10);
  root->left        = new Node(6);
  root->right       = new Node(14);
  root->left->left  = new Node(5);
  root->left->right = new Node(8);
  root->right->left  = new Node(11);
  root->right->right = new Node(18);
  
  Solution soln;

  vector<int>nums  = soln.levelOrder(root);

  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " -> ";
  }

  cout << endl;

  return 0;
}
