#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
  vector<double> contigousAvg(vector<int>nums, int k){
    int sum = 0;
    double avg;
    vector<double>avgs;
    
    for(int i = 0; i < nums.size(); i++){
      if(i==k-1){
	sum += nums[i];
	avg = (double)sum / k;
	avgs.push_back(avg);
      }
      else if(i < k){
	sum += nums[i];
      }
      else{
	sum += nums[i] - nums[i-k];
	avg = (double)sum / k;
	avgs.push_back(avg);
      }
    }

    return avgs;
  }
};


int main(){
  vector<int>nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};
  int k = 5;
  Solution *soln = new Solution();
  vector<double>avgs = soln -> contigousAvg(nums, k);

  for(int i = 0; i < avgs.size(); i++){
    cout << avgs[i] << " ";
  }
  
  cout << endl;
  
  delete soln;
  
  return 0;
}
