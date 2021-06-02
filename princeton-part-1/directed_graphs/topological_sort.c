#include<stdio.h>
#include<stdlib.h>
#include"directed_graph.h"

struct stack_node *head = NULL;

void push(int element){
  struct stack_node *temp = (struct stack_node*)malloc(sizeof (struct stack_node));
  temp -> value = element;
  temp -> next_node = head;
  head = temp;
}

int pop(){
  struct stack_node *temp = head;
  int value = temp->value;
  head = temp->next_node;
  free(temp);
  return value;
}

int isEmpty(){
  return head == NULL;
}

void printOrder(){
  while(head!=NULL){
    printf("%d -> ", pop());
  }

  printf("\n");
  
  return;
}

void order(int source, int marked[]){
  marked[source] = 1;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      order(value, marked);
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
  push(source);
}

void topologicalOrdering(int marked[], int num_vertices){
  for(int i=0; i<num_vertices; i++){
    if(!marked[i]){
      order(i, marked);
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

  printf("==================== topological ordering =========================\n");
  topologicalOrdering(marked, num_vertices);

  return 0;
}
