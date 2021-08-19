#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>merged;
    merged.push_back(intervals[0]);
    int pos = 0;
    for(int i = 1; i < intervals.size(); i++){
      if(intervals[i][0] <= merged[pos][1]){
	if(intervals[i][1] > merged[pos][1]){
	  merged[pos][1] = intervals[i][1];
	}
      }
      else{
	merged.push_back(intervals[i]);
	pos = 1;
      }
    };
    
    return merged;
    
  }
};




int main(){
  Solution *soln = new Solution();
  vector<vector<int>>intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
  vector<vector<int>>merge = soln->mergeOverlappingIntervals(intervals);

  for(int i = 0; i < merge.size(); i++){
    cout << "[ ";
    for(int j = 0; j < merge[i].size(); j++){
      cout << merge[i][j] << " ";
    }
    cout << "]";

    cout << endl;
  }
  
  return 0;
}
