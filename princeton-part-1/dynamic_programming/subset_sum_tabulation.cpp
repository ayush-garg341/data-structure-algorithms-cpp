#include<iostream>
#include<vector>
using namespace std;

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {

    vector<vector<bool>>dp(num.size(), vector<bool>(sum+1));

    int n = num.size();
    
    for(int i = 0 ; i < n; i++){
      dp[i][0] = true;
    }
    
    for(int s = 1; s <= sum; s++){
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
	else if(s >= num[i]){
	  dp[i][s] = dp[i-1][s-num[i]];
	}
      }
    }
    
    return dp[num.size()-1][sum];
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
