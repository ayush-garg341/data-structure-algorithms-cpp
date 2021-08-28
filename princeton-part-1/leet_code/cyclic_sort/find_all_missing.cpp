using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    
    int i = 0;
    while(i < nums.size()){

      int pos = nums[i] - 1;
      
      if(i+1!=nums[i] && nums[pos]!=nums[i]){
	swap(nums[i], nums[pos]);
      }
      else{
	i++;
      }
    }

    cout << "original nums" << endl;

    for(int i = 0; i < nums.size(); i++){

      cout << nums[i] << " ";
      
      if(nums[i]!=i+1){
	missingNumbers.push_back(i+1);
      }
    }

    cout << endl;
    
    return missingNumbers;
  }
};


int main(){
  AllMissingNumbers *amn = new AllMissingNumbers();
  vector<int>nums = {2, 4, 1, 2};
  vector<int>missing = amn->findNumbers(nums);

  cout << "missing nums" << endl;
  
  for(auto num:missing){
    cout << num << " ";
  }
  cout << endl;
  
  nums = {2, 3, 2, 1};
  missing = amn->findNumbers(nums);

  cout << "missing nums" << endl;
  
  for(auto num:missing){
    cout << num << " ";
  }

  cout << endl;

  nums = {2, 3, 1, 8, 2, 3, 5, 1};
  missing = amn -> findNumbers(nums);

  cout << "missing nums" << endl;
  
  for(auto num:missing){
    cout << num << " ";
  }

  cout << endl;
  
  return 0;
}
