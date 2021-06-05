#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int forward[nums.size()];
      int backward[nums.size()];
      vector<int>products;
      for(int i=0; i < nums.size(); i++){
	if(i==0){
	  forward[i] = 1;
	}
	else{
	  forward[i] = nums[i-1] * forward[i-1];
	}

	cout << "i = " << i << " forward[i] = " << forward[i] << "\n";
      }

      for(int i=nums.size()-1; i >= 0; i--){
	if(i==nums.size()-1){
	  backward[i] = 1;
	}
	else{
	  backward[i] = nums[i+1] * backward[i+1];
	}
	cout << "i = " << i << " backward[i] = " << backward[i] << "\n";
      }

      for(int i = 0; i < nums.size(); i++){
	products.push_back(forward[i] * backward[i]);
      }

      return products;
    }
};


int main(){
  Solution soln;
  vector<int> nums = {1,2,3,4};
  vector<int> g1 = soln.productExceptSelf(nums);
  for (auto it = g1.begin(); it != g1.end(); it++)
    cout << *it << " ";
}
