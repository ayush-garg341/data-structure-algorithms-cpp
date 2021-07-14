#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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

stack<int> pathToVertex(int edgeTo[], int vertex){
  stack<int>path;
  int dest = vertex;
  path.push(dest);
  while(edgeTo[dest]!=dest){
    path.push(edgeTo[dest]);
    dest = edgeTo[dest];
  }

  return path;
};


void bfs(vector<int>adj[],  int edgeTo[], bool marked[], int source){
  queue<int>vertices;
  vertices.push(source);
  edgeTo[source] = source;
  marked[source] = true;
  while(!vertices.empty()){
    int current = vertices.front();
    vertices.pop();
    for(auto x: adj[current]){
      if(!marked[x]){
	marked[x] = true;
	edgeTo[x] = current;
	vertices.push(x);
      }
    }
    cout << endl;
  }
}


int distanceFromSource(int edgeTo[], int dest){
  int count = 0;
  while(edgeTo[dest]!=dest){
    count++;
    dest = edgeTo[dest];
  }

  return count;
}



int main(int argc, char* argv[]){
  int V = 6;

  // can be written like this....
  // vector<int>* adj = new vector<int>[V];
  
  vector<int>adj[V];
  addEdge(adj, 0, 5);
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  printGraph(adj, V);

  cout << endl;

  int edgeTo[V];
  bool marked[V] = {false};
  int source = 0;

  edgeTo[source] = source;

  dfsUtil(adj, edgeTo, marked, source);

  printVertexSource(edgeTo, marked,  V);

  int dest = 4;
  stack<int>path = pathToVertex(edgeTo, dest);
  while(!path.empty()){
    cout << path.top() << " -> ";
    path.pop();
  }

  cout << endl;


  /* ----------------------- BFS processing --------------------- */

  // marked[V] = {false};

  for(int i = 0; i < V; i++){
    marked[i] = false;
  }
  
  bfs(adj, edgeTo, marked, source);

  printVertexSource(edgeTo, marked,  V);

  dest = 4;
  int distance = distanceFromSource(edgeTo, dest);
  cout << "distance to " << dest << " from source " << source <<   " = " << distance << endl;
  
  return 0;
}
