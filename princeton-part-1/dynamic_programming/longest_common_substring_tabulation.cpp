#include<iostream>
#include<vector>
using namespace std;

class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    int maxLength = 0;
    for(int i = 1; i < s1.length(); i++){
      for(int j = 1; j < s2.length(); j++){
	if(s1[i] == s2[j]){
	  dp[i][j] = 1 + dp[i-1][j-1];
	}
	else{
	  dp[i][j] = 0;
	}

	maxLength = max(maxLength, dp[i][j]);
      }
    }

    return maxLength;
  }

};


int main(){
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
  cout << lcs->findLCSLength("abc", "adc") << endl;
  delete lcs;
  return 0;
}
