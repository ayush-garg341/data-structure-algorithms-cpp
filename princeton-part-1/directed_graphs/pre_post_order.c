#include<stdio.h>
#include<stdlib.h>
#include"directed_graph.h"

struct queue *head = NULL;
struct queue *tail = NULL;

void enqueue(int element){
  struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
  temp->value = element;
  temp->next_node = NULL;
  if(head==NULL && tail ==NULL){
    head=tail=temp;
    return;
  }
  tail->next_node = temp;
  tail = temp;
  printf("enqueue ==== \n");
  printQueue();
};


void printQueue(){
  struct queue *temp = head;
  while(temp!=NULL){
    printf("%d -> ", temp->value);
    temp = temp->next_node;
  }
  printf("\n");
  
};


int dequeue(){
  if(head==NULL){
    printf("queue already empty\n");
    return -1;
  }
  else if(head==tail){
    struct queue *temp = head;
    int value = temp->value;
    head = tail = NULL;
    free(temp);
    return value;
  }
  struct queue *temp = head;
  int value = temp->value;
  head = temp->next_node;
  free(temp);
  return value;
}

int isEmpty(){
  return head==NULL;
}

void printOrder(){
  while(head!=NULL){
    printf("%d -> ", dequeue());
  }
  printf("\n");
  return;
}

void order(int source, int marked[]){
  marked[source] = 1;
  enqueue(source);
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      order(value, marked);
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
}

void post(int source, int marked[]){
  marked[source] = 1;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      post(value, marked);
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
  enqueue(source);
}

void preOrder(int marked[], int num_vertices){
  for(int i=0; i<num_vertices; i++){
    if(!marked[i]){
      order(i, marked);
    }
  }

  printOrder();
}


void postOrder(int marked[], int num_vertices){
  for(int i=0; i<num_vertices; i++){
    if(!marked[i]){
      post(i, marked);
    }
  }

  printOrder();
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;

  int marked[num_vertices];
  for(int i = 0; i< num_vertices; i++){
    marked[i] = 0;
  }
  
  printf("================= graph =====================\n");
  printGraph();

  printf("==================== pre order =========================\n");
  preOrder(marked, num_vertices);

  for(int i = 0; i< num_vertices; i++){
    marked[i] = 0;
  }
  
  printf("==================== post order =========================\n");
  postOrder(marked, num_vertices);

  return 0;
}
