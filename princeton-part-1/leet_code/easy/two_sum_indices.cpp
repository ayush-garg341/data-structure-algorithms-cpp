#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>indices;
    unordered_map<int , int>umap;
    for(int i = 0 ; i < nums.size(); i++){
      umap[nums[i]] = i;
    }

    for(int i = 0; i<nums.size(); i++){
      int x = nums[i];
      int y = target - x;
      cout << x <<  " " << y << endl;
      if(umap.find(y)!=umap.end()){
	if(i!=umap[y]){
	  indices.push_back(i);
	  indices.push_back(umap[y]);
	  return indices;
	}
      }
    }

    return indices;
  }
};



int main(){
  Solution *soln = new Solution();
  vector<int>nums = {2,7,11,15};
  int target = 9;
  vector<int>indices;
  //indices = soln -> twoSum(nums, target);
  // for(int i = 0; i < indices.size(); i++){
  //   cout << indices[i] << endl;
  // }
  
  
  // nums = {3, 3};
  // target = 6;
  // indices = soln -> twoSum(nums, target);

  // for(int i = 0; i < indices.size(); i++){
  //   cout << indices[i] << endl;
  // }

  nums = {3, 2, 4};
  target = 6;
  indices = soln -> twoSum(nums, target);

  for(int i = 0; i < indices.size(); i++){
    cout << indices[i] << endl;
  }
  
  return 0;
}
