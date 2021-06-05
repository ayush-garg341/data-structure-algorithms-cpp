#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      
      vector<int>products;
      products.push_back(1);
      for(int i=1; i < nums.size(); i++){
	products.push_back(nums[i-1] * products[i-1]);
      }

      int backward = 1;
      for(int i=nums.size()-1; i >= 0; i--){
	products[i] = products[i] * backward;
	backward = backward * nums[i];
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
  cout << "\n";
}
