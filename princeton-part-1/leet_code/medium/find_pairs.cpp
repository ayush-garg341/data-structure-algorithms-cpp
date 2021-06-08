#include<iostream>
#include<vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
      int count=0;
      unordered_map<int, int> umap;
      unordered_map<int, int>:: iterator itr;
      for(int i=0; i<nums.size(); i++){
	umap[nums[i]]++;
      }
      for (itr = umap.begin(); itr != umap.end(); itr++){
	int key = itr->first;
	int key_to_find = key - target;
	if (umap.find(key_to_find) == umap.end()){
	  continue;
	}
	else{
	  if(target==0){
	    if(itr->second >= 2)
	      count ++;
	  }
	  else{
	    count ++;
	  }
	}
      }
      
      return count;
    }
};


int main(){
  Solution soln;
  vector<int> nums = {1,3,1,5,4};
  int target = 0;
  int num_pairs = soln.findPairs(nums, target);
  cout << "num pairs" << num_pairs << "\n";
}
