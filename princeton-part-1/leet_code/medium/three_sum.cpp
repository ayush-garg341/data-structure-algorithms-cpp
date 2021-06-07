#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> pairs;
      vector<int>pair;

      vector<vector<int>> triplets;
      vector<int>triplet;
      
      for(int i=0; i < nums.size(); i++){
	if(pair.size()==0){
	  pair.push_back(nums[i]);
	}
	else{
	  pair[0] = nums[i];
	  pair[2] = i;
	}
	if(i>=1 && nums[i]==nums[i-1]){
	  continue;
	}
	for(int j = i+1; j < nums.size(); j++){

	  if(j>=1 && nums[j]==nums[j-1]){
	    continue;
	  }
	  
	  if(pair.size()==1){
	    pair.push_back(nums[j]);
	    pair.push_back(i);
	    pair.push_back(j);
	  }
	  else{
	    pair[1] = nums[j];
	    pair[3] = j;
	  }
	  pairs.push_back(pair);
 	}
      }

      for(int k =0; k < pairs.size() ; k++){
	int sum_pair = - ( pairs[k][0] + pairs[k][1]);
	int pos = binarySearch(nums, 0, nums.size()-1, sum_pair);
	if(pos != -1 && pairs[k][2] != pos && pairs[k][3] != pos){
	  if(triplet.size()==0){
	    triplet.push_back(pairs[k][0]);
	    triplet.push_back(pairs[k][1]);
	    triplet.push_back(nums[pos]);
	  }
	  else{
	    triplet[0] = pairs[k][0];
	    triplet[1] = pairs[k][1];
	    triplet[2] = nums[pos];
	  }

	    
	  triplets.push_back(triplet);
	    
	}
      };

      return triplets;
    }

  int binarySearch(vector<int> &arr, int l, int r, int x)
  {
    if (r >= l) {
      int mid = l + (r - l) / 2;
      
      if (arr[mid] == x)
	return mid;
      
      if (arr[mid] > x)
	return binarySearch(arr, l, mid - 1, x);
      
      return binarySearch(arr, mid + 1, r, x);
    }  
    return -1;
  }
};

int main(){
  Solution soln;
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector <vector <int>> triplets = soln.threeSum(nums);

  for(int k= 0; k < triplets.size(); k++){
    cout << "[0] = " << triplets[k][0] << " [1] = " << triplets[k][1] << " [2] = " << triplets[k][2] << "\n";
  }
}
