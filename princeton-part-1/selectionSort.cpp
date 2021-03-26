#include<iostream>
#include <vector>

using namespace std;

class SelectionSort{

public:
  void sort(vector<int>& nums){
    int array_size = nums.size();
    for(int i =0 ; i<array_size; i++){
      int min = i;
      for(int j = i+1; j < array_size; j++){
	if(isLess(nums[j], nums[min])){
	  min = j;
	}
      }

      exchange(nums, i, min);
      
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
      cout << "element =====>>>>>> " << nums[i] << "\n";
    }
  }
};


int main(){
  SelectionSort selSort;
  vector <int> nums = {-10, -20, 30, 5, 10, 4, 8, -5, -15};
  selSort.sort(nums);
}
