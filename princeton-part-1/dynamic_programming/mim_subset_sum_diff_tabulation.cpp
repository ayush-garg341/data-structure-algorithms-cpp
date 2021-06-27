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

    int n = num.size();
    int toFind = sum/2;
    
    vector<vector<bool>>dp(num.size(), vector<bool>(toFind + 1));

    for(int i = 0; i < n; i++){
      dp[i][0] = true;
    }

    for(int s = 1 ; s <= toFind; s++ ){
      if(s <= num[0]){
	dp[0][s] = true;
      }
      else{
	dp[0][s] = false;
      } 
    }

    for(int i = 1; i < n; i++){
      for(int s = 1; s <= toFind; s++){
	if(dp[i-1][s]){
	  dp[i][s] = dp[i-1][s];
	}
	else if(s >= num[i]){
	  dp[i][s] = dp[i-1][s-num[i]];
	}
      }
    }

    int closestSum = 0;
    for(int s = toFind; s >= 0; s--){
      if(dp[num.size()-1][s]){
	closestSum = s;
	break;
      }
    }

    int otherSubsetSum = sum - closestSum;

    return otherSubsetSum - closestSum;
    
    
    //return mim; 
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
