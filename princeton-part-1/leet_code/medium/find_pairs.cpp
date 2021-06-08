#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int target) {
      //sort(nums.begin(), nums.end());
      set<vector<int>> set_of_vectors;
      vector<int>pair;
      int count = 0;
      for(int i=0; i < nums.size(); i++){
	for(int j = i+1; j < nums.size(); j++){
	  if(abs(nums[i] - nums[j])==target){
	    if(pair.size()==0){
	      pair.push_back(nums[i]);
	      pair.push_back(nums[j]);
	    }
	    else{
	      pair[0] =  nums[i];
	      pair[1] =  nums[j];
	    }

	    if(set_of_vectors.count(pair)==0){
	      count += 1;
	      set_of_vectors.insert(pair);
	    }
	    
	  }
	}
	
      }
      return count;
    }
};


int main(){
  Solution soln;
  vector<int> nums = {1,2,3,4,5};
  int target = 1;
  int num_pairs = soln.findPairs(nums, target);
  cout << "num pairs" << num_pairs << "\n";
}
