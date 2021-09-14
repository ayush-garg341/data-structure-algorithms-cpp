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
  static vector<int> findMaxSum(TreeNode *root) {
    vector<vector<int>> allPaths;
    vector<int>results;
    int sum = 0;
    findMaxSumRecursive(root, results, sum);
    return results;
  }


private:
  
  static void findMaxSumRecursive(TreeNode* root, vector<int>&results,  int& sum){
    if(root == nullptr){
      return;
    }

    sum += root -> val;

    if(root->left == nullptr && root -> right == nullptr){
      results.push_back(sum);
    }
    else{
      // go to the left sub-tree
      findMaxSumRecursive(root->left , results, sum);

      // go to the right sub tree
      findMaxSumRecursive(root->right, results, sum);
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
  vector<int> results = FindAllTreePaths::findMaxSum(root);
  cout << "All paths sum, root to leaf " << endl;
  for(auto sum: results){
    cout << sum << " ";
  }

  cout << endl;
  
  return 0;
  
}
