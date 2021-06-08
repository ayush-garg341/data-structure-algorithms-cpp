#include<iostream>
#include<vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int missing_pos = 0;
      unordered_map<int, int> umap;
      unordered_map<int, int>:: iterator itr;
      for(int i=0; i<nums.size(); i++){
	umap[nums[i]]++;
      }

      for (int i=0; i<=nums.size(); i++){
	int key = i+1;
	if (umap.find(key) == umap.end()){
	  missing_pos = key;
	  break;
	}
      }

      return missing_pos;
    }
};


int main(){
  Solution soln;
  vector<int> nums = {};
  int missing_pos = soln.firstMissingPositive(nums);
  cout << "misssing positive => " << missing_pos << "\n";
}
