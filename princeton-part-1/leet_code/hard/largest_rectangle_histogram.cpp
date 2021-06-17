#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

      int maxArea = 0;
      
      unsigned int size = heights.size();
      
      vector<int> leftMax(size, -1);
      vector<int> rightMax(size, -1);

      for(int i=0; i<size-1; i++){
	int currentElement = heights[i];
	int j = i+1;
	while(heights[j]>=currentElement && j <= size - 1){
	  j++;
	}
	
	rightMax[i] = --j;
      }


      for(int i=size-1; i > 0; i--){
	int currentElement = heights[i];
	int j = i-1;
	while(heights[j]>=currentElement){
	  j--;
	}
	leftMax[i] = ++j;
      }

      for(int j = 0; j < size; j++){
	cout << " rightMax= " << rightMax[j] << " leftMax = " << leftMax[j] << "\n";
      }


      for(int i = 0; i<size; i++){
	int area = 0;
	if(leftMax[i] != -1 && rightMax[i] != -1){
	  area = heights[i] * (rightMax[i]-leftMax[i] +1);
	}
	else if(leftMax[i]==-1){
	  area = heights[i] * (rightMax[i] - i + 1);
	}
	else{
	  area = heights[i] * (i - leftMax[i] + 1);
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
  //vector<int> nums = {2,1,5,6,4,4,2,3};
  vector<int> nums = {2,4};
  int area = soln.largestRectangleArea(nums);
  cout << "area == " << area << "\n";
}
