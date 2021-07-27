#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution{
  typedef  pair<pair<int, int>, int> pi ;
public:
  int maxSumSubarray(vector<int>&nums){
    int high =  nums.size()-1;
    int sum = 0;
    pi indices_sum = maxSumSubarrayRecursive(nums, 0, high);

    cout << "i = " << indices_sum.first.first << " j = " << indices_sum.first.second << " sum = " << indices_sum.second << endl;
    
    return indices_sum.second;
  }

  pi maxSumSubarrayRecursive(vector<int>&nums, int low, int high){
    if(low == high){
      return {{low, high}, nums[low]};
    }
    else{
      int mid = (high + low)/2;
      pi left = maxSumSubarrayRecursive(nums, low, mid);
      pi right = maxSumSubarrayRecursive(nums, mid+1, high);
      pi crossing = crossingSum(nums, low, mid, high);

      if(left.second >= right.second && left.second >= crossing.second){
      	return left;
      }
      else if(right.second >= left.second && right.second >= crossing.second){
      	return right;
      }
      else{
      	return crossing;
      }
      
    }
  }

  pi crossingSum(vector<int>&nums, int low, int mid, int high){
    int left_sum = INT_MIN;
    int left_max = low;
    int sum = 0;
    for(int i = mid; i >= low; i--){
      sum = sum + nums[i];
      if(sum > left_sum){
	left_sum = sum;
	left_max = i;
      }
    }

    sum = 0;
    int right_sum = INT_MIN;
    int right_max = high;
    for(int i = mid+1; i <= high; i++){
      sum = sum + nums[i];
      if(sum > right_sum){
	right_sum = sum;
	right_max = i;
      }
    }

    return {{left_max, right_max}, left_sum + right_sum};
  }
  
};


int main(){
  vector<int>nums = {-2, -3, 4, -1, -2, 1, 5, -3};
  Solution *soln = new Solution();
  cout << soln->maxSumSubarray(nums) << endl;

  nums = {-2, -5, 6, -2, -2, 1, 5, 3};
  cout << soln->maxSumSubarray(nums) << endl;

  delete soln;
  
  return 0;
}
