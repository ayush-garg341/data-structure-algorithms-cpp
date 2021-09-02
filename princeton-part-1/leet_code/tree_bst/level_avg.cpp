using namespace std;

#include <iostream>
#include <queue>

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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
      int size = q.size();
      int count = 0;
      double sum = 0;
      while(size != 0){
	TreeNode* front = q.front();
	count += 1;
	sum += front->val;
	q.pop();
	size--;
	if(front->left!=nullptr){
	  q.push(front->left);
	}
	if(front->right!=nullptr){
	  q.push(front->right);
	}
      }

      result.push_back( double( sum / count ));
      
    }
    
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}


// similar and easy problem
// Find the largest value on each level of a binary tree.
