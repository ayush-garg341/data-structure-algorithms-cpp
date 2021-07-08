#include<iostream>
using namespace std;

struct Node{
  int val;
  Node *next;
};

struct Edges{
  int src, dest;
};


class Graph{

  int N;
  
  Node * getAdjListNode(int dest, Node * head){
    Node* newNode = new Node;
    newNode -> val = dest;
    newNode -> next = head;
    return newNode;
  }

public:
  // An array of pointers to Node to represent the adjacency list
  Node **head;

  Graph(Edges edges[], int n, int N){
    head = new Node*[N]();
    this->N = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
      head[i] = nullptr;
    }

    for(int i = 0; i < n; i++){
      int src = edges[i].src;
      int dest = edges[i].dest;

      // make node adjacent to src
      Node* newNode = getAdjListNode(dest, head[src]);
      head[src] = newNode;


      // make node adjacent to dest
      newNode = getAdjListNode(src, head[dest]);
      head[dest] = newNode;
      
    }
  }

  // Destructor
  ~Graph() {
    for (int i = 0; i < N; i++) {
      delete[] head[i];
    }
    
    delete[] head;
  }
};


void printList(Node* ptr){
  while(ptr!=nullptr){
    cout << "-> " << ptr->val;

    ptr = ptr -> next;
    
  }

  cout << endl;
}


int main(int argc, char *arg[]){
  Edges edges[] = {
		   { 0, 1 }, { 1, 2 }, { 2, 0 },
		   { 3, 2 }, { 4, 5 }
  };

  int  N = 6 ; // total number of nodes in graph

  // calculate the total number of edges
  int n = sizeof(edges)/sizeof(edges[0]);

  // construct graph
  Graph graph(edges, n, N);

  for(int i=0; i < N; i++){
    cout << i;
    printList(graph.head[i]);
  }

  return 0;
  
}
