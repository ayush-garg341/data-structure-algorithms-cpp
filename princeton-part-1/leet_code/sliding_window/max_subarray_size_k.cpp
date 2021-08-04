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
};


int main(){

  vector<int>nums = {2, 1, 5, 1, 3, 2};
  int k = 3;

  nums = {2, 3, 4, 1, 5};
  k = 2;
  
  MaxSumSubArrayOfSizeK *soln = new MaxSumSubArrayOfSizeK();

  cout << soln -> findMaxSumSubArray(k, nums) << endl;
  
  return 0;
}
