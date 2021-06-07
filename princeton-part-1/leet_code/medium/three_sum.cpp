#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> triplets;
      sort(nums.begin(), nums.end());

      set<vector<int>> set_of_vectors;
      vector<int>triplet;
      
      for(int i=0; i<nums.size(); i++){
	int k = i+1;
	int j = nums.size()-1;
	while(k<j){
	  if(nums[i]+nums[k] == -nums[j]){
	    if(triplet.size()==0){
	      triplet.push_back(nums[i]);
	      triplet.push_back(nums[k]);
	      triplet.push_back(nums[j]);
	    }
	    else{
	      triplet[0] =  nums[i];
	      triplet[1] =  nums[k];
	      triplet[2] =  nums[j];
	    }

	    if(set_of_vectors.count(triplet)==0){
	      set_of_vectors.insert(triplet);
	    }

	    k++;
	    j--;
	  }

	  else if(nums[i]+nums[k] < -nums[j]){
	    k++;
	  }
	  else{
	    j--;
	  }
	}
      }

      for (auto it = set_of_vectors.begin(); it != set_of_vectors.end(); it++) {
        triplets.push_back(*it);
      } 
      
      return triplets;
    }
};

int main(){
  Solution soln;
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector <vector <int>> triplets = soln.threeSum(nums);
  for(int i=0; i<triplets.size(); i++){
    cout << triplets[i][0] << ", " << triplets[i][1] << ", " << triplets[i][2] << "\n";
  }
}
