#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class PairWithTargetSum{
public:
  static pair<int, int> search(vector<int>nums, int target){
    int i = 0;
    int j = nums.size() - 1;
    while(i < j){
      int actual_sum = nums[i] + nums[j];
      if(actual_sum == target){
	return {nums[i], nums[j]};
      }
      else if(actual_sum > target){
	j--;
      }
      else{
	i++;
      }
    }

    return {};
  }


   static pair<int, int> searchHashMap(vector<int>nums, int target){

     // array need not be sorted at all and this is important to note, useful when we need to return indices, in particular order...
     
     unordered_map<int, int>umap;
     for(int i = 0; i < nums.size(); i++){
       int diff = target - nums[i];
       if(umap.find(diff)!=umap.end()){
	 return {nums[i], diff};
       }
       else{
	 umap[nums[i]] = i;
       }
     }
     
     return {};
  }
  
};


int main(){

  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::searchHashMap(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::searchHashMap(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;

  result = PairWithTargetSum::searchHashMap(vector<int>{5, 2, 1, 3, 3, 6, 4}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  
  return 0;
}
