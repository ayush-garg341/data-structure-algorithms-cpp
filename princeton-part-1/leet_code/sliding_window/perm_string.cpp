#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class Solution{
public:
  bool stringPermutation(string str, string pattern){
    unordered_map<char, int>umap;
    int window_start = 0, matched=0;
    
    // storing the frequencies of the chars in pattern.
    for(int i = 0; i < pattern.length(); i++){
      umap[pattern[i]]++;
    }

    for(int window_end = 0 ; window_end < str.length(); window_end++){

      if(umap.find(str[window_end])!=umap.end()){
	umap[str[window_end]]--;
	if(umap[str[window_end]]==0){
	  matched++;
	}
      }

      if(matched == (int)umap.size()){
	return true;
      }

      if(window_end >= pattern.length()-1){
	int start_char = str[window_start++];
	if(umap.find(start_char)!=umap.end()){
	  if(umap[start_char]==0){
	    matched--;
	  }
	  umap[start_char]++;
	}
      }
      
    }

    return false;
    
  }
};


int main(){
  Solution *soln = new Solution();
  string str = "oidbcaf";
  string pattern = "abc";
  cout << soln -> stringPermutation(str, pattern) << endl;

  str = "bcdxabcdy";
  pattern = "bcdyabcdx";
  cout << soln -> stringPermutation(str, pattern) << endl;

  str = "odicf";
  pattern = "dc";
  cout << soln -> stringPermutation(str, pattern) << endl;
  
  delete soln;
  return 0;
}
