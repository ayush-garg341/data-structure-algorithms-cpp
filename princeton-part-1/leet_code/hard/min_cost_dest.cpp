#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      int V = passingFees.size();
      bool visited[V] = {false};
      vector<pair<int, int>>adj[V];
      for(int i = 0; i < edges.size(); i++){
	addEdge(adj, edges[i][0], edges[i][1], edges[i][2]);
      }

      vector<vector<pair<int, int>>>paths;
      vector<pair<int, int>>path;

      int time = 0;
      dfs(adj, visited, 0, V-1, paths, path, time);

      int mimCost = INT_MAX;
      for(int i =0; i < paths.size(); i++){
	//cout << "path no = " << i+1 << endl;
	int path_time = 0;
	int cost = 0;
	for(int j = 0; j < paths[i].size(); j++){
	  //cout << " ( " << paths[i][j].first << " " << paths[i][j].second << " ) ";
	  path_time += paths[i][j].second;
	  cost += passingFees[paths[i][j].first];
	}

	if(path_time <= maxTime){
	  mimCost = min(mimCost, cost);
	}
	cout << endl;
      }

      return mimCost==INT_MAX?-1:mimCost;
      
    }

  void dfs(vector<pair<int, int>>adj[], bool visited[], int source, int dest, vector<vector<pair<int, int>>>&paths, vector<pair<int, int>>&path, int time){
    visited[source] = true;
    path.push_back(make_pair(source, time));
    
    if(source==dest){
      paths.push_back(path);
    }
    else{
      for(auto x: adj[source]){
	if(!visited[x.first]){
	  dfs(adj, visited,  x.first, dest, paths, path, x.second);
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
  int maxTime = 25;
  vector<vector<int>>edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
  vector<int> passingFees = {5,1,2,20,20,3};

  Solution soln;
  
  int mimCost = soln.minCost(maxTime, edges, passingFees);

  cout << "mim cost = " << mimCost << endl;

  return 0;

}
