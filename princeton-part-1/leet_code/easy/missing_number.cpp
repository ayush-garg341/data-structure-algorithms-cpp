#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution{
public:
  int missingNumber(vector<int>nums){
    unordered_map<int, int>umap;
    for(int i = 0; i < nums.size(); i++){
      umap[nums[i]]++;
    }

    for(int i = 0; i <= nums.size(); i++){
      if(umap.find(i)!=umap.end()){
	continue;
      }
      else{
	return i;
      }
    }
    return nums.size();
  }

  int missingNumberXOR(vector<int>nums){
    int size = nums.size();
    int XOR = nums[0];
    bool zero = false;
    if(nums[0]==0){
      zero = true;
    }
    for(int i = 1; i < nums.size(); i++){
      XOR = XOR ^ nums[i];
      if(nums[i]==0){
	zero = true;
      }
    }

    for(int i = 0; i <= nums.size(); i++ ){
      XOR = XOR ^ i;
    }

    if(XOR == 0 && zero == false){
      return 0;
    }

    return XOR;
  }

  int usingSum(vector<int>nums){
    int sum =  0;
    
    for(int i = 0; i < nums.size(); i++){
      sum +=  i - nums[i];
    }

    sum += nums.size();
    
    return sum;
  }
  
};


int main(){
  vector<int>nums = {9,6,4,2,3,5,7,0,1};
  //nums = {0};
  Solution *soln = new Solution();
  cout << soln -> missingNumber(nums) << endl;

  cout << soln -> missingNumberXOR(nums) << endl;

  cout << soln -> usingSum(nums) << endl;
  
  return 0;
}
