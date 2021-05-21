#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bst.h"


int is_tree_bst = 1;
char *previous_key = (char*)"\0";

struct bst_node* root = NULL;

int get(char *key){
  struct bst_node* x = root;
  
  while(x!=NULL){
    printf("====================================================\n");
    int comparison = strcmp((char *)x->key, (char *)key);
    if(comparison>0){
      x = x->left_tree;
    }
    else if(comparison<0){
      x = x->right_tree;
    }
    else{
      return x->value;
    }
  }

  return -1;
}

struct bst_node* putKeyValue(char *key, int value, struct bst_node* root){
  if(root==NULL){
    struct bst_node* root = (struct bst_node*)malloc(sizeof(struct bst_node));
    root->key = (char*)key;
    root->value = value;
    root->left_tree = NULL;
    root->right_tree = NULL;
    return root;
  }
  else{
    int cmp = strcmp((char *)root->key, (char *)key);
    if(cmp > 0){
      root->left_tree = putKeyValue(key, value, root->left_tree);
    }
    else if(cmp < 0){
      root->right_tree = putKeyValue(key, value, root->right_tree);
    }
    else{
      root->value = value;
    }

    return root;
  }
}


struct bst_node* min(struct bst_node* sub_tree){
  if(sub_tree->left_tree==NULL){
    return sub_tree;
  }
  while(sub_tree->left_tree!=NULL){
    sub_tree = sub_tree -> left_tree;
  }
  return sub_tree;
}



struct bst_node* max(struct bst_node* sub_tree){
  if(sub_tree->right_tree==NULL){
    return sub_tree;
  }
  while(sub_tree->right_tree!=NULL){
    sub_tree = sub_tree -> right_tree;
  }
  return sub_tree;
}


struct bst_node* deleteKey(char *key, struct bst_node *root){
  int cmp = strcmp((char *)root->key, (char *)key);
  if(cmp > 0){
    root->left_tree = deleteKey(key,  root->left_tree);
  }
  else if(cmp < 0){
    root->right_tree = deleteKey(key, root->right_tree);
  }
  else{
    if(root->left_tree == NULL){
      struct bst_node *right = root->right_tree;
      free(root);
      return right;
    }
    else if(root->right_tree == NULL){
      struct bst_node *left = root->left_tree;
      free(root);
      return left;
    }
    struct bst_node* min_right_tree = min(root->right_tree);
    root->key = min_right_tree->key;
    root->value = min_right_tree->value;
    root->right_tree = deleteKey(min_right_tree->key, root->right_tree);

    return root;
  }
}



void level_order_traversal(struct bst_node* root){
  if(root==NULL){
    return ;
  }
  else{
    pushQueue(root);
    while(!queueEmpty()){
      struct bst_node* front = popQueue();
      printf("%s ", (char *)front->key);
      if(front->left_tree!=NULL){
	pushQueue(front->left_tree);
      }
      if(front->right_tree!=NULL){
	pushQueue(front->right_tree);
      }
    }
  }
  printf("\n");
}



void pre_order_traversal(struct bst_node *root){
  if(root==NULL){
    return;
  }
  printf("%s ", (char *)root->key);
  pre_order_traversal(root->left_tree);
  pre_order_traversal(root->right_tree);
}



void in_order_traversal(struct bst_node *root){
  if(root == NULL){
    return;
  }
  in_order_traversal(root->left_tree);
  printf("%s ", (char *)root->key);
  in_order_traversal(root->right_tree);
}


void post_order_traversal(struct bst_node* root){
  if(root == NULL){
    return;
  }
  post_order_traversal(root->left_tree);
  post_order_traversal(root->right_tree);
  printf("%s ", (char *)root->key);
}


void bst_in_order_traversal(struct bst_node* root){
  if(root == NULL){
    return;
  }
  bst_in_order_traversal(root->left_tree);
  char *current_key =  (char *)root->key;
  printf("current = %s, previous = %s\n", current_key, previous_key);
  int cmp = strcmp(current_key, previous_key);
  if(cmp >= 0){
    previous_key = current_key;
  }
  else{
    is_tree_bst = 0;
    //return;
  }
  bst_in_order_traversal(root->right_tree);
}


int is_bst(struct bst_node *root){
  // struct bst_node *minimum_key_node = min(root);
  // char *minimum_key = minimum_key_node -> key;
  bst_in_order_traversal(root);

  if(is_tree_bst==1){
    return 1;
  }
  return 0;
}


int main(){
  root = putKeyValue((char*)"h", 1, root);
  root = putKeyValue((char*)"c", 2, root);
  root = putKeyValue((char*)"s", 3, root);
  root = putKeyValue((char*)"a", 4, root);
  root = putKeyValue((char*)"e", 5, root);
  root = putKeyValue((char*)"r", 6, root);
  root = putKeyValue((char*)"x", 7, root);
  root = putKeyValue((char*)"d", 8, root);
  root = putKeyValue((char*)"f", 9, root);
  root = putKeyValue((char*)"g", 10, root);


  root = deleteKey((char *)"c", root);
  
  
  printf("value for key x = %d\n", get((char *)"x"));

  printf(" ======= level order traversal ====== \n");
  level_order_traversal(root);

  printf(" ======= pre order traversal ======= \n");
  
  pre_order_traversal(root);

  printf("\n");

  printf(" ====== in order traversal / gives sorted list ======= \n");

  in_order_traversal(root);

  printf("\n");


  printf(" ======== post order traversal ========= \n");

  post_order_traversal(root);

  printf("\n");

  printf("binary tree is binary search tree = %d\n", is_bst(root));

  is_tree_bst = 1;
  previous_key = (char *)"\0";

  // check for any other binary tree which is not bst

  struct bst_node *root2 = (struct bst_node*)malloc(sizeof(struct bst_node));
  root2->key = (char*)"d";
  root2->value = 1;
  root2->left_tree = NULL;
  root2->right_tree = NULL;

  struct bst_node *root2_left = (struct bst_node*)malloc(sizeof(struct bst_node));
  root2_left->key = (char*)"e";
  root2_left->value = 2;
  root2_left->left_tree = NULL;
  root2_left->right_tree = NULL;

  struct bst_node *root2_right = (struct bst_node*)malloc(sizeof(struct bst_node));
  root2_right->key = (char*)"f";
  root2_right->value = 3;
  root2_right->left_tree = NULL;
  root2_right->right_tree = NULL;

  root2->left_tree = root2_left;
  root2->right_tree = root2_right;
  
  printf("second binary tree is binary search tree = %d\n", is_bst(root2));

  printf("previous key = %s\n", previous_key);
  
  return 0;
}
