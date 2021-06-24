#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int size = nums.size();
    TreeNode *root = createBST(nums, 0, size-1);
    return root;
  }

  TreeNode* createBST(vector<int>nums, int low, int high){
    if(low > high){
      return NULL;
    }
    int mid = (low + high)/2 ;
    TreeNode *root = new TreeNode(nums[mid]);
    root -> left = createBST(nums, low, mid-1);
    root -> right = createBST(nums, mid+1, high);

    return root;
  }
  
  
};


int main(){
  vector<int> nums = {-10,-3,0,5,9};
  Solution soln;
  TreeNode *root = soln.sortedArrayToBST(nums);
  return 0;
}
