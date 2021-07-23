#include<iostream>
#include<vector>
using namespace std;


class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    int maxLength = min(s1.length(), s2.length());
    vector<vector<vector<int>>> dp(s1.length(),
                                   vector<vector<int>>(s2.length(), vector<int>(maxLength, -1)));
    
    int count = 0;
    if(s1.length()==0 || s2.length()==0){
      return count;
    }
    
    count = findLCSLengthRecursive(dp, s1, s2, 0, 0, 0);
    
    return count;
  }

  int findLCSLengthRecursive(vector<vector<vector<int>>> &dp,  const string &s1, const string &s2, int startS1, int startS2, int count){
    if(startS1 == s1.length() || startS2 == s2.length()){
      return count;
    }


    if(dp[startS1][startS2][count] == -1){
      int c1 = count;
      if(s1[startS1] == s2[startS2]){
	c1 = findLCSLengthRecursive(dp, s1, s2, startS1 + 1, startS2 + 1, count + 1);
      }
      
      int count2 = findLCSLengthRecursive(dp, s1, s2, startS1 , startS2 + 1, 0);
      int count3 = findLCSLengthRecursive(dp, s1, s2, startS1+1, startS2 , 0);

      dp[startS1][startS2][count] = max(c1, max(count2, count3));
    }
    
    return dp[startS1][startS2][count];
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
