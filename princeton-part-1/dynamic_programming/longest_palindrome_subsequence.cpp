/*
  A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 */


#include<iostream>

using namespace std;


class LPS {
public:
  int findLPSLength(const string &st) {
    return findLPSLengthRecursive(st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(const string &st, int startIndex, int endIndex){
    if(startIndex > endIndex){
      return 0;
    }

    if(startIndex == endIndex){
      return 1;
    }

    if(st[startIndex]==st[endIndex]){
      return 2 + findLPSLengthRecursive(st, startIndex+1, endIndex-1);
    }

    int count1 = findLPSLengthRecursive(st, startIndex+1, endIndex);
    int count2 = findLPSLengthRecursive(st, startIndex, endIndex-1);

    return max(count1, count2);
    
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
