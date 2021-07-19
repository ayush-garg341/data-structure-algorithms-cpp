#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int>iPair;

struct Graph{
  int V, E;
  vector<pair<int, iPair>>edges;

  Graph(int V, int E){
    this->V = V;
    this->E = E;
  }

  void addEdge(int u, int v, int w){
    edges.push_back({w, {u, v}});
  }

  int kruskalMST();
};


struct DisjointSets{
  int *parent, *rnk;
  int n;

  DisjointSets(int n){
    this->n = n;
    parent = new int[this->n];
    rnk = new int[this->n];

    for(int i=0; i < n; i++){
      parent[i] = i;
      rnk[i] = 0;
    }
  }

  int find(int u){
    if(u!=parent[u]){
      parent[u] = find(parent[u]);
    }

    return parent[u];
  }

  void merge(int u, int v){
    u = find(u), v = find(v);
    if(rnk[u] > rnk[v]){
      parent[v] = u;
    }
    else{
      parent[u] = v;
    }

    if(rnk[u] == rnk[v]){
      rnk[v]++;
    }
  }
  
};

int Graph::kruskalMST(){
  int mst_wt = 0;
  sort(edges.begin(), edges.end());
  DisjointSets ds(V);

  vector<pair<int, iPair>>::iterator it;
  for(it = edges.begin(); it!=edges.end(); it++){
    int u = it -> second.first;
    int v = it -> second.second;

    int set_u = ds.find(u);
    int set_v = ds.find(v);

    if(set_u!=set_v){
      cout << u << " - " << v << endl;
      mst_wt += it->first;
      ds.merge(set_u, set_v);
    }
  }

  return mst_wt;
};



int main(int argc, char* argv[]){
  int V=9, E=14;
  Graph graph(V, E);

  graph.addEdge(0, 1, 4);
  graph.addEdge(0, 7, 8);
  graph.addEdge(1, 2, 8);
  graph.addEdge(1, 7, 11);
  graph.addEdge(2, 3, 7);
  graph.addEdge(2, 5, 4);
  graph.addEdge(2, 8, 2);
  graph.addEdge(3, 4, 9);
  graph.addEdge(3, 5, 14);
  graph.addEdge(4, 5, 10);
  graph.addEdge(5, 6, 2);
  graph.addEdge(6, 7, 1);
  graph.addEdge(6, 8, 6);
  graph.addEdge(7, 8, 7);

  cout << graph.kruskalMST() << endl;

  return 0;
};
