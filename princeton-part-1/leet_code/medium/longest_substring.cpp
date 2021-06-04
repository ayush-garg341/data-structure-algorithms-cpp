#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
	int start = 0;
        for(unsigned int i = 0; i < s.length(); i++){
	  cout  << "substring = " << s.substr(0, i+1) << "\n";
	  cout << "s[i] = " << s[i] << "\n";
	  if(s.substr(0, i).rfind(s[i])!=string::npos){
	    cout << "found = " << s[i] << "\n";
	    start = max((unsigned)start, (unsigned)s.substr(0,i).rfind(s[i]) + 1 );
	    cout << "start = " << start << "\n";
	  }
	  len = max((unsigned)len ,  i - start + 1);
	  cout << "len = " << len << "\n";
	}
        
        return len;
    }
};


int main(){
  Solution soln;
  int len = soln.lengthOfLongestSubstring("abba");
  cout << "len = " << len << "\n";
}
