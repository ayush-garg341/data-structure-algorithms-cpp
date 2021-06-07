#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      int closest_sum = 0;
      int closest_max = INT_MAX; 
      for(int i=0; i<nums.size(); i++){
	int k = i+1;
	int j = nums.size()-1;
	while(k<j){
	  if(nums[i]+nums[k] == target - nums[j]){
	    return target;
	  }

	  else if(nums[i]+nums[k] < target-nums[j]){
	    if(abs(target - (nums[i] + nums[j] + nums[k])) < closest_max){
	      closest_max = abs(target - (nums[i] + nums[j] + nums[k]));
	      closest_sum = nums[i] + nums[j] + nums[k];
	    }
	    k++;
	  }
	  else{
	    if(abs(target - (nums[i] + nums[j] + nums[k])) < closest_max){
	      closest_max = abs(target - (nums[i] + nums[j] + nums[k]));
	      closest_sum = nums[i] + nums[j] + nums[k];
	    }
	    j--;
	  }
	}
      }

      
      return closest_sum;
    }
};

int main(){
  Solution soln;
  vector<int> nums = {-1,2,1,-4};
  int target = 1;
  int closest_sum = soln.threeSumClosest(nums, target);
  cout << "closest sum == " << closest_sum << "\n";
}
