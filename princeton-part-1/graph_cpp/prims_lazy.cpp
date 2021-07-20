#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Graph{
#define p pair<double, pair<int,int>>
  int V, E;
  vector<pair<int, double>>*adj;

  priority_queue <p, vector<p>, greater<p>>pq;

  Graph(int V, int E){
    this->V = V;
    this->E = E;
    this->adj = new vector<pair<int, double>>[V];
  };

  void addEdge(int u, int v, double w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  };

  vector<pair<double, pair<int, int>>> getMST(){
    vector<pair<double, pair<int, int>>>mst_queue;
    bool marked[V] = {false};

    for (int v = 0; v < V; v++)     // run Prim from all vertices to
      if (!marked[v]) {};     // get a minimum spanning forest
    
    
    visit(0, marked);
    while(!pq.empty()){
      p min_weight_edge = pq.top();
      pq.pop();
      double weight = min_weight_edge.first;
      int u = min_weight_edge.second.first;
      int v = min_weight_edge.second.second;

      if(marked[u] && marked[v]){
	continue;
      }

      mst_queue.push_back({weight, {u, v}});

      if(!marked[u]){
	visit(u, marked);
      }
      if(!marked[v]){
	visit(v, marked);
      } 
    }
    return mst_queue;
  };

  void visit(int vertex, bool marked[]){
    marked[vertex] = true;
    for(auto x: adj[vertex]){
      int other = x.first;
      double weight = x.second;
      if(!marked[other]){
	pq.push({weight, {vertex, other}});
      }
    }
  };

};



int main(){
  int V = 8, E = 16;

  Graph graph(V, E);
  graph.addEdge(4, 5, 0.35);
  graph.addEdge(4, 7 , 0.37);
  graph.addEdge(5, 7, 0.28);
  graph.addEdge(0, 7, 0.16);
  graph.addEdge(1, 5, 0.32);
  graph.addEdge(0, 4, 0.38);
  graph.addEdge(2, 3, 0.17);
  graph.addEdge(1, 7, 0.19);
  graph.addEdge(0, 2, 0.26);
  graph.addEdge(1, 2, 0.36);
  graph.addEdge(1, 3, 0.29);
  graph.addEdge(2, 7, 0.34);
  graph.addEdge(6, 2, 0.40);
  graph.addEdge(3, 6, 0.52);
  graph.addEdge(6, 0, 0.58);
  graph.addEdge(6, 4, 0.93);

  vector<pair<double, pair<int, int>>> edges = graph.getMST();

  double mst_wt = 0;
  cout << "edges :- " << endl;
  for(int i = 0; i < edges.size(); i++){
    double weight = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    mst_wt += weight;

    cout << u << " - " << v << endl;
  }

  cout << "total mst weight is = " << mst_wt << endl;
  
  return 0;
}
