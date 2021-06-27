using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  int canPartition(const vector<int> &num) {
    int sum = 0;

    for(int i =0; i<num.size(); i++){
      sum += num[i];
    }
    
    vector<vector<int>>dp(num.size(), vector<int>(sum +1, -1));
    int mim = canPartitionRecursive(dp, num, sum,  0, 0, 0);
    return mim; 
  }

private:
  int canPartitionRecursive(vector<vector<int>>dp, const vector<int> &num, int sum,  int sum1, int sum2, int currentIndex){
    if(currentIndex == num.size()){
      return abs(sum1 - sum2);
    }

    if(dp[currentIndex][sum1]==-1){
      int diff1 = canPartitionRecursive(dp, num, sum, sum1+num[currentIndex], sum2, currentIndex+1);

      int diff2 = canPartitionRecursive(dp, num, sum, sum1, sum2+num[currentIndex], currentIndex+1);

      dp[currentIndex][sum1] = min(diff1, diff2);
    }
    
    return dp[currentIndex][sum1];
  }
  
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
