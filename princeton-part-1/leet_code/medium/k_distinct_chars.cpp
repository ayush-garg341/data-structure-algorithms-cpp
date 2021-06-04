#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestKDistinctCharSubstring(string s, int k) {
       vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0;

	if(k==0){
	  return 0;
	}

	
	
        while((unsigned)end<s.size()){
	  char c1 = s.at(end);
	  if(map[c1]==0){
	    counter++;
	  }
	  map[c1]++;
	  end++;
	  
	  while(counter>k) {
	    // char c2 = s.at(begin);
	    // counter--;
	    // begin = begin + map[c2];
	    if (--map[s.at(begin++)] == 0) counter--;
	  }
	  d=max(d, end-begin);
        }
        return d;
    }
};


int main(){
  Solution soln;
  int k = 16;
  int len = soln.longestKDistinctCharSubstring("eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh", k);
  cout << "len = " << len << "\n";
}
