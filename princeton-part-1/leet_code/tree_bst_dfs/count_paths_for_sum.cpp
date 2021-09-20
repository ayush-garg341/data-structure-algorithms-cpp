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

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    // TODO: Write your code here
    vector<int>currentPath;
    return countPathsRecursive(root, S, currentPath);
  }

    static int countPathsRecursive(TreeNode *root, int sum, vector<int>&currentPath){
        if(root == nullptr){
            return 0;
        }

        currentPath.push_back(root->val);
        int path_count = 0;
        int path_sum = 0;
        vector<int>:: reverse_iterator itr;
        for( itr = currentPath.rbegin(); itr != currentPath.rend(); ++itr){
            path_sum += *itr;

            if(path_sum == sum){
                path_count ++;
            }
        }

        path_count += countPathsRecursive(root->left, sum, currentPath);
        path_count += countPathsRecursive(root->right, sum, currentPath);


        currentPath.pop_back();

        return path_count;
    }

};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
  return 0;
}
