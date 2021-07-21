/*
  Consider an array of size n with all initial values as 0. Perform the given ‘m’ add operations from index ‘a’ to ‘b’ and evaluate the highest element in the array. An add operation adds 100 to all elements from a to b (both inclusive). 
 */

#include<iostream>
#include<vector>
using namespace std;

#define pi pair<int, int>

class Solution{
public:
  int maxElement(vector<int>&nums, vector<pi>indices){
    for(int i= 0; i < indices.size(); i++){
      int a = indices[i].first;
      int b = indices[i].second;

      nums[a-1] = nums[a-1] + 100;
      nums[b] = nums[b] - 100;
      
    }

    int max_element = nums[0];

    for(int i = 1; i < nums.size(); i++){
      nums[i] += nums[i-1];
      if(nums[i] > max_element){
	max_element = nums[i];
      }
    }

    return max_element;
    
  };
};


int main(){
  Solution soln;
  vector<int> nums = {0, 0, 0, 0, 0};
  vector<pi>indices = {{2, 4}, {1, 3}, {1, 2}};
  int maxVal  = soln.maxElement(nums, indices);

  cout << maxVal << endl;
  
  return 0;
}
