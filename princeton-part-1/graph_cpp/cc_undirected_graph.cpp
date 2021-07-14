#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>adj[], int from, int to){
  adj[from].push_back(to);
  adj[to].push_back(from);
};


void dfs(vector<int>adj[], int edgeTo[], bool marked[], int source, int count, int cc[]){
  marked[source] = true;
  cc[source] = count;
  for(auto x: adj[source]){
    if(!marked[x]){
      dfs(adj, edgeTo, marked, x, count, cc);
      edgeTo[x]=source;
    }
  }
}


void dfsUtil(vector<int>adj[], int edgeTo[], bool marked[], int source, int count, int cc[]){
  dfs(adj, edgeTo, marked, source, count, cc);
}


bool areConnected(int u, int v, int cc[]){
  return cc[u]==cc[v];
}


int main(){
  int V = 13;
  
  // can be written like this....
  // vector<int>* adj = new vector<int>[V];

  vector<int>adj[V];
  addEdge(adj, 0, 5);
  addEdge(adj, 4, 3);
  addEdge(adj, 0, 1);
  addEdge(adj, 9, 12);
  addEdge(adj, 6, 4);
  addEdge(adj, 5, 4);
  addEdge(adj, 0, 2);
  addEdge(adj, 11, 12);
  addEdge(adj, 9, 10);
  addEdge(adj, 0, 6);
  addEdge(adj, 7, 8);
  addEdge(adj, 9, 11);
  addEdge(adj, 5, 3);

  int cc[V];

  bool marked[V] = {false};
  int edgeTo[V];
  
  int count = 0;
  for(int i=0; i < V; i++){
    if(!marked[i]){
      dfsUtil(adj, edgeTo, marked, i, count, cc);
      count++;
    }
  }

  bool query;
  int u = 8; int v = 7;
  cout << areConnected(8, 7, cc) << endl;
  cout << areConnected(6, 4, cc) << endl;
  cout << areConnected(9, 11, cc) << endl;
  cout << areConnected(3, 5, cc) << endl;
  cout << areConnected(5, 9, cc) << endl;
  
  return 0;
  
}
