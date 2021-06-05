#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int trap_water = 0;
      int left = 0;
      int right = 0;
      int low = 0;
      int hi = height.size() - 1;

      while(low < hi){
	left = max(left, height[low]);
	right = max(right, height[hi]);

	cout << "left max = " << left << "\n";
	cout << "right max = " << right << "\n";

	if(left > right){
	  if(right - height[hi]<=0){
	    trap_water += 0;
	  }
	  else{
	    trap_water += right - height[hi];
	  }
	  hi--;
	}
	else{
	  if(left - height[low] <= 0){
	    trap_water += 0;
	  }
	  else{
	    trap_water += left - height[low];
	  }
	  
	  low++;
	}
	
	
      }
      

      return trap_water;
      
    }
};

int main(){
  Solution soln;
  vector<int> height = {4,2,0,3,2,5};
  int max_water = soln.trap(height);
  cout << "max water =" << max_water << "\n";
}
