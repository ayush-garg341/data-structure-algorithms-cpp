using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class FindAllTreePaths {
 public:
  static int findMaxSum(TreeNode *root) {
    vector<vector<int>> allPaths;
    int max_sum = 0;
    int sum = 0;
    findMaxSumRecursive(root, max_sum, sum);
    return max_sum;
  }


private:
  
  static void findMaxSumRecursive(TreeNode* root, int& max_sum,  int& sum){
    if(root == nullptr){
      return;
    }

    sum += root -> val;

    if(root->left == nullptr && root -> right == nullptr){
      max_sum = max(max_sum, sum);
    }
    else{
      // go to the left sub-tree
      findMaxSumRecursive(root->left , max_sum, sum);

      // go to the right sub tree
      findMaxSumRecursive(root->right, max_sum, sum);
    }

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    sum -= root -> val;
    
  }
  
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int result = FindAllTreePaths::findMaxSum(root);
  cout << "Max Sum root to leaf " << result << endl;

  return 0;
  
}
