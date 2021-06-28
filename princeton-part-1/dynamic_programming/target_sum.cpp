using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
public:
  int findTargetSubsets(const vector<int> &num, int s) {
    int sum = 0;
    for(int i = 0; i < num.size(); i++){
      sum += num[i];
    }
    vector<vector<int>>dp(num.size(), vector<int>(sum+1, -1));
    int count = findTargetSubsetsRecursuve(dp, num, s, 0, 0, 0);
    return count;
  }

private:
  int findTargetSubsetsRecursuve( vector<vector<int>>dp, const vector<int> &num, int sum, int sum1, int sum2, int currentIndex){

    if(currentIndex == num.size() || num.empty()){
      if(sum1-sum2==sum){
	return 1;
      }
      return 0;
    }

    int count = 0;

    if(dp[currentIndex][sum1]==-1){
      count += findTargetSubsetsRecursuve(dp, num, sum,  sum1 + num[currentIndex], sum2,  currentIndex+1);
      
      count += findTargetSubsetsRecursuve(dp, num, sum, sum1, sum2 + num[currentIndex], currentIndex+1);

      dp[currentIndex][sum1] = count;
    }
    return dp[currentIndex][sum1];
    //return count;
  }
  
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
