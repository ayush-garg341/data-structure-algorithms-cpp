#include<iostream>
#include<limits>
#include<vector>

// #include<climits>
// INT_MIN, INT_MAX

using namespace std;

class Solution{
public:
  vector<int> threeLargest(vector<int>nums){
    int mim = numeric_limits<int>::min();
    vector<int>threeLar{mim, mim, mim};

    for(int i = 0; i < nums.size(); i++){
      if(nums[i] >= threeLar[2]){
	setLargestNumbers(threeLar, 2, nums[i]);
      }
      else if(nums[i] >= threeLar[1]){
	setLargestNumbers(threeLar, 1, nums[i]);
      }
      else if(nums[i] >= threeLar[0]){
	setLargestNumbers(threeLar, 0, nums[i]);
      }
    }

    return threeLar;
  }

  void setLargestNumbers(vector<int>&threeLar, int index, int num){

    // below commented code will give wrong results think about it.......
    // for(int i = index - 1; i >= 0; i--){
    //   threeLar[i] = threeLar[i+1];
    // }
    // threeLar[index] = num;

    
    for(int i = 0; i < index; i++){
      threeLar[i] =  threeLar[i+1];
    }
    threeLar[index] = num;
  }
  
};


int main(){

  Solution *soln = new Solution();

  vector<int>nums = {5, 8, 3, 4, 1, 7, 6, 9, 0};

  // nums = {3, 1, 2};
  
  vector<int>threeLar = soln -> threeLargest(nums);

  for(auto num:threeLar){
    cout << num << " ";
  }

  cout << endl;

  delete soln;
  
  return 0;
}
