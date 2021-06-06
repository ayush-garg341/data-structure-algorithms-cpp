#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range;
    binarySearch(nums, 0, nums.size()-1, target, range);

    if(range.size() == 2  && range[0] > range[1]){
      int temp = range[0];
      range[0] = range[1];
      range[1] = temp;
    }
    

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
	  }
	  else{
	    int larger;
	    int smaller;
	    int smallerPos;
	    int largerPos;
	    if(range[0] > range[1]){
	      larger = range[0];
	      smaller = range[1];
	      smallerPos = 1;
	      largerPos = 0;
	    }
	    else{
	      larger = range[1];
	      smaller = range[0];
	      smallerPos = 0;
	      largerPos = 1;
	    }

	    if(mid < smaller){
	      range[smallerPos] = mid;
	    }
	    if(mid > larger){
	      range[largerPos] = mid;
	    }
	  }
	}
        
	binarySearch(arr, l, mid - 1, x, range);
        binarySearch(arr, mid + 1, r, x, range);
    }
  }
  
};

int main(){
  Solution soln;
  vector <int> nums = {5,7,8,8,8,8,8,8,8,8,9,10};
  int target = 8;
  vector <int> range = soln.searchRange(nums, target);
}
