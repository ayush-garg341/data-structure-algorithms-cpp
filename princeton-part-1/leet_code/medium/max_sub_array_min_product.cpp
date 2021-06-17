#include<iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>

using namespace std;

const unsigned int M = 1000000007;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
      
      int size = nums.size();

      unsigned long long maxProduct = 0;
      
      vector<int>prefix_sum(size+1, 0);
      
      stack<int> st;
      
      for(int i=0; i<size; i++){
	prefix_sum[i+1] = prefix_sum[i] + nums[i];
      }

      nums.push_back(0);

      size = nums.size();

      for(int i = 0; i < size; i++){
	while(!st.empty() && nums[i] < nums[st.top()]){
	  int top = st.top();
	  st.pop();
	  if(st.empty()){
	    maxProduct = max(maxProduct,  (unsigned long long)prefix_sum[i]*nums[top]);
	  }
	  else{
	    unsigned long long sum = prefix_sum[i] - prefix_sum[st.top()+1];
	    maxProduct = max(maxProduct,  (unsigned long long)sum*nums[top]);
	  }
	}
	st.push(i);
	
      }
      
      return maxProduct % M ;
      
    }
};

int main(){
  Solution soln;
  // vector<int> nums = {1,1,3,2,2,2,1,5,1,5};
  // vector<int> nums = {1,2,3,2};
  vector<int> nums = {3,1,5,6,4,2};
  int maxProduct = soln.maxSumMinProduct(nums);

  cout << "max product = " << maxProduct << "\n";

  return 0;
}
