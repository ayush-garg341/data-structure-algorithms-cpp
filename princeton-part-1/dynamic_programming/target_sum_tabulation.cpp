using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
public:
  int findTargetSubsets(const vector<int> &num, int s) {
    int sum = 0;
    int n = num.size();
    for(int i = 0; i < num.size(); i++){
      sum += num[i];
    }

    int totalSum = sum + s;

    if(totalSum % 2 !=0){
      return 0;
    }

    int toFind = totalSum / 2;

    vector<vector<int>>dp(n, vector<int>(toFind+1, 0));
    
    for(int i = 0; i < n; i++){
      dp[i][0] = 1;
    }

    for(int s = 1; s <= toFind; s++){
      if(s <= num[0]){
	dp[0][s] = 1;
      }
    }

    for(int i = 1; i < n; i++){
      for(int s = 1; s <= toFind; s++){
	dp[i][s] = dp[i-1][s];
	if(s >= num[i]){
	  dp[i][s] += dp[i-1][s-num[i]];
	}
      }
    }
    
    return dp[n-1][toFind];
  }
  
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
