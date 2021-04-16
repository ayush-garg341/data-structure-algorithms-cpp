// shell sort works as insertion sort when gap is 1..

#include<iostream>
#include <vector>

using namespace std;

class ShellSort{
public:
  void sort(vector<int>& nums){
    int array_size = nums.size();
    int gap = 1;
    while(gap < array_size/3){
      gap = 3*gap + 1;
    }
    while(gap >= 1){
      cout << "gap ===== " << gap << "\n";
      for(int i = gap ; i<array_size; i++){
	for(int j = i; j >= gap ; j=j-gap){
	  if(isLess(nums[j], nums[j-gap])){
	    exchange(nums, j, j-gap);
	  }
	}
      }

      gap = gap/3;
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
      cout << "Shell sort element =====>>>>>> " << nums[i] << "\n";
    }
  }
};


int main(){
  ShellSort shellSort;
  vector <int> nums = {30, 5, 10, 4, 8, 5, 15};
  shellSort.sort(nums);
  return 0;
}
