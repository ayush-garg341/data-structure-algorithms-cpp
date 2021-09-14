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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    // int totalPathsSum = 0;
    // TODO: Write your code here
    // vector<vector<int>>allPaths;
    // vector<int>currentPath;
    // findAllPathsRecursive(root, currentPath, allPaths);

    
    // for(auto vec: allPaths){
    //   int power = 1;
    //   int num = 0;
    //   for(int i = vec.size()-1; i >= 0; i--){
    // 	num += vec[i] * power;
    // 	power *= 10;
    //   }

    //   totalPathsSum += num;
    // }

    
    
    // return totalPathsSum;

    return findAllPathNumberSum(root, 0);
  }


private:
  static void findAllPathsRecursive(TreeNode* root, vector<int>& currentPath, vector<vector<int>>&allPaths){
    if(root == nullptr){
      return;
    }

    currentPath.push_back(root -> val);
    
    if(root->left == nullptr && root->right == nullptr){
      allPaths.push_back(currentPath);
    }
    else{
      findAllPathsRecursive(root->left, currentPath, allPaths);

      findAllPathsRecursive(root->right, currentPath, allPaths);
    }
    
    currentPath.pop_back();
  }

  static int findAllPathNumberSum(TreeNode* root, int pathSum){
    if(root == nullptr){
      return 0;
    }

    pathSum = 10*pathSum + root -> val;

    if(root->left == nullptr && root -> right == nullptr){
      return pathSum;
    }

    return findAllPathNumberSum(root->left, pathSum) + findAllPathNumberSum(root-> right, pathSum);
    
  }
  
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
