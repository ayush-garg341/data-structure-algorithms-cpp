using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {

    sort(arr.begin(), arr.end());
    int closeSum = numeric_limits<int>::max();

    int actual_sum = 0;
    
    for(int i = 0; i < arr.size(); i++){

      int j = i+1;

      int k = arr.size()-1;

      while(j < k){
	int sum = arr[i] + arr[j] + arr[k];
	int diffSum = abs(targetSum - sum);
	if(diffSum==0){
	  return sum;
	}
	else if(sum > targetSum){
	  if(diffSum < closeSum){
	    closeSum = diffSum;
	    actual_sum = sum;
	  }
	  k--;
	  
	}
	else{
	  if(diffSum < closeSum){
	    closeSum = diffSum;
	    actual_sum = sum;
	  }
	  j++;
	  
	}
      }
      
    }
    
    return actual_sum;
  }
};


int main(){
  TripletSumCloseToTarget *trip = new TripletSumCloseToTarget();
  vector<int>nums = {-2, 0, 1, 2};
  int target = 2;
  cout << trip -> searchTriplet(nums, target) << endl;

  nums = {-3, -1, 1, 2};
  target = 1;
  cout << trip -> searchTriplet(nums, target) << endl;

  nums = {1, 2, 3, 4};
  target = 6;
  cout << trip -> searchTriplet(nums, target) << endl;
  
  return 0;
}
