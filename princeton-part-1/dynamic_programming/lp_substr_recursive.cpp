#include<iostream>
#include<vector>

using namespace std;


class LPS {
public:
  int findLPSLength(const string &st) {
    vector<vector<int>>dp(st.length(), vector<int>(st.length(), 0));
    int len = findLPSLengthRecursive(st, dp, 0, st.length()-1);

    return len;
  }

  int findLPSLengthRecursive(const string &st, vector<vector<int>>dp, int start, int end){
    if(start > end){
      return 0;
    }

    if(start == end){
      return 1;
    }

    if(st[start]==st[end]){
      int remainingLen = end-start-1;
      if(remainingLen==findLPSLengthRecursive(st, dp, start+1, end-1)){
	return 2 + remainingLen;
      }
    }

    int c1 = findLPSLengthRecursive(st, dp, start+1, end);
    int c2 = findLPSLengthRecursive(st, dp, start, end-1);

    return max(c1, c2);
    
  }
  
};


int main(int argc, char *argv[]){
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;
  cout << lps->findLPSLength("babad") << endl;
  cout << lps->findLPSLength("cbbd") << endl;
  cout << lps->findLPSLength("a") << endl;
  cout << lps->findLPSLength("ac") << endl;
  delete lps;
  
  return 0;
}
