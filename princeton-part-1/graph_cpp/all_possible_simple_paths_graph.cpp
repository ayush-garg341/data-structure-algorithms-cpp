#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void addEdge(vector<int>adj[], int from, int to){
  adj[from].push_back(to);
  adj[to].push_back(from);
};

void dfs(vector<int>adj[], bool visited[], int source, int dest, vector<vector<int>>&paths, vector<int>&path){
  
  visited[source] = true;
  path.push_back(source);

  if(source==dest){
    paths.push_back(path);
  }
  else{
    for(auto x: adj[source]){
      if(!visited[x]){
	dfs(adj, visited,  x, dest, paths, path);
      }
    }
  }

  visited[source]=false;
  path.pop_back();
}


void dfsUtil(vector<int>adj[], bool visited[], int source, int dest, vector<vector<int>>&paths, vector<int>&path){
  dfs(adj, visited, source, dest, paths, path);
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

  cout << endl;

  bool visited[V] = {false};
  int source = 0;
  int dest = 5;

  vector<vector<int>>paths;
  vector<int>path;

  dfsUtil(adj, visited, source, dest, paths, path);

  cout << paths.size() << endl;

  for(int i = 0; i<paths.size(); i++){
    cout << "path no = " << i << endl;
    for(int j = 0; j< paths[i].size(); j++){
      cout << paths[i][j] << " -> ";
    }

    cout << endl;
  }
  
  cout << endl;
  
  return 0;
}
