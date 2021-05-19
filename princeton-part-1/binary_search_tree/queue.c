#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

struct bst_queue{
  struct bst_node* data;
  struct bst_queue* next;
};


struct bst_queue* head = NULL;

void pushQueue(struct bst_node* node){
  struct bst_queue* x = (struct bst_queue *)malloc(sizeof(struct bst_queue));
  x->data=node;
  x->next=NULL;
  
  if(head==NULL){
    head = x;
    return;
  }
  else{
    struct bst_queue* temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = x;
  }
}


struct bst_node* popQueue(){
  struct bst_queue* temp = head;
  struct bst_node* front = temp -> data;
  head = head->next;
  free(temp);
  return front;
}

int queueEmpty(){
  return head == NULL;
}
