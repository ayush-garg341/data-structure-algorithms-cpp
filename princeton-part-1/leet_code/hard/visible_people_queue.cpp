#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
      unordered_map<int, int>umap;

      vector<int>dp(heights.size()+1);
      dp[0] = 0;
      
      for(int i = 1; i < heights.size(); i++){
	if(i == heights.size()-1){
	  umap[heights[i]] = 0;
	}
	
	if(heights[i] < heights[i-1]){
	  
	}
	if(heights[i] > heights[i-1]){
	  umap[heights[i-1]]++;
	}
      }
    }
};


int main(){
  Solution *soln = new Solution();
  vector<int>heights = {10,6,8,5,11,9};
  vector<int>visible = soln -> canSeePersonsCount(heights);
  return 0;
}
