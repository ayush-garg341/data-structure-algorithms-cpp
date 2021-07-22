#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int>umap;
    int size = nums.size();
    int i = -1;
    umap[0] = 1;
    int sum = 0;
    int count = 0;
    while(i < size-1){
      i++;
      sum += nums[i];
      if(umap.find(sum-k)!=umap.end()){
	count += umap[sum-k];
      }

      umap[sum]++;
    }
    

    return count;
  }
};

int main(){
  vector<int>nums = {1,1,1};
  int k = 2;
  Solution soln;
  cout << soln.subarraySum(nums, k) << endl;
  return 0;
}
