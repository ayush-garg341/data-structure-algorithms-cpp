#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      int V = passingFees.size();\
      bool visited[V] = {false};
      vector<pair<int, int>>adj[V];
      for(int i = 0; i < edges.size(); i++){
	addEdge(adj, edges[i][0], edges[i][1], edges[i][2]);
      }

      vector<vector<int>>paths;
      vector<int>path;

      dfs(adj, visited, 0, V-1, paths, path);

      
      for(int i = 0; i<paths.size(); i++){
	int time = 0;
	int cost = 0;
	for(int j = 0; j< paths[i].size(); j++){
	  if(time <= maxTime){
	    cost += passingFees[paths[i][j]];
	  }
	  else{
	    cost = -1;
	  }
	  
	}
      }

      return 0;
      
    }

  void dfs(vector<pair<int, int>>adj[], bool visited[], int source, int dest, vector<vector<int>>&paths, vector<int>&path){
    visited[source] = true;
    path.push_back(source);
    
    if(source==dest){
      paths.push_back(path);
    }
    else{
      for(auto x: adj[source]){
	if(!visited[x.first]){
	  dfs(adj, visited,  x.first, dest, paths, path);
	}
      }
    }
    
    visited[source]=false;
    path.pop_back();
  }

  void addEdge(vector<pair<int, int>>adj[], int u, int v, int time){
    adj[u].push_back(make_pair(v, time));
    adj[v].push_back(make_pair(u, time));
  }
  
};



int main(){
  int maxTime = 30;
  vector<vector<int>>edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
  vector<int> passingFees = {5,1,2,20,20,3};

  Solution soln;
  
  int mimCost = soln.minCost(maxTime, edges, passingFees);

  cout << "mim cost = " << mimCost << endl;

  return 0;

}
