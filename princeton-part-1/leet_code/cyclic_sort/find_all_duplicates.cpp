using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;

    int i = 0;
    while(i < nums.size()){
      int pos = nums[i] - 1;
      if(i+1!=nums[i] && nums[i]!=nums[pos]){
	swap(nums[i], nums[pos]);
      }
      else{
	i++;
      }
    }

    for(int i = 0; i < nums.size(); i++){
      if(i+1!=nums[i]){
	duplicateNumbers.push_back(nums[i]);
      }
    }
    
    return duplicateNumbers;
  }
};


int main(){
  FindAllDuplicate *fad = new FindAllDuplicate();
  vector<int>nums = {3, 4, 4, 5, 5};

  vector<int>dup = fad -> findNumbers(nums);

  for(auto num: dup){
    cout << num << " ";
  }
  cout << endl;

  nums = {5, 4, 7, 2, 3, 5, 3};
  dup = fad -> findNumbers(nums);
  for(auto num: dup){
    cout << num << " ";
  }
  cout << endl;
  
  return 0;
}
