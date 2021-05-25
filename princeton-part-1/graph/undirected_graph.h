struct adj_node{
  int value;
  struct adj_node *pointer_to_adj_node;
};


void add_edge(int source, int destination);

int degree(int vertex);

int maxDegree();

int num_of_edges();

double averageDegree();

void adjacent_vertex(int vertex);

void printGraph();
