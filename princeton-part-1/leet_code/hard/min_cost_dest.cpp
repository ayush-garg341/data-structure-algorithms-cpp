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

      vector<vector<pair<pair<int, int>, int>>>paths;
      vector<pair<pair<int, int>, int>>path;

      int time = 0;
      dfs(adj, visited, 0, V-1, paths, path, time, passingFees, maxTime);

      // int mimCost = INT_MAX;
      // for(int i =0; i < paths.size(); i++){
      // 	//cout << "path no = " << i+1 << endl;
      // 	int path_time = 0;
      // 	int cost = 0;
      // 	for(int j = 0; j < paths[i].size(); j++){
      // 	  //cout << " ( " << paths[i][j].first << " " << paths[i][j].second << " ) ";
      // 	  path_time += paths[i][j].second;
      // 	  cost += passingFees[paths[i][j].first];
      // 	}

      // 	if(path_time <= maxTime){
      // 	  mimCost = min(mimCost, cost);
      // 	}
      // 	cout << endl;
      // }

      // return mimCost==INT_MAX?-1:mimCost;

      if(paths.size()==0){
	return -1;
      }

      else{
	vector<pair<pair<int, int>, int>>path = paths[0];
	int cost = path[path.size()-1].second;
	return cost;
      }
      
    }

  void dfs(vector<pair<int, int>>adj[], bool visited[], int source, int dest, vector<vector<pair<pair<int, int>, int>>>&paths, vector<pair<pair<int, int>, int>>&path, int time, vector<int>&passingFees, int maxTime){
    
    visited[source] = true;
    if(path.size()==0){
      path.push_back(make_pair(make_pair(source, time), passingFees[source]));
    }
    else{
      int size = path.size();
      pair<pair<int, int>, int>latest_pair = path[size-1];
      int new_time = latest_pair.first.second + time;
      int cost = latest_pair.second + passingFees[source];
      if(new_time <= maxTime){
	path.push_back(make_pair(make_pair(source, new_time), cost));
      }
      else{
	path.push_back(make_pair(make_pair(source, new_time), cost));
	visited[source]=false;
	path.pop_back();
	return;
      }
    }
    
    if(source==dest){
      cout << source << " " << dest << endl;
      if(paths.size()==0){
	paths.push_back(path);
      }
      else{
	int size = path.size();
	pair<pair<int, int>, int>latest_pair = path[size-1];
	int cost = latest_pair.second;

	int paths_size = paths.size();
	vector<pair<pair<int, int>, int>>last_pair = paths[paths_size-1];
	int last_pair_cost = last_pair[last_pair.size()-1].second;
	if(cost < last_pair_cost){
	  paths[0] = path;
	}
      }
    }
    else{
      for(auto x: adj[source]){
	if(!visited[x.first]){
	  dfs(adj, visited,  x.first, dest, paths, path, x.second, passingFees, maxTime);
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
  int maxTime = 29;
  vector<vector<int>>edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
  vector<int> passingFees = {5,1,2,20,20,3};

  Solution soln;
  
  int mimCost = soln.minCost(maxTime, edges, passingFees);

  cout << "mim cost = " << mimCost << endl;

  return 0;

}



// can be improved a bit.....
