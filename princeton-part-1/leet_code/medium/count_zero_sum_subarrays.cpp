#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
  int countZeroSumSubArrays(vector<int>&nums){
    unordered_map <int, int>umap;
    int size = nums.size();
    int i = -1;
    umap[0] = 1;
    int sum = 0;
    int count = 0;
    cout << i << " " << nums.size()-1 << endl;
    while(i < size - 1){
      i++;
      sum += nums[i];
      if(umap.end() != umap.find(sum)){
	count += umap[sum];
	umap[sum]++;
      }
      else{
	umap[sum] = 1;
      }
    }

    return count;
  }
};

int main(){
  vector<int>nums = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
  Solution soln;
  int num = soln.countZeroSumSubArrays(nums);
  cout << num << endl;
  return 0;
}
