#include<stdio.h>
#include<stdlib.h>
#include"directed_graph.h"
# define NUM_VERTICES 13

struct adj_node *adj[NUM_VERTICES];

void add_edge(int source, int dest){

  struct adj_node *new_node = (struct adj_node *)malloc(sizeof(struct adj_node));
  new_node -> pointer_to_adj_node = NULL;
  new_node -> value = dest;
  
  struct adj_node *temp_source = adj[source];

  new_node -> pointer_to_adj_node = temp_source;
  adj[source] = new_node;

}


struct adj_node * adjacent_vertex(int vertex, int flag){
  struct adj_node *head = adj[vertex];
  struct adj_node *temp = head;
  
  while(temp!=NULL){
    if(flag==1){
      printf("%d ", temp->value);
    }
    temp = temp -> pointer_to_adj_node;
  }

  return head;
}


int num_of_edges(){
  int total_edges = 0;
  for(int i=0; i < NUM_VERTICES; i++){
    total_edges += degree(i);
  }
  return total_edges;
}

int degree(int vertex){
  struct adj_node *head = adj[vertex];
  int count = 0;
  while(head!=NULL){
    count += 1;
    head = head -> pointer_to_adj_node;
  }

  return count;
}


int maxDegree(){
  int max = 0;
  for(int i=0; i < NUM_VERTICES; i++){
    if(degree(i)>max){
      max = degree(i);
    }
  }

  return max;
}


void printGraph(){
  for(int i=0; i < NUM_VERTICES ; i++){
    printf("vertex ---> %d = ", i);
    adjacent_vertex(i, 1);
    printf("\n");
  }
}



struct graph_node * create_graph(){

  struct graph_node *graph_node = (struct graph_node *)malloc(sizeof(struct graph_node));

  graph_node -> vertices = NUM_VERTICES;
  
  for(int i=0;i < NUM_VERTICES; i++){
    adj[i] = NULL;
  }

  graph_node -> pointer_to_arr =  adj;

  add_edge(0, 1);
  add_edge(0, 5);
  add_edge(2, 3);
  add_edge(2, 0);
  add_edge(3, 2);
  add_edge(3, 5);
  add_edge(4, 2);
  add_edge(4, 3);
  add_edge(5, 4);
  add_edge(6, 0);
  add_edge(6, 8);
  add_edge(6, 4);
  add_edge(6, 9);
  add_edge(7, 9);
  add_edge(7, 6);
  add_edge(8, 6);
  add_edge(9, 10);
  add_edge(9, 11);
  add_edge(10, 12);
  add_edge(11, 12);
  add_edge(11, 4);
  add_edge(12, 9);
  
  return graph_node;

}
