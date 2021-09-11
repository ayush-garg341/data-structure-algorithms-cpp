#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};



class TreeTraversal {
 public:
  vector<int> preOrder(TreeNode* root){
    vector<int>preOrderTraverse;

    preOrderRecursive(root, preOrderTraverse);
    
    return preOrderTraverse;
  }


  void preOrderRecursive(TreeNode* root, vector<int>&preOrderTraverse){

    if(root==nullptr){
      return;
    }

    preOrderTraverse.push_back(root->val);

    preOrderRecursive(root->left, preOrderTraverse);
    preOrderRecursive(root->right, preOrderTraverse);
    
  }
  

  vector<int> preOrderIterative(TreeNode* root){
    vector<int>preOrderTraverse;

    stack<TreeNode*>st;
    while(!st.empty() || root!=nullptr){
      if(root!=nullptr){
	preOrderTraverse.push_back(root->val);
	st.push(root);
	root = root -> left;
      }
      else{
	root = st.top();
	st.pop();
	root = root -> right;
      }
    }
    return preOrderTraverse; 
  }


  vector<int>inOrder(TreeNode* root){
    vector<int>inOrderTraverse;
    inOrderRecursive(root, inOrderTraverse);
    return inOrderTraverse;
  }

  void inOrderRecursive(TreeNode* root, vector<int>&inOrderTraverse){
    if(root == nullptr){
      return;
    }

    inOrderRecursive(root->left, inOrderTraverse);
    inOrderTraverse.push_back(root->val);
    inOrderRecursive(root->right, inOrderTraverse);
    
  }


  vector<int> inOrderIterative(TreeNode *root){

    vector<int>inOrderTraverse;

    stack<TreeNode*>st;

    while(!st.empty() || root != nullptr){

      if(root!=nullptr){
	st.push(root);
	root = root -> left;
      }
      else{
	root = st.top();
	st.pop();
	inOrderTraverse.push_back(root->val);
	root = root -> right;
      }
      
    }

    return inOrderTraverse;
    
  }
  


  vector<int> postOrder(TreeNode* root){
    vector<int>postOrderTraverse;
    postOrderRecursive(root, postOrderTraverse);
    return postOrderTraverse;
  }

  void postOrderRecursive(TreeNode* root, vector<int>&postOrderTraverse){
    if(root==nullptr){
      return;
    }

    postOrderRecursive(root->left, postOrderTraverse);
    postOrderRecursive(root->right, postOrderTraverse);
    postOrderTraverse.push_back(root->val);
    
  }


  vector<int>postOrderIterative(TreeNode* root){

    vector<int>postOrderTraverse;
    
    stack<TreeNode*>st1;
    stack<int>st2;

    st1.push(root);

    while(!st1.empty()){
      TreeNode* top = st1.top();
      st1.pop();
      st2.push(top->val);
      if(top->left != nullptr){
	st1.push(top->left);
      }
      if(top->right != nullptr){
	st1.push(top->right);
      }
      
    }

    while(!st2.empty()){
      int val = st2.top();
      postOrderTraverse.push_back(val);
      st2.pop();
    }

    return postOrderTraverse;
    
  }


  vector<int>postOrderIterativeUsingSingleStack(TreeNode* root){
    vector<int>postOrderTraverse;
    stack<TreeNode*>st;
    while(!st.empty() || root != nullptr){
      if(root != nullptr){
	st.push(root);
	root = root -> left;
      }
      else{
	TreeNode* temp = st.top()->right;
	if(temp == nullptr){
	  temp = st.top();
	  st.pop();
	  postOrderTraverse.push_back(temp->val);
	  while(!st.empty() && temp == st.top()->right){
	    temp = st.top();
	    postOrderTraverse.push_back(temp->val);
	    st.pop();
	  }
	}
	else{
	  root = temp;
	}
      }
    }

    return postOrderTraverse;
  }
  
  
};



int main(int argc, char *argv[]){

  TreeTraversal tt;
  
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(8);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<int>preOrderTraversal = tt.preOrder(root);

  cout << "=======  pre order recursive  ========" <<  endl;
  
  for(auto num: preOrderTraversal){
    cout << num <<  " ";
  }

  cout << endl <<  "======  pre order iterative  ========" << endl;
  
  vector<int>preOrderIterativeTraverse = tt.preOrderIterative(root);

  for(auto num: preOrderIterativeTraverse){
    cout << num <<  " ";
  }

  cout << endl;


  vector<int>inOrderTraversal = tt.inOrder(root);

  cout << "=======  in order recursive  =========" <<  endl;
  
  for(auto num: inOrderTraversal){
    cout << num <<  " ";
  }

  cout << endl <<  "=======  in order iterative  ========" << endl;
  
  vector<int>inOrderIterativeTraverse = tt.inOrderIterative(root);

  for(auto num: inOrderIterativeTraverse){
    cout << num <<  " ";
  }

  cout << endl;

  cout << "======  post order recursive =======" << endl;

  vector<int>postOrderRecursiveTraverse = tt.postOrder(root);

  for(auto num : postOrderRecursiveTraverse){
    cout << num << " ";
  }

  cout << endl;


  cout << "=======  post order iterative ======" << endl;

  vector<int>postOrderIterativeTraverse = tt.postOrderIterative(root);

  for(auto num : postOrderIterativeTraverse){
    cout << num << " ";
  }

  cout << endl;


  cout << "=======  post order iterative using single stack ======" << endl;

  postOrderIterativeTraverse = tt.postOrderIterativeUsingSingleStack(root);

  for(auto num : postOrderIterativeTraverse){
    cout << num << " ";
  }

  cout << endl;
    
  return 0;
}
