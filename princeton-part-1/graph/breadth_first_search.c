#include<stdio.h>
#include<stdlib.h>
#include"undirected_graph.h"


struct queue *head = NULL;

void enqueue(int element){
  struct queue *temp_head = head;
  struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
  temp->value = element;
  temp->next_node = NULL;
  while(temp_head!=NULL){
    temp_head = temp_head->next_node;
  }
  temp_head = temp;
  if(head==NULL){
    head = temp;
  }
};

int dequeue(){
  if(head==NULL){
    printf("queue already empty\n");
    return -1;
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


void bfs(int source, int marked[], int edge_to[]){
  marked[source] = 1;
  enqueue(source);
  while(!isEmpty()){
    int element = dequeue();
    struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(element);
    while(ptr_to_adjacent_nodes!=NULL){
      int node_value = ptr_to_adjacent_nodes->value;
      if(!marked[node_value]){
	marked[node_value] = 1;
	enqueue(node_value);
	edge_to[node_value] = element;
      }
      ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
    }
  }
  
  
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
  //struct adj_node **ptr_to_arr = graph_node -> pointer_to_arr;
  //struct adj_node *first_element = (struct adj_node *)*ptr_to_arr;

  int marked[num_vertices];

  for(int i=0; i < num_vertices; i++){
    marked[i] = 0;
  }
  
  int edge_to[num_vertices];

  for(int i=0; i < num_vertices; i++){
    edge_to[i] = -1;
  }

  int source = 0;

  bfs(source, marked, edge_to);

  printf("\n");

  printf("================= graph =====================\n");

  printGraph();

  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices);
  
  return 0;
}
