using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here

    int i = 0;
    while(i < nums.size()){
      int pos = nums[i];
      if(nums[i] < nums.size() && nums[i]!=i){
	swap(nums[i], nums[pos]);
      }
      else{
	i++;
      }
    }

    for(int i = 0; i < nums.size(); i++){
      if(i!=nums[i]){
	return i;
      }
    }
    
    return -1;
  }
  
};



int main(int argc, char* argv[]){

  MissingNumber *mn = new MissingNumber();
  
  vector<int>nums = {4, 0, 3, 1};
  int missing = mn -> findMissingNumber(nums);
  cout << missing << endl;

  nums = {8, 3, 5, 2, 4, 6, 0, 1};
  missing = mn -> findMissingNumber(nums);
  cout << missing << endl;
  
  return 0;
  
}
