#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
  int missingNumber(vector<int>nums){
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
      cout << nums[i] << " ";
    }
    cout << endl;

    int low = 0;
    int high = nums.size() - 1;
    while(low < high){

      int mid = (low + high)/2;

      cout << " low = " << low << " mid = " << mid << " high = " << high << endl;
      
      if(nums[low]-low != nums[mid]-mid){
	high = mid;
      }
      else if(nums[high]-high != nums[mid]-mid){
	low = mid + 1;
      }
      else{
	return low + 1;
      }
      
    }

    return low + 1;
    
  }
};


int main(){
  Solution *soln = new Solution();
  vector<int>nums = {2, 4, 3, 6, 1, 5, 8};
  //vector<int>nums = {};
  cout << soln -> missingNumber(nums) << endl;
  return 0;
}
