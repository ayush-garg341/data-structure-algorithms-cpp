#include<iostream>
#include<vector>

using namespace std;

int DAC_Max(vector<int> nums, int index, int n){
  if(index >= n-2){
    if(nums[index] > nums[index+1]){
      return nums[index];
    }
    else{
      return nums[index+1];
    }
  }

  int max = DAC_Max(nums, index+1, n);

  if(nums[index] > max){
    return nums[index];
  }
  else{
    return max;
  }
  
}


int DAC_Min(vector<int> nums, int index, int n){
  if(index >= n-2){
    if(nums[index] < nums[index+1]){
      return nums[index];
    }
    else{
      return nums[index+1];
    }
  }

  int min = DAC_Min(nums, index+1, n);

  if(nums[index] < min){
    return nums[index];
  }
  else{
    return min;
  }
}


int main(){
  vector<int> nums = {120, 34, 54, 32, 58, 11, 90};
  int n = sizeof(nums) / sizeof(nums[0]);
  int max, min;
  max = DAC_Max(nums, 0, n);
  min = DAC_Min(nums, 0, n);
  cout << "Maximum: " << max << endl;
  cout << "Minimum: " << min << endl;
  return 0;
}
