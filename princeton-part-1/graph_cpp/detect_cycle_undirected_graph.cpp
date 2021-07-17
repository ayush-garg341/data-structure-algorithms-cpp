/* Using disjoint set */

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
  int src, dest;
};


class Graph{
public:
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    Edge* edge;
};


Graph* createGraph(int V, int E){
  Graph* graph  =  new Graph();
  graph->V = V;
  graph->E = E;

  graph->edge = new Edge[graph->E * sizeof(Edge)];

  return graph;
};


int findParent(int parent[], int vertex){
  if(parent[vertex]==-1){
    return vertex;
  }
  return findParent(parent, parent[vertex]);
};


void Union(int parent[], int source_parent, int dest ){
  parent[dest] = source_parent;
};


bool isCyclic(Graph* graph){

  // Allocate memory for creating V vertices

  int *parent = new int[graph->V * sizeof(int)];

  // Initialize all subsets as single element sets
  memset(parent, -1, graph->V * sizeof(int));

  for(int i =0; i < graph->E; i++){
    int parent_source = findParent(parent, graph->edge[i].src);
    int parent_dest = findParent(parent, graph->edge[i].dest);

    if(parent_source==parent_dest){
      return 1;
    }

    Union(parent, parent_source,  parent_dest);
  }

  return 0;
  
};


int main(int argc, char* argv[]){
  int V = 5, E=5;
  Graph* graph = createGraph(V, E);

  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;

  graph->edge[1].src = 1;
  graph->edge[1].dest = 2;

  graph->edge[2].src = 2;
  graph->edge[2].dest = 3;

  graph->edge[3].src = 2;
  graph->edge[3].dest = 4;

  graph->edge[4].src = 3;
  graph->edge[4].dest = 4;

  if(isCyclic(graph)){
    cout << "Graph is cyclic \n" << endl;
  }
  else{
    cout << "Graph is acyclic \n" << endl;
  }
  
  
  cout << endl;
}
