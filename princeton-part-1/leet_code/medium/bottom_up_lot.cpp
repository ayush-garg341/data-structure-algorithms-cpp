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
    this->val = val;
    left=nullptr;
    right=nullptr;
  }
};


class Solution{
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    stack<vector<int>>bottomUp;
    vector<vector<int>>levelOrder;

    if(root==nullptr){
      return levelOrder;
    }

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
      vector<int>temp;
      int size = q.size();
      while(size!=0){
	struct TreeNode* root = q.front();
	temp.push_back(root->val);
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
	bottomUp.push(temp);
      }
    }

    while(!bottomUp.empty()){
      levelOrder.push_back(bottomUp.top());
      bottomUp.pop();
    }

    return levelOrder;
    
  }
};

int main(){
  struct TreeNode* root = new TreeNode(3);
  root->left        = new TreeNode(9);
  root->right       = new TreeNode(20);
  root->right->left  = new TreeNode(15);
  root->right->right = new TreeNode(7);
  
  Solution soln;

  vector<vector<int>>nums  = soln.levelOrderBottom(root);

  for(int i = 0; i < nums.size(); i++){
    cout << "[ " ;
    for(int j = 0; j < nums[i].size(); j++){
      cout <<  nums[i][j] << " ";
    }
    cout << "]";

    cout << endl;
  }

  cout << endl;
}
