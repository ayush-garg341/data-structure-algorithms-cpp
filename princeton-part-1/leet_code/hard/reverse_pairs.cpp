#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  int reversePairs(vector<int>& nums) {
    int count = 0;
    int low = 0;
    int high = nums.size();
    int size = high;
    mergeSort(nums, low, high-1, size, count);
    //mergeSort(nums, low, high-1, size);
    
    return count;
  }

  void mergeSort(vector<int>&nums, int low, int high, int size, int &count){
    if(low < high){
      int mid = (low + high)/2;
      mergeSort(nums, low, mid, size, count);
      mergeSort(nums, mid+1, high, size, count);
      merge(nums, low, mid, high, size, count);
    }
  }

  void merge(vector<int>&nums, int low, int mid, int high, int size, int &count){
    //cout << "low = " << low << " mid = " << mid << " high = " << high << endl;

    // for(int z = 0; z < size; z++){
    //   cout << nums[z] << " ";
    // }

    // cout << endl;

    int l = low;
    int m = mid+1;
    while(l <= mid && m <=high){

      // cout << nums[l] << " " << nums[m] << endl;
      
      if((long long )nums[l] > (long long)2*nums[m]){
	count += (mid - l +1);
	m++;
      }
      else{
	l++;
      }
    }
    
    
    int auxArr[size];
    int k = 0;
    int i = low;
    int j = mid+1;

    while(i <= mid && j <= high){
      if(nums[j] < nums[i]){
	auxArr[k++] = nums[j];
	j++;
      }
      else{
	auxArr[k++] = nums[i];
	i++;
      }
    }

    while(i<=mid){
      auxArr[k++] = nums[i];
      i++;
    }

    while(j <= high){
      auxArr[k++] = nums[j];
      j++;
    }

    for(j = high; j>=low; j--){
      nums[j] = auxArr[--k];
    }

    for(int i = 0; i < size; i++){
      cout << nums[i] << " ";
    }

    cout << endl;
    
  }
  
};


int main(){
  vector<int> nums = {1,3,2,3,1};
  Solution soln;
  int count = soln.reversePairs(nums);
  cout << "count reverse paris = " << count << endl;
  return 0;
}


// Using the fact that left array will be sorted and right array will be sorted and computing the count .
// We use extra loops to print the output for debugging, sometime it gives TLE due to lasrge input printing to the console.
