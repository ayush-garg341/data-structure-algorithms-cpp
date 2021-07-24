#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
      unordered_map<char, int>umap;
      for(int i = 0 ; i < s.length(); i++){
	umap[s[i]]++;
      }

      int freq = umap[s[0]];

      for(auto m = umap.begin(); m != umap.end(); m++){
	if(m->second!=freq){
	  return false;
	}
      }

      return true;
      
    }
};


int main(){
  string s = "aaabb";
  Solution *soln = new Solution();

  cout << soln -> areOccurrencesEqual(s) << endl;

  s = "abacbc";
  cout << soln -> areOccurrencesEqual(s) << endl; 

  return 0;
}
