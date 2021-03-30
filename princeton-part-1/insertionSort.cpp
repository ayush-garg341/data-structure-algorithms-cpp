// for the current ith element, check all the elements to left of it and exchange if smaller...

#include<iostream>
#include <vector>

using namespace std;

class InsertionSort{
  
public:
  void sort(vector<int>& nums){
    int array_size = nums.size();
    for(int i =0 ; i<array_size; i++){
      for(int j = i; j > 0; j--){
	if(isLess(nums[j], nums[j-1])){
	  exchange(nums, j, j-1);
	}
      }
      
    }

    printSorted(nums);
  }


  bool isLess(int a, int b){
    return a < b;
  }


  void exchange(vector<int>& nums, int largerPos, int smallerPos){
    int temp = nums[largerPos];
    nums[largerPos] = nums[smallerPos];
    nums[smallerPos] = temp;
  }

  void printSorted(vector<int>&nums){
    int array_size = nums.size();
    for(int i=0; i< array_size; i++){
      cout << "insertion sort element =====>>>>>> " << nums[i] << "\n";
    }
  }
};


int main(){
  InsertionSort insSort;
  vector <int> nums = {30, 5, 10, 4, 8, 5, 15};
  insSort.sort(nums);
  return 0;
}
