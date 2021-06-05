#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

      vector<int>products;
      int product = 1;
      bool zero_exist = false;
      int count_zeros = 0;
      for(int i = 0; i < nums.size(); i++){
	if(nums[i]!=0){
	  product *= nums[i];
	}
	else{
	  count_zeros++;
	  zero_exist = true;
	}
      }

      for(int i = 0; i < nums.size(); i++){
	if(nums[i]!=0 && zero_exist){
	  products.push_back(0);
	}
	else if(nums[i]!=0 && !zero_exist){
	  products.push_back(product/nums[i]);
	}
	else if(nums[i]==0 && count_zeros>1){
	  products.push_back(0);
	}
	else if(nums[i]==0){
	  products.push_back(product);
	}
      }

      return products;
    }
};


int main(){
  Solution soln;
  vector<int> nums = {0, 0};
  vector<int> g1 = soln.productExceptSelf(nums);
  for (auto it = g1.begin(); it != g1.end(); it++)
    cout << *it << " ";
}
