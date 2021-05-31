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
    printf("dequeue ==== \n");
    printQueue();
    return value;
  }
  struct queue *temp = head;
  int value = temp->value;
  head = temp->next_node;
  free(temp);
  printf("dequeue ==== \n");
  printQueue();
  return value;
}

int isEmpty(){
  return head==NULL;
}


void bfs_directed(int source, int marked[], int edge_to[], int levels[]){
  marked[source] = 1;
  enqueue(source);
  while(!isEmpty()){
    int element = dequeue();
    struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(element, 0);
    while(ptr_to_adjacent_nodes!=NULL){
      int node_value = ptr_to_adjacent_nodes->value;
      if(!marked[node_value]){
	marked[node_value] = 1;
	enqueue(node_value);
	edge_to[node_value] = element;
	levels[node_value] = levels[element] + 1;
      }
      ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
    }
  }
  
  
}


void edgeToVertex(int edge_to[], int num_vertices, int levels[]){
  for(int i=0; i< num_vertices; i++){
    printf("node = %d, from = %d, level = %d\n", i, edge_to[i], levels[i]);
  }
  return;
}


void printShortesRoute(int source, int dest, int edge_to[]){
  if(edge_to[dest]==source){
    printf("%d -> %d -> ", source, dest);
    return;
  }
  printShortesRoute(source, edge_to[dest], edge_to);
  printf("%d -> ", dest);
}


int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  
  int marked[num_vertices];
  int edge_to[num_vertices];
  int levels[num_vertices];
  
  for(int i=0; i < num_vertices; i++){
    marked[i] = 0;
    edge_to[i] = -1;
    levels[i] = 0;
  }

  int source = 0;

  bfs_directed(source, marked, edge_to, levels);

  printf("\n");

  printf("================= graph =====================\n");

  printGraph();

  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices, levels);

  /* printf(" ================= print shortes route =======================\n"); */
  /* printShortesRoute(0, 8, edge_to); */
  
  return 0;
}
