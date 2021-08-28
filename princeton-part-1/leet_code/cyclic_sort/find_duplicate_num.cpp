using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {


    // can be done with the help of slow and fast pointer without modifying input array and without using any extra space....
    
    int i = 0;
    while(i < nums.size()){
      int pos = nums[i]-1;

      if(i+1 != nums[i] && nums[i]!=nums[pos]){
	swap(nums[i], nums[pos]);
      }
      else{
	i++;
      }
    }

    for(int i = 0; i < nums.size(); i++){
      if(i+1!=nums[i]){
	return nums[i];
      }
    }
        
    return -1;
  }
};



int main(){

  FindDuplicate *fd = new FindDuplicate();
  vector<int>nums = {1, 4, 4, 3, 2};
  cout << fd -> findNumber(nums) << endl;

  nums = {2, 1, 3, 3, 5, 4};
  cout << fd -> findNumber(nums) << endl;

  nums = {2, 4, 1, 4, 4};
  cout << fd -> findNumber(nums) << endl;

  delete fd;
  
  return 0;
}
