#include<stdio.h>
#include<stdlib.h>
#include"undirected_graph.h"

/* struct stack_node *head = NULL; */

/* void push(int element){ */
/*   struct stack_node *temp = (struct stack_node*)malloc(sizeof (struct stack_node)); */
/*   temp -> value = element; */
/*   temp -> next_node = head; */
/*   head = temp; */
/* } */


/* int pop(){ */
/*   struct stack_node *temp = head; */
/*   int value = temp->value; */
/*   head = temp->next_node; */
/*   free(temp); */
/*   return value; */
/* } */

/* int isEmpty(){ */
/*   return head == NULL; */
/* } */

int search_traversed(int source, int value, struct adj_node *edge_traversed[]){
  struct adj_node *head_source = edge_traversed[source];
  while(head_source!=NULL){
    if(head_source->value == value){
      return 1;
    }
    head_source = head_source->pointer_to_adj_node;
  }

  struct adj_node *val_source = edge_traversed[value];
  while(val_source!=NULL){
    if(val_source->value == source){
      return 1;
    }
    val_source = val_source->pointer_to_adj_node;
  }
  
  return 0;
}


void make_traversed(int source, int value, struct adj_node *edge_traversed[]){
  //printf("source = %d,  value = %d\n", source, value);
  struct adj_node *new_node_source = (struct adj_node *)malloc(sizeof(struct adj_node));
  new_node_source -> pointer_to_adj_node = NULL;
  new_node_source -> value  = value;

  struct adj_node *new_node_value = (struct adj_node *)malloc(sizeof(struct adj_node));
  new_node_value -> pointer_to_adj_node = NULL;
  new_node_value -> value = source;
  
  struct adj_node *temp_source = edge_traversed[source];
  struct adj_node *temp_dest = edge_traversed[value];

  
  new_node_source -> pointer_to_adj_node = temp_source;
  edge_traversed[source] = new_node_source;

  new_node_value -> pointer_to_adj_node = temp_dest;
  edge_traversed[value] = new_node_value;

  //printTraversed(edge_traversed);
  
}


void printTraversed(struct adj_node *edge_traversed[]){
  for(int i = 0; i < 7; i++){
    struct adj_node *head = edge_traversed[i];
    printf("edge ====== %d\n", i);
    while(head!=NULL){
      printf("value ====== %d\n", head->value);
      head = head -> pointer_to_adj_node;
    }
  }
}



void eulerCyclePath(int source, struct adj_node *edge_traversed[]){
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);
  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!search_traversed(source, value, edge_traversed)){
      printf("%d -> %d ====\n", source, value);
      make_traversed(source, value, edge_traversed);
      eulerCyclePath(value,  edge_traversed);
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
}



int hasEulerCycle(int source, int num_vertices){
  for(int i=0; i< num_vertices; i++){
    int count = 0;
    struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(i, 0);
    while(ptr_to_adjacent_nodes!=NULL){
      count += 1;
      ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
    }
    if(count%2!=0){
      return 0;
    }
  }
  return 1;
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  struct adj_node **ptr_to_arr = graph_node -> pointer_to_arr;
  struct adj_node *first_element = (struct adj_node *)*ptr_to_arr;

  struct adj_node *edge_traversed[num_vertices];
  
  for(int i= 0; i< num_vertices; i++){
    edge_traversed[i] = NULL;
  }

  int source = 0;

  printf("================= graph =====================\n");

  printGraph();

  int eulerCycle = hasEulerCycle(source, num_vertices);
  if(eulerCycle==0){
    printf("graph vertices has odd number of vertices\n");
  }
  else{
    printf("graph vertices has even number of vertices\n");
  }

  if(eulerCycle){
    printf("Finding euler cycle\n");
    eulerCyclePath(source,  edge_traversed);
  }

  return 0;
  
}
