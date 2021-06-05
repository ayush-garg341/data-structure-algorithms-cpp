#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
      int maxArea = 0;
        int area = 0;
        int size = height.size();
        
        for(int i=0; i < size; i++){
            for(int j=i; j < size; j++){
	      area = (j-i) * min(height[i], height[j]);
	      if(area > maxArea){
		maxArea = area;
	      }
            }
            
        }
    
      return maxArea;
      
    }
};


int main(){
  Solution soln;
  vector<int>height = {1,8,6,2,5,4,8,3,7};
  int maxArea = soln.maxArea(height);
  cout << "max area = " << maxArea << "\n";
}
