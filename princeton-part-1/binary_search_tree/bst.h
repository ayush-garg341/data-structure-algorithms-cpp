struct bst_node{
  char *key;
  int value;
  struct bst_node *left_tree;
  struct bst_node *right_tree;
};

int get(char *key);
struct bst_node* putKeyValue(char *key, int value, struct bst_node *root);
struct bst_node* deleteKey(char *key, struct bst_node *root);
struct bst_node* min(struct bst_node *root);
struct bst_node* max(struct bst_node *root);

void level_order_traversal(struct bst_node* root);

void pushQueue(struct bst_node* x);
struct bst_node* popQueue();
int queueEmpty();

int check_if_bst(struct bst_node *root);

char* bst_in_order_traversal(struct bst_node* root, char *minimum_key);
