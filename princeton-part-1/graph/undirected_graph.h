struct adj_node{
  int value;
  struct adj_node *pointer_to_adj_node;
};


struct graph_node{
  int vertices;
  struct adj_node **pointer_to_arr;
};

void add_edge(int source, int destination);

int degree(int vertex);

int maxDegree();

int num_of_edges();

double averageDegree();

struct adj_node * adjacent_vertex(int vertex);

void printGraph();

struct graph_node * create_graph();

void dfs(struct adj_node *adj_node, int source, int marked[], int edge_to[]);

void printVisitedNodes(int marked[], int num_vertices);

void edgeToVertex(int edge_to[], int num_vertices);
