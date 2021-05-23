struct ist_node{
  int left_val, right_val, max_so_far;
  struct ist_node *left_tree, *right_tree;
};

struct ist_node * insertInterval(int low, int high, struct ist_node *root);

void updateMaxValForNode(struct ist_node *current_node, struct ist_node *latest_node);

void in_order_traversal(struct ist_node *root);

void searchIntersectingInterval(struct ist_node *root, int low, int high);

int intersects(struct ist_node *x, int low, int high);
