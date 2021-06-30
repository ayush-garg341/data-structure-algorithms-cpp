using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    int n = ribbonLengths.size();
    vector<vector<int>>dp(n, vector<int>(total + 1, numeric_limits<int>::min()));
    for(int i = 0; i < n; i++){
      dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++){
      for(int j = 1; j <= total; j++){
	if(i > 0){
	  dp[i][j] = dp[i-1][j];
	}
	if(j >= ribbonLengths[i]){
	  if(dp[i][j-ribbonLengths[i]]!=numeric_limits<int>::min()){
	    dp[i][j] = max(dp[i][j], 1 + dp[i][j-ribbonLengths[i]]);
	  }
	}

	cout << " i = " << i << " j = " << j << " " << dp[i][j] << endl;
      }
    }
    
    return  dp[n-1][total] == numeric_limits<int>::min() ? -1 :  dp[n-1][total];
  }
};

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{3, 5, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
}
