#include<iostream>
#include<vector>
using namespace std;


class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length() +1, 0));
 
    for(int i = 1; i <= s1.length(); i++){
      for(int j = 1; j <= s2.length(); j++){
	if(s1[i-1]==s2[j-1]){
	  dp[i][j] = 1 + dp[i-1][j-1];
	}
	else{
	  dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	}
      }
    }

    return dp[s1.length()][s2.length()];
  }
};

int main(){
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
  delete lcs;
  return 0;
}
