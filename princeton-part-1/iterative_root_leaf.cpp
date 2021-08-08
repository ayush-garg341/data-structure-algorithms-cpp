#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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
  vector<vector<int>> rootToLeafPaths(Node* root) {
    unordered_map<Node*, bool>umap;
    vector<vector<int>>all_paths;
    vector<int>path;
    stack<Node*>nodes;
    nodes.push(root);
    umap[root] = true;
    path.push_back(root->data);
    while(!nodes.empty() || root!=nullptr){
      
      if(root->left!=nullptr && umap[root->left]!=true){
	nodes.push(root->left);
	path.push_back(root->left->data);
	umap[root->left] = true;
	root = root->left;
      }
      else if(root->right!=nullptr && umap[root->right]!=true){
	nodes.push(root->right);
	path.push_back(root->right->data);
	umap[root->right] = true;
	root = root->right;
      }
      else if(root->left==nullptr && root->right==nullptr){
	all_paths.push_back(path);
	nodes.pop();
	path.pop_back();
	if(nodes.empty()){
	  root = nullptr;
	}
	else{
	  root = nodes.top();
	}
      }
      else {
      	nodes.pop();
      	path.pop_back();
      	if(nodes.empty()){
      	  root = nullptr;
      	}
      	else{
      	  root = nodes.top();
      	}
      }
    }

    return all_paths;
    
  }
  
};

int main(int argc, char* argv[]){

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
  vector<vector<int>> paths  = soln.rootToLeafPaths(root);

  for(int i = 0; i < paths.size(); i++){
    for(int j = 0;  j < paths[i].size(); j++){
      cout << paths[i][j] << " -> ";
    }
    cout << endl;
  }

  return 0;
}
