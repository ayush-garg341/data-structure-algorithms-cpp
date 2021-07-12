#include<iostream>
#include<vector>
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
  
  return 0;
}
