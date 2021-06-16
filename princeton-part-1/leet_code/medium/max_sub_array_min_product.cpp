#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

const unsigned int M = 1000000007;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
      int maxVal=INT_MIN;

      vector<int> max_min_products;

      for(int i = 0; i< nums.size(); i++){
	int sum = 0;
	int minVal = nums[i];
	int prod = 0;
	for(int j = i; j < nums.size(); j++){
	  sum += nums[j];
	  if(nums[j] < minVal){
	    minVal = nums[j];
	  }
	  if(((minVal*sum) % M) > prod ){
	    prod = (minVal*sum) % M;
	    max_min_products.push_back(prod);
	  }
	}
      }
      
      for(int j = 0; j < max_min_products.size(); j++){
	if(max_min_products[j] > maxVal){
	  maxVal = max_min_products[j];
	}
      }
      
      return maxVal ;
      
    }
};

int main(){
  Solution soln;
  vector<int> nums = {1,1,3,2,2,2,1,5,1,5};
  int maxProduct = soln.maxSumMinProduct(nums);

  cout << "max product = " << maxProduct << "\n";

  return 0;
}
