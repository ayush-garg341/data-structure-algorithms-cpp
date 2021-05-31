struct adj_node{
  int value;
  struct adj_node *pointer_to_adj_node;
};


struct graph_node{
  int vertices;
  struct adj_node **pointer_to_arr;
};


struct path_nodes{
  int node;
  struct path_nodes *next_node;
};


struct queue{
  int value;
  struct queue *next_node;
};


struct stack_node{
  int value;
  struct stack_node *next_node;
};


void add_edge(int source, int destination);

int degree(int vertex);

int maxDegree();

int num_of_edges();

struct adj_node * adjacent_vertex(int vertex, int flag);

void printGraph();

struct graph_node * create_graph();

void dfs_directed(int source, int marked[], int edge_to[]);

void printVisitedNodes(int marked[], int num_vertices);

void edgeToVertex(int edge_to[], int num_vertices, int levels[]);

void bfs_directed(int source, int marked[], int edge_to[], int levels[]);

void enqueue(int element);

int dequeue();

int isEmpty();

void printQueue();
