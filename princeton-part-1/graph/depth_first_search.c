#include<stdio.h>
#include<stdlib.h>
#include"undirected_graph.h"


void dfs(struct adj_node *adj_node, int source, int marked[], int edge_to[]){
  marked[source] = 1;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      dfs(adj_node, value, marked, edge_to);
      edge_to[value] = source;
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
}


void printVisitedNodes(int marked[], int num_vertices){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, visited = %d\n", i, marked[i]);
  }
  
  return;
}


void edgeToVertex(int edge_to[], int num_vertices){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, from = %d\n", i, edge_to[i]);
  }
  
  return;
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  struct adj_node **ptr_to_arr = graph_node -> pointer_to_arr;
  struct adj_node *first_element = (struct adj_node *)*ptr_to_arr;

  int marked[num_vertices];

  for(int i=0; i < num_vertices; i++){
    marked[i] = 0;
  }
  
  int edge_to[num_vertices];

  for(int i=0; i < num_vertices; i++){
    edge_to[i] = -1;
  }

  dfs(first_element, 0, marked, edge_to);

  printf("\n");

  printf("================= graph =====================\n");

  printGraph();

  printf(" ================= Nodes visited =======================\n");
  
  printVisitedNodes(marked, num_vertices);


  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices);
  
  return 0;
}
