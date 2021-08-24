#include<iostream>
#include<vector>

using namespace std;


class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
      
      if(i < k-1){
	sum += arr[i];
      }
      else if(i == k-1){
	sum += arr[i];
	maxSum = max(sum, maxSum);
      }
      else{
	sum += arr[i] - arr[i-k];
	maxSum = max(sum, maxSum);
      }
    }
    return maxSum;
  }


  static int findMaxSumSubArrayTwo(int k, const vector<int>& arr) {
    int maxSum = 0;
    int window_sum = 0;
    int window_start = 0;

    for(int i = 0; i < arr.size(); i++){
      window_sum += arr[i];

      if( i >= k-1){
	maxSum = max(maxSum, window_sum);
	window_sum -= arr[window_start++];
      }
    }
    
    return maxSum;
  }
  
};


int main(){

  vector<int>nums = {2, 1, 5, 1, 3, 2};
  int k = 3;

  nums = {2, 3, 4, 1, 5};
  k = 2;
  
  MaxSumSubArrayOfSizeK *soln = new MaxSumSubArrayOfSizeK();

  cout << soln -> findMaxSumSubArray(k, nums) << endl;

  cout << soln -> findMaxSumSubArrayTwo(k, nums) << endl;

  delete soln;
  
  return 0;
}
