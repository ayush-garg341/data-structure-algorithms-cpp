#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
      vector<vector<int>>dp(s.length(), vector<int>(s.length(), 0));
      for(int i = 0; i < s.length(); i++){
	dp[i][i] = 0;
      }

      for(int l =2; l <= s.length(); l++){
	for(int i = 0; i < s.length()-l+1; i++){
	  int j = i + l - 1;

	  //cout << s[i] << " " << s[j] << endl;
	  
	  if(isPalindrome(i, j, s)){
	    //cout << "yea" << endl;
	    dp[i][j] = 0;
	  }
	  else{
	    int min_len = INT_MAX;
	    for(int k = i; k < j; k++){
	      min_len = min(min_len,  dp[i][k] + dp[k+1][j]);
	    }
	    dp[i][j] = 1 + min_len;
	    //cout << dp[i][j] << endl;
	  }
	}
      }

      return dp[0][s.length()-1];
    }

  bool isPalindrome(int start, int end, string s){
    while(start <= end){
      if(s[start] != s[end]){
	return false;
      }
      start += 1;
      end -= 1;
    };

    return true;
  }
  

};


int main(){
  Solution *soln = new Solution();
  cout << soln -> minCut("abcbm") << endl;
  cout << soln -> minCut("abdbca") << endl;
  cout << soln -> minCut("cddpd") << endl;
  cout << soln -> minCut("pqr") << endl;
  //cout << soln.minCut("") << endl;

  delete soln;
  
  return 0;
}
