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



struct ist_node * insertInterval(struct interval interval, struct ist_node *root){
  if(root==NULL){
    struct ist_node* root = (struct ist_node*)malloc(sizeof(struct ist_node));
    (root->interval).left_val = interval.left_val;
    (root->interval).right_val = interval.right_val;
    root->max_so_far = interval.right_val;
    root->left_tree = NULL;
    root->right_tree = NULL;
    latest_node = root;
    return root;
  }
  else{
    if(interval.left_val < (root->interval).left_val){
      root->left_tree = insertInterval(interval, root->left_tree);
    }
    else if(interval.left_val > (root->interval).left_val){
      root->right_tree = insertInterval(interval, root->right_tree);
    }

    updateMaxValForNode(root, latest_node);

    return root;
  }
}


void searchIntersectingInterval(struct ist_node *root, struct interval interval){
  struct ist_node *x = root;
  while(x!=NULL){
    if(intersects(x, interval)){
      printf("new interval (%d, %d) intersects with  existing interval (%d, %d) \n", interval.left_val, interval.right_val, (x->interval).left_val, (x->interval).right_val);
      return;
    }
    else if(x->left_tree==NULL){
      x = x->right_tree;
    }
    else if(x->left_tree->max_so_far < interval.left_val){
      x = x->right_tree;
    }
    else{
      x = x->left_tree;
    }
  }

  return ;
}


int intersects(struct ist_node *x, struct interval interval){
  if((x->interval).right_val < interval.left_val || (x->interval).left_val > interval.right_val){
    return 0;
  }
  return 1;
}

void in_order_traversal(struct ist_node *root){
  if(root == NULL){
    return;
  }
  in_order_traversal(root->left_tree);
  printf("node = %d max = %d \n", (root->interval).left_val, root->max_so_far);
  in_order_traversal(root->right_tree);
}


int main(){

  struct interval interval1, interval2, interval3, interval4, interval5, interval6, interval7, search_interval;
  interval1.left_val = 17;
  interval1.right_val = 19;

  interval2.left_val = 5;
  interval2.right_val = 8;

  interval3.left_val = 21;
  interval3.right_val = 24;

  interval4.left_val = 4;
  interval4.right_val = 8;

  interval5.left_val = 15;
  interval5.right_val = 18;

  interval6.left_val = 7;
  interval6.right_val = 10;

  interval7.left_val = 16;
  interval7.right_val = 22;
  
  root = insertInterval(interval1, root);
  root = insertInterval(interval2, root);
  root = insertInterval(interval3, root);
  root = insertInterval(interval4, root);
  root = insertInterval(interval5, root);
  root = insertInterval(interval6, root);
  root = insertInterval(interval7, root);

  in_order_traversal(root);


  search_interval.left_val = 21;
  search_interval.right_val = 23;
  
  searchIntersectingInterval(root, search_interval);
  
}
