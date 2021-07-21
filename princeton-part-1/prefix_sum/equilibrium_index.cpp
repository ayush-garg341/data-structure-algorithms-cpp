#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  int getEqbIndex(vector<int>&nums){
    for(int i = 1; i < nums.size(); i++){
      nums[i] += nums[i-1];
    }

    for(int i = 1; i < nums.size() - 1; i++){
      if(nums[i-1] ==  ( nums[nums.size()-1] - nums[i])){
	return i;
      }
    }

    return -1;
    
  }
};

int main(){
  vector<int>nums = {-7, 1, 5, 2, -4, 3, 0};
  Solution soln;
  int index = soln.getEqbIndex(nums);
  cout << index << endl;
  return 0;
}
