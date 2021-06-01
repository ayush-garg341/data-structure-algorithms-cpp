#include<stdio.h>
#include<stdlib.h>
#include"directed_graph.h"

struct stack_node *head = NULL;

int FLAG = 0;

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


void makeCycle(int source, int value, int edge_to[]){
  push(value);
  push(source);
  while(edge_to[source]!=value){
    source = edge_to[source];
    push(source);
  }
  push(value);
}


int checkCycle(int marked[], int edge_to[], int onStack[], int num_vertices){
  for(int i = 0; i < num_vertices; i++){
    int cycle = dfs_cycle(i, marked, edge_to, onStack);
    if(cycle==1){
      FLAG = 0;
      return 1;
    }
  }
  return 0;
}


int dfs_cycle(int source, int marked[], int edge_to[], int onStack[]){
  marked[source] = 1;
  onStack[source] = 1;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;

    if(FLAG==1){
      return FLAG;
    }
    
    if(!marked[value]){
      edge_to[value] = source;
      dfs_cycle(value, marked, edge_to, onStack);
    }
    else if (onStack[value]){
      printf("source = %d, value = %d\n", source, value);
      makeCycle(source, value, edge_to);
      FLAG = 1;
      return FLAG;
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
  onStack[source] = 0;
  return FLAG;
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


void printCycle(){
  while(head!=NULL){
    printf("%d -> ", pop());
  }
  printf("\n");
  return;
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  int marked[num_vertices];
  int edge_to[num_vertices];
  int levels[num_vertices];
  int onStack[num_vertices];
  for(int i = 0; i< num_vertices; i++){
    marked[i] = 0;
    edge_to[i] = -1;
    levels[i] = 0;
    onStack[i] = 0;
  }


  printf("================= graph =====================\n");
  printGraph();
  
  printf(" ================= Nodes visited =======================\n");
  
  printVisitedNodes(marked, num_vertices);


  printf("==================== Checking if graph has cycle or not to find topological ordering =========================\n");
  int cycle = checkCycle(marked, edge_to, onStack, num_vertices);

  if(cycle==1){
    printf("Graph has cycle\n");
    printf("Cycle is ---- \n");
    printCycle();
  }
  else{
    printf("Graph has no cycle\n");
  }

  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices, levels);

}
