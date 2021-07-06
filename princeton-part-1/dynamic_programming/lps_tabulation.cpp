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

    for(int startIndex = st.length() - 1; startIndex >= 0; startIndex--){
      for(int endIndex = startIndex + 1; endIndex < st.length(); endIndex++){
	if(st[startIndex]==st[endIndex]){
	  dp[startIndex][endIndex] = 2 + dp[startIndex+1][endIndex-1];
	}
	else{
	  dp[startIndex][endIndex] = max(dp[startIndex+1][endIndex], dp[startIndex][endIndex-1]);
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
