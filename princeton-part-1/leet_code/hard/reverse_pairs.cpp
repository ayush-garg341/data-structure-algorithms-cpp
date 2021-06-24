#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  int reversePairs(vector<int>& nums) {
    int count = 0;
    for(int i=0; i <= nums.size()-2; i++){
      for(int j = i+1; j <= nums.size()-1; j++){
	if(nums[i] > 2*nums[j]){
	  count++;
	}
      }
    }
    return count;
  }
};


int main(){
  vector<int> nums = {2,4,3,5,1};
  Solution soln;
  int count = soln.reversePairs(nums);
  cout << "count reverse paris = " << count << endl;
  return 0;
}
