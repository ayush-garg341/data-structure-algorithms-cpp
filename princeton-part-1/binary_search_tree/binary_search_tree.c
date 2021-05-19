#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bst.h"


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


int main(){
  root = putKeyValue((char*)"h", 1, root);
  root = putKeyValue((char*)"c", 2, root);
  root = putKeyValue((char*)"s", 3, root);
  root = putKeyValue((char*)"a", 4, root);
  root = putKeyValue((char*)"e", 5, root);
  root = putKeyValue((char*)"r", 6, root);
  root = putKeyValue((char*)"x", 7, root);

  printf("value for key x = %d\n", get((char *)"x"));

  level_order_traversal(root);
  
  return 0;
}
