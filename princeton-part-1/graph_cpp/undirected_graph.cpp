#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int>adj[], int from, int to){
  adj[from].push_back(to);
  adj[to].push_back(from);
};

void printGraph(vector<int>adj[], int V){
  for(int i=0; i < V; i++){
    cout << "\n Adjacency list of vertex "
	 << i << "\n head ";
    for(auto x: adj[i]){
      cout << x << " -> ";
    }

    cout << endl;
  }
}


void dfs(vector<int>adj[], int edgeTo[], bool marked[], int source){
  marked[source] = true;
  for(auto x: adj[source]){
    if(!marked[x]){
      dfs(adj, edgeTo, marked, x);
      edgeTo[x]=source;
    }
  }
}


void dfsUtil(vector<int>adj[], int edgeTo[], bool marked[], int source){
  dfs(adj, edgeTo, marked, source);
}


void printVertexSource(int edgeTo[], bool marked[], int V){
  for(int i = 0; i < V; i++){
    cout << i << " " << (marked[i]?"visited":"un-visited") << endl;
    cout << "to "<< i << " from " << edgeTo[i] << endl;
    printf("\n");
  }
}

void pathToVertex(int edgeTo[], int vertex){
  if(edgeTo[vertex]!=vertex){
    pathToVertex(edgeTo, edgeTo[vertex]);
    cout << edgeTo[vertex] << " -> ";
  }
  return;
}


int main(int argc, char* argv[]){
  int V = 5;

  // can be written like this....
  // vector<int>* adj = new vector<int>[V];
  
  vector<int>adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  printGraph(adj, V);

  cout << endl;

  int edgeTo[V];
  bool marked[V] = {false};
  int source = 0;

  edgeTo[source] = source;

  dfsUtil(adj, edgeTo, marked, source);

  printVertexSource(edgeTo, marked,  V);

  int dest = 4;
  pathToVertex(edgeTo, dest);
  cout << dest << endl;
  
  return 0;
}
