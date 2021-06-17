#include<iostream>
#include<vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

      int maxArea = heights[0];
      
      int size = heights.size();
      
      vector<int> leftMax(size, 0);
      vector<int> rightMax(size, 0);

      calculateMax(heights, size, rightMax);
      
      reverse(heights.begin(), heights.end());
      
      calculateMax(heights, size, leftMax);
      
      reverse(leftMax.begin(), leftMax.end());

      
      for(int i = 0; i < size; i++){
        leftMax[i] = size - 1 - leftMax[i];
      }
      
      reverse(heights.begin(), heights.end());

      for(int i = 0; i<size; i++){
      	int area = heights[i] * ( abs(leftMax[i] - rightMax[i]) + 1 );
      	if(area > maxArea){
      	  maxArea = area;
      	}	
      } 
      return maxArea;
    }

  void calculateMax(vector<int>& heights, int size, vector<int>& auxVector){
    stack<int> st;
    int maxTop = -1;
      for( int i=0; i <= size-1; i++){	
	while(!st.empty() && heights[i] < heights[st.top()]){
	  int top = st.top();
	  if(top > maxTop){
	    maxTop = top;
	  }
	  
	  if(!st.empty()){
	    auxVector[top] = maxTop;
	    st.pop();
	  }
	  // else{
	  //   st.push(i);
	  // }
	}
	st.push(i);
      }

      while(!st.empty()){
	int top = st.top();
	st.pop();
	if(top > maxTop){
	  maxTop = top;
	}
	auxVector[top] = maxTop;
      }
  }
};


int main(){
  Solution soln;
  vector<int> nums = {2,1,5,6,4,4,2,3};
  // vector<int> nums = {2,4};
  // vector<int> nums = {5,5,1,7,1,1,5,2,7,6};
  int area = soln.largestRectangleArea(nums);
  cout << "area == " << area << "\n";
}
