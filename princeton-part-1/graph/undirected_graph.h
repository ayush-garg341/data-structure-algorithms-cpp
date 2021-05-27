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

double averageDegree();

struct adj_node * adjacent_vertex(int vertex, int flag);

void printGraph();

struct graph_node * create_graph();

void dfs(struct adj_node *adj_node, int source, int marked[], int edge_to[]);

void printVisitedNodes(int marked[], int num_vertices);

void edgeToVertex(int edge_to[], int num_vertices, int levels[]);

int hasPathTo(int marked[], int vertex);

struct path_nodes * pathTo(int marked[], int source, int destination);

void bfs(int source, int marked[], int edge_to[], int levels[]);

void enqueue(int element);

int dequeue();

int isEmpty();

void printQueue();

void dfs_cc(int source, int marked[], int id[], int count);

void printCCNodes(int id[], int num_vertices);

void dfs_without_recusrion(int source, int marked[], int edge_to[]);

void push(int element);

int pop();

void printShortesRoute(int source, int dest, int edge_to[]);
