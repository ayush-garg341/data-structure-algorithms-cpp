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


int isElementAdjacentToValue(int element, int value){
  struct adj_node *value_head = adjacent_vertex(value, 0);
  while(value_head!=NULL){
    if(value_head->value == element){
      return 0;
    }
    value_head = value_head -> pointer_to_adj_node;
  }
  return 1;
}


int notFoundAdjacent(int source, int adjacentValue){
  struct adj_node *source_adjacent_values = adjacent_vertex(source, 0);
  struct adj_node *target_adjacent_values = adjacent_vertex(adjacentValue, 0);
  int source_check = 0;
  int adjacent_check = 0;
  while(source_adjacent_values!=NULL){
    if(source_adjacent_values->value == adjacentValue){
      source_check = 1;
    }
    source_adjacent_values = source_adjacent_values -> pointer_to_adj_node;
  }

  while(target_adjacent_values!=NULL){
    if(target_adjacent_values -> value == source){
      adjacent_check = 1;
    }
    target_adjacent_values = target_adjacent_values -> pointer_to_adj_node;
  }

  if(source_check && adjacent_check){
    return 0;
  }
  
  return 1;
}


int checkCycle(int marked[], int edge_to[], int num_vertices){
  for(int i = 0; i < num_vertices; i++){
    int cycle = dfs_cycle(i, marked, edge_to);
    if(cycle==1){
      return 1;
    }
    for(int j = 0; j < num_vertices; j++){
      marked[j] = 0;
    }
  }

  return 0;
}


int dfs_cycle(int source, int marked[], int edge_to[]){
  push(source);
  while(!isEmpty()){
    int element = pop();
    if(!marked[element]){
      marked[element] = 1;
      struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(element, 0);
      while(ptr_to_adjacent_nodes!=NULL){
	int value = ptr_to_adjacent_nodes->value;
	if(!marked[value]){
	  edge_to[value] = element;
	  push(value);
	}
	else if(marked[value]){
	  printf("source element = %d, adjacent value = %d edge_to[%d] = %d\n", element, value, value,  edge_to[value]);
	  return 1;
	}
	ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
      }
    }
  }
  return 0;
}


void printVisitedNodes(int marked[], int num_vertices){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, visited = %d\n", i, marked[i]);
  }
  
  return;
}


void edgeToVertex(int edge_to[], int num_vertices, int levels[]){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, from = %d\n", i, edge_to[i]);
  }
  
  return;
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  int marked[num_vertices];
  int edge_to[num_vertices];
  int levels[num_vertices];
  for(int i = 0; i< num_vertices; i++){
    marked[i] = 0;
    edge_to[i] = -1;
    levels[i] = 0;
  }


  printf("================= graph =====================\n");
  printGraph();
  
  printf(" ================= Nodes visited =======================\n");
  
  printVisitedNodes(marked, num_vertices);


  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices, levels);

  printf("==================== Checking if graph has cycle or not to find topological ordering =========================\n");
  int cycle = checkCycle(marked, edge_to, num_vertices);

  if(cycle==1){
    printf("Graph has cycle\n");
  }
  else{
    printf("Graph has no cycle\n");
  }
}
