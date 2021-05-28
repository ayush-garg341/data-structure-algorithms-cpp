#include<stdio.h>
#include<stdlib.h>
#include"undirected_graph.h"


struct stack_node *head = NULL;

void dfs(struct adj_node *adj_node, int source, int marked[], int edge_to[]){
  marked[source] = 1;
  struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(source, 0);

  while(ptr_to_adjacent_nodes!=NULL){
    int value = ptr_to_adjacent_nodes->value;
    if(!marked[value]){
      dfs(adj_node, value, marked, edge_to);
      edge_to[value] = source;
    }
    ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
  }
}


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


void dfs_without_recusrion(int source, int marked[], int edge_to[]){
  //marked[source]=1;
  //edge_to[source] = source;
  push(source);
  while(!isEmpty()){
    int element = pop();
    if(!marked[element]){
      marked[element] = 1;
      struct adj_node *ptr_to_adjacent_nodes = adjacent_vertex(element, 0);
      while(ptr_to_adjacent_nodes!=NULL){
	int value = ptr_to_adjacent_nodes->value;
	if(!marked[value]){
	  //marked[value] = 1;
	  edge_to[value] = element;
	  push(value);
	}
	ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
      }
    }
  }
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


int hasPathTo(int marked[], int vertex){
  return marked[vertex];
}



int hasCycle(int source, int marked[], int edge_to[]){
  push(source);
  edge_to[source] = source;
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
	else if(marked[value] && edge_to[element]!=value){
	  return 1;
	}
	ptr_to_adjacent_nodes = ptr_to_adjacent_nodes -> pointer_to_adj_node;
      }
    }
  }
  return 0;
}



struct path_nodes * pathTo(int edge_to[], int source, int destination){
  int temp_path = edge_to[destination];
  struct path_nodes *head = NULL;
  struct path_nodes *path_node = (struct path_nodes*)malloc(sizeof(struct path_nodes));
  path_node -> node = destination;
  path_node -> next_node = head;
  head = path_node;
  while(temp_path!=source){
    struct path_nodes *path_node2 = (struct path_nodes*)malloc(sizeof(struct path_nodes));
    path_node2 -> node = temp_path;
    path_node2 -> next_node = head;
    head = path_node2;
    temp_path = edge_to[temp_path];
  }
  struct path_nodes *path_node3 = (struct path_nodes*)malloc(sizeof(struct path_nodes));
  path_node3 -> node = temp_path;
  path_node3 -> next_node = head;
  head = path_node3;
  return head;
}



int main(){
  struct graph_node *graph_node = create_graph();
  int num_vertices = graph_node -> vertices;
  struct adj_node **ptr_to_arr = graph_node -> pointer_to_arr;
  struct adj_node *first_element = (struct adj_node *)*ptr_to_arr;

  int marked[num_vertices];
  int edge_to[num_vertices];
  int levels[num_vertices];
  
  for(int i=0; i < num_vertices; i++){
    marked[i] = 0;
    edge_to[i] = -1;
  }

  int source = 0;

  int destination = 5;
  
  // dfs(first_element, source, marked, edge_to);

  dfs_without_recusrion(source, marked, edge_to);

  printf("\n");

  printf("================= graph =====================\n");

  printGraph();

  printf(" ================= Nodes visited =======================\n");
  
  printVisitedNodes(marked, num_vertices);


  printf(" ================ Nodes visited from ========================\n");
  
  edgeToVertex(edge_to, num_vertices, levels);

  printf(" ================ has path to ========================\n");
  printf("There is a path from source = %d to dest = %d =>> %d\n", source, destination, hasPathTo(marked, destination));

  printf("==================== path ====================== \n");
  struct path_nodes *head = pathTo(edge_to, 0, 3);
  while(head!=NULL){
    printf("%d ", head->node);
    head = head->next_node;
  }

  printf("\n");

  /* printf(" ======================= does the graph has cycle ====================\n"); */
  /* int has = hasCycle(0, marked, edge_to); */
  /* if(has==0){ */
  /*   printf("graph does not have cycle\n"); */
  /* } */
  /* else{ */
  /*   printf("graph has cycle\n"); */
  /* } */
  
  return 0;
}
