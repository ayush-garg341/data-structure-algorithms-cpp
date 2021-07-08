#include<iostream>
#include<stack>

using namespace std;

struct Node{

  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    left = right = nullptr;
  }
  
};



void inOrderIterative(Node* root){
  stack<Node*>s;
  while(!s.empty() || root!=nullptr){
    if(root!=nullptr){
      s.push(root);
      root = root -> left;
    }
    else{
      root = s.top();
      cout << root->data << " -> ";
      s.pop();
      root = root -> right;
    }
  }

  cout << endl;
}



void preOrderIterative(Node* root){
  stack<Node *>s;
  while(!s.empty() || root!=nullptr){
    if(root!=nullptr){
      cout << root -> data << " -> ";
      s.push(root);
      root = root->left;
    }
    else{
      root = s.top();
      s.pop();
      root = root -> right;
    }
  }

  cout << endl;
}
  
  
  

int main(int argc, char* argv[]){
  struct Node* root = new Node(10);
  root->left        = new Node(6);
  root->right       = new Node(14);
  root->left->left  = new Node(5);
  root->left->right = new Node(8);
  root->right->left  = new Node(11);
  root->right->right = new Node(18);

  preOrderIterative(root);

  inOrderIterative(root);
  
  return 0;
}
