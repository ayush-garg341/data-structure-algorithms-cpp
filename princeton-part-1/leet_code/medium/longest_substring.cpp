#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
	unordered_set <char> charSet ;
        for(unsigned int i = 0; i < s.length(); i++){
	  int count = 0;
	  for(unsigned int j = i; j < s.length(); j++){
	    if (charSet.find(s[j]) == charSet.end()){
	      charSet.insert(s[j]);
	      count += 1;
	    }
	    else{
	      break;
	    }
	  }

	  if(count > len){
	    len = count;
	  }

	  charSet.clear();
	  
        }
        
        return len;
    }
};


int main(){
  Solution soln;
  int len = soln.lengthOfLongestSubstring("abcabcbb");
  cout << "len = " << len << "\n";
}
