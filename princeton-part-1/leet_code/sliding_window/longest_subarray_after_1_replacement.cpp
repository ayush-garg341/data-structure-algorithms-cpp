#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    int index = 0;
    int maxRepeatingOnes = 0;

    for(int i = 0; i < arr.size(); i++){
      if(arr[i]==1){
	maxRepeatingOnes ++;
      }

      while(i - index + 1 - maxRepeatingOnes > k){
	if(arr[index]==1){
	  maxRepeatingOnes --;
	}
	index++;
      }
      maxLength = max(maxLength, i - index + 1);
    }
    
    return maxLength;
  }
};

int main(){
  vector<int> nums = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
  int k = 2;
  ReplacingOnes *soln = new ReplacingOnes();

  cout << soln -> findLength(nums, k) << endl;

  nums = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
  k = 3;

  cout << soln -> findLength(nums, k) << endl;
  
  delete soln;
  
  return 0;
}
