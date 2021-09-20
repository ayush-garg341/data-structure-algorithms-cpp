#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    // TODO: Write your code here
    int index = 0;
    int size = sequence.size();
    bool exist = findPathRecursive(root, sequence, size, index);
    return exist;
  }


    static bool findPathRecursive(TreeNode *root, const vector<int> &sequence, int size, int index){
        if(root == nullptr){
            return false;
        }

        if(index >= size || sequence[index]!=root->val){
            return false;
        }

        if(root->left == nullptr && root->right == nullptr && size-1 == index){
            return true;
        }

        return findPathRecursive(root->left, sequence, size, index + 1) || findPathRecursive(root->right, sequence, size, index + 1);
        
        
    }

};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  vector<int>inp;
  inp.push_back(1);
    inp.push_back(0);
    inp.push_back(7);
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, inp)
       << endl;

    vector<int>inp2;
    inp2.push_back(1);
    inp2.push_back(1);
    inp2.push_back(6);
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, inp2)
       << endl;

       return 0;
}
