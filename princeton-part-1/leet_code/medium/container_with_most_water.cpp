#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
      int maxArea = 0;
      int i = 0;
      int j = height.size() - 1;
      while(i<j){
	int area = 0;
	if(height[i] < height[j]){
	  area = (j-i) * height[i];
	  i++;
	}
	
	else if(height[i] > height[j]){
	  area = (j-i) * height[j];
	  j--;
	}
	else{
	  area = (j-i) * height[i];
	  i++;
	  j--;
	}

	if(area > maxArea){
	  maxArea = area;
	}
	
      }
      
      return maxArea;
      
    }
};


int main(){
  Solution soln;
  vector<int>height = {1,2,1};
  int maxArea = soln.maxArea(height);
  cout << "max area = " << maxArea << "\n";
}
