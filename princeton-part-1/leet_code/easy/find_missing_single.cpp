#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

class MissingSingle{

public:
  int hashMap(vector<int>&nums){
    unordered_map<int, int>umap;
    for(int i =0; i<nums.size(); i++){
      umap[nums[i]]++;
    }

    for(auto it=umap.begin(); it!=umap.end(); it++){
      if(it->second ==1 ){
	return it->first;
      }
    }
    
  };

  int naive(vector<int>&nums){
    sort(nums.begin(), nums.end());
    int prev = nums[0];
    int prevCount = 1;
    for(int i = 1; i < nums.size(); i++){
      if(prev == nums[i]){
        prevCount += 1;
      }
      else if(prevCount==2 && prev!=nums[i]){
	prev = nums[i];
	prevCount = 1;
      }
      else{
	return prev;
      }
    }
  };

  int XOR(vector<int>&nums){
    int result = nums[0];
    for(int i =1; i < nums.size(); i++){
      result = result ^ nums[i];
    }

    return result;
  }; 

  int binarySearch(vector<int>&nums){
    
  };

  int sum(vector<int>&nums){
    unordered_map<int, int>umap;
    int total_sum = 0;
    int unique_sum = 0;
    for(int i = 0; i < nums.size(); i++){
      if(umap.find(nums[i])!=umap.end()){
	total_sum += nums[i];
      }
      else{
	unique_sum += nums[i];
	total_sum += nums[i];
	umap[nums[i]]++;
      }
    }

    return 2*unique_sum - total_sum;
  };
  
};


int main(){
  vector<int>nums = {1, 2, 1, 3, 3, 2, 7, 8, 9, 7, 9};

  MissingSingle *soln = new MissingSingle();

  cout << soln -> hashMap(nums) << endl;
  cout << soln -> naive(nums) << endl;
  cout << soln -> XOR(nums) << endl;
  // cout << soln -> binarySearch(nums) << endl;
  cout << soln -> sum(nums) << endl;

  delete soln;
  
  return 0;
}
