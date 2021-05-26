#include<stdio.h>
#include<stdlib.h>
#include"undirected_graph.h"


void dfs_cc(int source, int marked[], int id[], int count){
  marked[source] = 1;
  id[source] = count;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source);
  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      dfs_cc(value, marked, id, count);
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
}


void printCCNodes(int id[], int num_vertices){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, component = %d\n", i, id[i]);
  }
  
  return;
}




int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  int marked[num_vertices];
  int id[num_vertices];
  int count = 0;
  
  for(int i=0; i < num_vertices; i++){
    marked[i] = 0;
    id[i] = -1;
  }

  for(int i=0; i<num_vertices; i++){
    if(!marked[i]){
      dfs_cc(i, marked, id, count);
      count++;
    }
  }

  printf("\n");

  printf("================= graph =====================\n");

  printGraph();

  printf(" ================= Nodes visited =======================\n");
  
  printCCNodes(id, num_vertices);
  
}
