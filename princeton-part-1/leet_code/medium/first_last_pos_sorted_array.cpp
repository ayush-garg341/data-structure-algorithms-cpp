#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range;
    binarySearch(nums, 0, nums.size()-1, target, range);

    if(range.size()==0){
      range.push_back(-1);
      range.push_back(-1);
    }
    else if(range.size()==1){
      range.push_back(range[0]);
    }

    
    return range;
  }
  
  
  void binarySearch(vector<int> &arr, int l, int r, int x, vector<int> &range){
    if (r >= l) {
        int mid = l + (r - l) / 2;
       
        if (arr[mid] == x){
	  if(range.size()<2){
	    range.push_back(mid);
	    if(range.size()==2 && range[1] < range[0]){
	      int temp = range[0];
	      range[0] = range[1];
	      range[1] = temp;
	    }
	  }
	  else{
	    if(mid < range[0]){
	      range[0] = mid;
	    }
	    if(mid > range[1]){
	      range[1] = mid;
	    }
	  }
	}
	if(x <= arr[mid]){
	  binarySearch(arr, l, mid - 1, x, range);
	}
	if(x >= arr[mid]){
	   binarySearch(arr, mid + 1, r, x, range);
	 }
    }
  }
  
};

int main(){
  Solution soln;
  vector <int> nums = {1,2,3,4,5,7,9,10,11,12,13,14};
  int target = 8;
  vector <int> range = soln.searchRange(nums, target);
}
