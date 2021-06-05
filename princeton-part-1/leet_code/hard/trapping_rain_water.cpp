#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int trap_water = 0;
      for(int i=0; i < height.size(); i++){
	int leftMax = 0;
	int rightMax = 0;
	for(int left = 0; left < i; left++){
	  if(height[left] > leftMax){
	    leftMax = height[left];
	  }
	}
	for(int right = i+1; right < height.size(); right++){
	  if(height[right] > rightMax){
	    rightMax = height[right];
	  }
	}
	int canHoldWater = min(leftMax, rightMax);
	int waterAtIndex = canHoldWater - height[i];
	if(waterAtIndex<=0){
	  trap_water+=0;
	}
	else{
	  trap_water += waterAtIndex;
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
