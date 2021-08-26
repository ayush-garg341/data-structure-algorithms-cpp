#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
  static int removeKey(vector<int>&arr, int key){
    int nextnonkey = 0;
    for(int i = 0; i < arr.size(); i++){
      if(arr[i]!=key){
	arr[nextnonkey] = arr[i];
	nextnonkey++;
      }
    }

    return nextnonkey;
  }
};



int main(){

  Solution *soln = new Solution();

  vector<int>nums = {3, 2, 3, 6, 3, 10, 9, 3};
  int key = 3;

  int j = soln->removeKey(nums, key);
  cout << j << endl;

  for(int i = 0; i < j; i++){
    cout << nums[i] << " ";
  }

  cout << endl;
  
  return 0;
}
