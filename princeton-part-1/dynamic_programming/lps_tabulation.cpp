#include<iostream>
#include<vector>

using namespace std;


class LPS {
public:
  int findLPSLength(const string &st) {
    vector<vector<int>>dp(st.length(), vector<int>(st.length(), 0));
    for(int i = 0; i < st.length(); i++){
      dp[i][i] = 1;
    }

    for(int l = 2; l <= st.length(); l++){
      for(int i = 0; i < st.length()-l+1; i++){
	int j = i + l -1;
	if(l==2 && st[i] == st[j]){
	  dp[i][j] = 2;
	}
	else if(st[i] == st[j]){
	  dp[i][j] = 2 + dp[i+1][j-1];
	}
	else{
	  dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
	}
      }
    }

    return dp[0][st.length()-1];
    
  }
  
};


int main(int argc, char *argv[]){
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;
  delete lps;
  
  return 0;
}
