#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototype.h"

struct st{
  char *key;
  int value;
  struct st* link;
};

struct st* head = NULL;

void insert(char *x, int val){

  int found = put(x, val);
  if(found==0){
    struct st* temp = (struct st*)malloc(sizeof(struct st*));
    temp->key=x;
    temp->value=val;
    temp->link = head;
    head=temp;
  }  
}


int put(char *x, int val){
  struct st* temp = head;
  int found = 0;
  while(temp!=NULL){
    if(strcmp((char*)temp->key, (char*)x)==0){
      found = 1;
      temp->value = val;
      return found;
    }
    else{
      temp = temp -> link;
    }
  }

  if(found==1){
    printf("key already present, value updated successfully\n");
  }
  else{
    printf("Key not found\n");
  }

  return found;
  
}


int get(char *x){
  struct st* temp = head;
  while(temp!=NULL){
    if(strcmp((char*)temp->key, (char*)x)==0){
      return temp->value;
    }
    else{
      temp = temp -> link;
    }
  }
  return 0;
}



int main(){
  insert((char *)"first", 1);
  insert((char *)"second", 23);
  insert((char *)"third", 30);
  printf("value is %d\n", get((char *)"first"));
  printf("value is %d\n", get((char *)"second"));
  put((char *)"third", 3);
  printf("value is %d\n", get((char *)"third"));
  return 0;
}
