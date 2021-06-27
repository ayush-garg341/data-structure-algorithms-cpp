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

    int n = num.size();

    sum = sum/2;
    
    vector<vector<bool>>dp(n, vector<bool>(sum + 1));

    for(int i = 0; i < n; i++){
      dp[i][0] = true;
    }

    for(int s = 1; s <= sum ; s++){
      if(s <= num[0]){
	dp[0][s] = true;
      }
      else{
	dp[0][s] = false;
      }
    }

    for(int i = 1; i < n; i++){
      for(int s = 1; s <= sum; s++){
	if(dp[i-1][s]){
	  dp[i][s] = dp[i-1][s];
	}
	else if (s >= num[i]){
	  dp[i][s] = dp[i-1][s-num[i]];
	}
      }
    }
    
    return dp[n-1][sum];
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
