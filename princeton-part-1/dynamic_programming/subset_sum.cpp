#include<iostream>
#include<vector>
using namespace std;

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {

    vector<vector<int>>dp(num.size(), vector<int>(sum+1, -1));
    
    bool can = canPartitionRecursive(dp, num, sum, 0);
    return can;
  }

private:
  bool canPartitionRecursive(vector<vector<int>>dp , const vector<int> &num, int sum, int currentIndex){
    if(sum==0){
      return true;
    }

    if(currentIndex >= num.size() || num.empty()){
      return false;
    }

    if(dp[currentIndex][sum]==-1){
      if(num[currentIndex] <= sum){
	if(canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)){
	  dp[currentIndex][sum] = 1;
	  return true;
	}
      }
    }

    dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1) ? 1 : 0;
    
    return dp[currentIndex][sum]==1 ? true: false;
    
  }
  
};


int main(){
  SubsetSum cPtr;
  vector<int>num = {1, 2, 7, 1, 5};
  int s = 10;
  bool can1 = cPtr.canPartition(num, s);
  cout << can1 << endl;

  num = {1, 2, 3, 7};
  s = 6;
  bool can2 = cPtr.canPartition(num, s);
  cout << can2 << endl;
  
  num = {1, 3, 4, 8};
  s = 6;
  bool can3 = cPtr.canPartition(num, s);
  cout << can3 << endl;
  
  return 0;
  
}
