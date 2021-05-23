struct interval{
  int left_val, right_val;
};

struct ist_node{
  struct interval interval;
  int  max_so_far;
  struct ist_node *left_tree, *right_tree;
};

struct ist_node * insertInterval(struct interval interval, struct ist_node *root);

void updateMaxValForNode(struct ist_node *current_node, struct ist_node *latest_node);

void in_order_traversal(struct ist_node *root);

void searchIntersectingInterval(struct ist_node *root, struct interval interval);

int intersects(struct ist_node *x, struct interval interval);
