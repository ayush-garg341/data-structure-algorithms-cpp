struct bst_node{
  char *key;
  int value;
  struct bst_node *left_tree;
  struct bst_node *right_tree;
};

int get(char *key);
struct bst_node* put(char *key, int value, struct bst_node *root);
