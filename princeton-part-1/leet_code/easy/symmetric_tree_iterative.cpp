#include<iostream>
#include<queue>

using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int val){
    this->val = val;
  }
};


class Solution{
public:
  bool isSymmetric(Node* root){
    if(root==nullptr){
      return true;
    }
    if(root->left==nullptr && root->right==nullptr){
      return true;
    }
    
    queue<Node *>q;
      q.push(root);
      while(!q.empty()){
	vector<int> temp;
	int size = q.size();
	while(size!=0){
	  struct Node* root = q.front();
	  q.pop();
	  size--;
	  if(root->left!=nullptr){
	    q.push(root->left);
	    temp.push_back(root->left->val);
	  }
	  else{
	    temp.push_back(101);
	  }
	  if(root->right!=nullptr){
	    q.push(root->right);
	    temp.push_back(root->right->val);
	  }
	  else{
	    temp.push_back(101);
	  }
	}
	if(!temp.empty()){
	  for(int i = 0; i < temp.size() / 2; i++){
	    if(temp[i]!=temp[temp.size()-1-i]){
	      cout << "here"<<endl;
	      return false;
	    }
	  }
	}

	cout << endl;
      }

      return true;
  }
};


int main(){
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(4);
  root->right->right = new Node(3);

  // root->left->right = new Node(3);
  // root->right->right = new Node(3);

  Solution soln;
  
  if(soln.isSymmetric(root)){
    cout << "symmetric" << endl;
  }
  else{
    cout << "Asymmetric" << endl;
  }

  return 0;
  
}
