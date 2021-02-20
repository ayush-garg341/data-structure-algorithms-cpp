#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ThreeSum{
public:
  void threeSum(vector<int>& nums){
    int array_size = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<array_size;i++){
      int current_element = nums[i];
      int j = i+1;
      int k = array_size - 1;
      while(j<k){
	int sum = current_element + nums[j] + nums[k];
	if(sum == 0){
	  cout << "three numbers === " << current_element << ", " << nums[j] << ", " << nums[k] << endl;
	  j++;
	  k--;
	}
	else if(sum > 0){
	  k--;
	}
	else {
	  j++;
	}
      }
    }
    
  }
};


int main(){
  ThreeSum threesum;
  vector <int> nums = {-10, -20, 30, 5, 10, 4, 8, -5, -15};
  threesum.threeSum(nums);
}
