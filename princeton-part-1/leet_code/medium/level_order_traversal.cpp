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
  vector<vector<int>> levelOrder(Node* root) {

    vector<vector<int>>level_order;
    
    if(root==nullptr){
      return level_order;
    }
    
    queue<Node *>q;
      q.push(root);
      while(!q.empty()){
	vector<int> temp;
	int size = q.size();
	while(size!=0){
	  struct Node* root = q.front();
	  temp.push_back(root->data);
	  q.pop();
	  size--;
	  if(root->left!=nullptr){
	    q.push(root->left);
	  }
	  if(root->right!=nullptr){
	    q.push(root->right);
	  }
	}
	if(!temp.empty()){
	  level_order.push_back(temp);
	}
      }
      
      return level_order;
      
    }
};

int main(int argc, char* argv[]){

  struct Node* root = new Node(3);
  root->left        = new Node(9);
  root->right       = new Node(20);
  root->right->left  = new Node(15);
  root->right->right = new Node(7);
  
  Solution soln;

  vector<vector<int>>nums  = soln.levelOrder(root);

  for(int i = 0; i < nums.size(); i++){
    cout << "[ " ;
    for(int j = 0; j < nums[i].size(); j++){
      cout <<  nums[i][j] << " ";
    }
    cout << "]";

    cout << endl;
  }

  cout << endl;

  return 0;
}
