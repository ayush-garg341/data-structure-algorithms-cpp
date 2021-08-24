#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
  string minimumWindowSubstring(string str, string pattern){
    int window_start = 0;
    int matched = 0;
    unordered_map<char, int>umap;
    int min_len = str.length() + 1;
    int substrstart = 0;
    
    for(auto chr: pattern){
      umap[chr]++;
    }

    for(int window_end = 0; window_end < str.length(); window_end++){
      char right = str[window_end];
      if(umap.find(right)!=umap.end()){
	umap[right]--;
	if(umap[right]>=0){
	  matched++;
	}
      }

      while(matched == pattern.length()){
	if(min_len > window_end - window_start + 1){
	  min_len = window_end - window_start + 1;
	  substrstart = window_start;
	}

	char left = str[window_start++];

	if(umap.find(left)!=umap.end()){
	  if(umap[left]==0){
	    matched--;
	  }
	  umap[left]++;
	}	
      }
    }

    cout << substrstart << " " << min_len << endl;

    return min_len == str.length()+1 ? "": str.substr(substrstart, min_len);
    
  };
};


int main(){
  Solution *soln = new Solution();
  string str = "aabdec";
  string pattern = "abc";

  cout << soln -> minimumWindowSubstring(str, pattern) << endl;

  str = "abcdefghi";
  pattern = "xy";
  cout << soln -> minimumWindowSubstring(str, pattern) << endl;


  str = "aaaafgabdca";
  pattern = "aabc";
  cout << soln -> minimumWindowSubstring(str, pattern) << endl;

  delete soln;
  
  return 0;
}
