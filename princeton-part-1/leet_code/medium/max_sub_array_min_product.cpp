#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

const unsigned int M = 1000000007;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      unsigned long long max_min_prod = 0;

      int i = nums.size()-1;
      int sum = 0;
      
      while(i>=0){
	sum += nums[i];
	if(nums[i]*sum > max_min_prod){
	  max_min_prod = nums[i]*sum;
	}
	else {
	  break;
	}
	i--;
      }

      cout << "max product = " << max_min_prod << "\n";
      
      return max_min_prod % M ;
      
    }
};

int main(){
  Solution soln;
  vector<int> nums = {3,1,5,6,4,2};
  int maxProduct = soln.maxSumMinProduct(nums);

  cout << "max product = " << maxProduct << "\n";

  return 0;
}
