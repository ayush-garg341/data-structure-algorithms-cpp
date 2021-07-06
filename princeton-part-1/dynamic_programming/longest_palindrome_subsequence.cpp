/*
  A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 */


#include<iostream>
#include<vector>

using namespace std;


class LPS {
public:
  int findLPSLength(const string &st) {
    vector<vector<int>>dp(st.length(), vector<int>(st.length(), -1));
    return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(vector<vector<int>>dp, const string &st, int startIndex, int endIndex){
    if(startIndex > endIndex){
      return 0;
    }

    if(startIndex == endIndex){
      return 1;
    }


    if(dp[startIndex][endIndex]==-1){
      if(st[startIndex]==st[endIndex]){
	dp[startIndex][endIndex] =  2 + findLPSLengthRecursive(dp, st, startIndex+1, endIndex-1);
      }
      else{
	int count1 = findLPSLengthRecursive(dp, st, startIndex+1, endIndex);
	int count2 = findLPSLengthRecursive(dp, st, startIndex, endIndex-1);
	dp[startIndex][endIndex] = max(count1, count2);
      }
    }
      
    return dp[startIndex][endIndex];
    
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
