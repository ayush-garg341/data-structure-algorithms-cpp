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

  unordered_map<int, vector<int>> allSubArraysWithZeroSum(vector<int>&nums){
    unordered_map <int, int>umap;
    unordered_map <int, vector<int>>sub_arrays;
    int size = nums.size();
    int i = -1;
    umap[0] = 1;
    //sub_arrays[0].push_back(0);
    int sum = 0;
    int count = 0;
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

      sub_arrays[sum].push_back(i);
    }

    return sub_arrays;
  }
  
};

int main(){
  vector<int>nums = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
  Solution soln;
  int num = soln.countZeroSumSubArrays(nums);
  cout << num << endl;

  unordered_map<int, vector<int>>sub_arrays;
  sub_arrays = soln.allSubArraysWithZeroSum(nums);

  unordered_map<int, vector<int>>::iterator it;
  for(it=sub_arrays.begin(); it!=sub_arrays.end(); it++){
    cout << "sum = " <<  it->first << endl;
    for(int i = 0; i < sub_arrays[it->first].size();i++){
      cout << sub_arrays[it->first][i] << " -> ";
    }
    cout << endl;
  }  
  
  return 0;
}
