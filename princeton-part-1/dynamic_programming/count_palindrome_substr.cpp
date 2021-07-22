#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
      vector<vector<int>>dp(s.length(), vector<int>(s.length(), 0));

      int count = 0;
      for(int i = 0; i < s.length(); i++){
	dp[i][i] = 1;
	count += 1;
      }

      for(int l = 2; l <= s.length(); l++){
	for(int i = 0; i < s.length() - l + 1; i++){
	  int j = i + l -1;
	  if(l==2 && s[i] == s[j]){
	    dp[i][j] = 2;
	    count++;
	  }
	  else if(s[i] == s[j]){
	    if(j-i-1 == dp[i+1][j-1]){
	      dp[i][j] = 2 + dp[i+1][j-1];
	      count++;
	    }
	    else{
	      dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
	    }
	  }
	  else{
	    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
	  }
	  
	}
      }

      return count;
      
    }
};


int main(int argc, char *argv[]){
  Solution *lps = new Solution();
  cout << lps->countSubstrings("abdbca") << endl;
  cout << lps->countSubstrings("cddpd") << endl;
  cout << lps->countSubstrings("pqr") << endl;
  cout << lps->countSubstrings("babad") << endl;
  cout << lps->countSubstrings("cbbd") << endl;
  cout << lps->countSubstrings("a") << endl;
  cout << lps->countSubstrings("ac") << endl;
  delete lps;
  
  return 0;
}
