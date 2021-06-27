#include<iostream>
#include<vector>

using namespace std;

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for(int i = 0; i < num.size(); i++){
      sum += num[i];
    }

    if(sum % 2 != 0){
      return false;
    }

    vector<vector<int>>dp(num.size(), vector<int>(sum/2 + 1, -1));
    
    bool can = canPartitionRecursive(dp, num, sum/2,  0);

    return can;
  }

private:
  bool canPartitionRecursive(vector<vector<int>>dp,  const vector<int> &num, int sum,  int currentIndex){

    if(sum == 0){
      return true;
    }
    
    if(currentIndex >= num.size() || num.empty()){
      return false;
    }

    if(dp[currentIndex][sum]==-1){
      if(num[currentIndex] <= sum){
	if(canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex+1)){
	  dp[currentIndex][sum] = 1;
	  return true;
	}
      }
    }

    dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex+1) ? 1 : 0;

    return dp[currentIndex][sum] == 1 ? true : false;
    
  }
  
};


int main(){
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
  return 0;
}
