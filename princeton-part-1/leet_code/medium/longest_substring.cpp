#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while((unsigned)end<s.size()){
	  char c1 = s.at(end);
	  if(map[c1]>0){
	    counter++;
	  }
	  map[c1]++;
	  end++;
	  while(counter>0) {
	    char c2 = s.at(begin);
	    if(map[c2]>1){
	      counter--;
	    }
	    map[c2]--;
	    begin++;
	  }
	  d=max(d, end-begin);
        }
        return d;
    }
};


int main(){
  Solution soln;
  int len = soln.lengthOfLongestSubstring("abcdedfghisjk");
  cout << "len = " << len << "\n";
}
