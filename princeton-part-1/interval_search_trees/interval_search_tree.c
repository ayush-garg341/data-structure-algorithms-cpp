#include<stdio.h>
#include<stdlib.h>
#include"ist.h"

struct ist_node *root = NULL;

struct ist_node *latest_node = NULL;


void updateMaxValForNode(struct ist_node *current_node, struct ist_node *latest_node){
  if(current_node->max_so_far < latest_node->max_so_far){
    current_node->max_so_far = latest_node->max_so_far;
  }
}



struct ist_node * insertInterval(int low, int high, struct ist_node *root){
  if(root==NULL){
    struct ist_node* root = (struct ist_node*)malloc(sizeof(struct ist_node));
    root->left_val = low;
    root->right_val = high;
    root->max_so_far = high;
    root->left_tree = NULL;
    root->right_tree = NULL;
    latest_node = root;
    return root;
  }
  else{
    if(low < root->left_val){
      root->left_tree = insertInterval(low, high, root->left_tree);
    }
    else if(low > root->left_val){
      root->right_tree = insertInterval(low, high, root->right_tree);
    }

    updateMaxValForNode(root, latest_node);

    return root;
  }
}


void searchIntersectingInterval(struct ist_node *root, int low, int high){
  struct ist_node *x = root;
  while(x!=NULL){
    if(intersects(x, low, high)){
      printf("new interval (%d, %d) intersects with  existing interval (%d, %d) \n", low, high, x->left_val, x->right_val);
      return;
    }
    else if(x->left_tree==NULL){
      x = x->right_tree;
    }
    else if(x->left_tree->max_so_far < low){
      x = x->right_tree;
    }
    else{
      x = x->left_tree;
    }
  }

  return ;
}


int intersects(struct ist_node *x, int low, int high){
  printf("%d %d %d %d\n", x->right_val, x->left_val, low, high);
  if(x->right_val < low || x->left_val > high){
    return 0;
  }
  return 1;
}

void in_order_traversal(struct ist_node *root){
  if(root == NULL){
    return;
  }
  in_order_traversal(root->left_tree);
  printf("node = %d max = %d \n", root->left_val, root->max_so_far);
  in_order_traversal(root->right_tree);
}


int main(){
  root = insertInterval(17, 19, root);
  root = insertInterval(5, 8, root);
  root = insertInterval(21, 24, root);
  root = insertInterval(4, 8, root);
  root = insertInterval(15, 18, root);
  root = insertInterval(7, 10, root);
  root = insertInterval(16, 22, root);

  in_order_traversal(root);
  
  searchIntersectingInterval(root, 21, 23);
  
}
