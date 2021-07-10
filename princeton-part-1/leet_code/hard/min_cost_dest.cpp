#include<iostream>
#include<vector>
#include <climits>

using namespace std;

class Solution{
public:
  struct Node{
    int val;
    int time;
    Node *next;
  };
  
  int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees){
    int num_nodes = passingFees.size();
    int num_edges = sizeof(edges)/sizeof(edges[0]);

    this->maxTime = maxTime;
    this->passingFees = passingFees;
    
    for (int i = 0; i < num_nodes; i++) {
      this->head[i] = nullptr;
    }

    for(int i = 0; i < num_edges; i++){
      int src = edges[i][0];
      int dest = edges[i][1];

      // make node adjacent to src
      Node* newNode = getAdjListNode(dest, edges[i][2], head[src]);
      head[src] = newNode;


      // make node adjacent to dest
      newNode = getAdjListNode(src, edges[i][2], head[dest]);
      head[dest] = newNode; 
    }

    int source = 0;
    int dest = num_nodes - 1;

    this->dest = dest;

    Node* headAdjSource = getAdjNodes(source);

    int minCost = INT_MAX;
    int time = 0;
    int cost = 0;
    while(headAdjSource!=nullptr){
      time += headAdjSource->time;
      cost += passingFees[0];
      int  returnCost = dfs(headAdjSource->val, time, cost);
      if(returnCost!=-1){
	minCost = min(minCost, cost+returnCost);
      }
    }

    return minCost == INT_MAX ? -1 : minCost;
    
  }

private:

  Node **head;
  int maxTime;
  int dest;
  vector<int>passingFees;
  
  
  Node * getAdjListNode(int dest, int time, Node * head){
    Node* newNode = new Node;
    newNode -> val = dest;
    newNode -> time = time;
    newNode -> next = head;
    return newNode;
  }
  
  Node* getAdjNodes(int v){
    return this->head[v];
  }

  int dfs(int w, int time, int cost){
    if(time > this->maxTime){
      return -1;
    }
    if(w!=this->dest){
      cost += this->passingFees[w];
      Node* headAdjSource = getAdjNodes(w);
      while(headAdjSource!=nullptr){
	time+=headAdjSource->time;
	dfs(headAdjSource->val, time, cost);
      }
      headAdjSource = headAdjSource->next;
    }
    return cost;
  }
  
};


int main(int argc, char* argv[]){
  int maxTime = 30;
  vector<vector<int>>edges = { {0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15} };
  vector<int>passingFees = {5,1,2,20,20,3};
  
  // int num_nodes = passingFees.size();
  // int num_edges = sizeof(edges)/sizeof(edges[0]);
  
  Solution soln;

  int cost = soln.minCost(maxTime, edges, passingFees);

  cout << cost << endl;
    
  return 0;
}
