using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    vector<vector<int>>dp(num.size(), vector<int>(sum+1, 0));
    int n = num.size();

    for(int i=n; i<n; i++){
      dp[i][0] = 1;
    }

    for(int s = 1; s <= sum; s++){
      if(s <= num[0]){
	dp[0][s] = 1;
      }
    }

    for(int i = 1; i < n; i++){
      for(int s = 1; s < sum; s++){
	if(s >= num[i])
	  dp[i][s] = dp[i-1][s] + dp[i-1][s-num[i]];
	else
	  dp[i][s] = dp[i-1][s];
      }
    }
    
    return dp[num.size() - 1][sum];
    
  }  
};


int main(){
  SubsetSum ss;
  vector<int>num = {1, 1, 2, 3};
  int sum = 4;
  int count = ss.countSubsets(num, sum);
  cout << count << endl;

  num = {1, 2, 7, 1, 5};
  sum = 9;
  count = ss.countSubsets(num, sum);
  cout << count << endl;

  return 0;
}
