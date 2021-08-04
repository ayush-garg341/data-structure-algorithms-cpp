#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int index = 0;
    unordered_map<char, int>distinct_char_map;
    for(int i = 0; i < str.length(); i++){
      distinct_char_map[str[i]]++;
	
      while( (int)distinct_char_map.size() > k){
	distinct_char_map[str[index]]--;
	if(distinct_char_map[str[index]]==0){
	  distinct_char_map.erase(str[index]);
	}
	index ++;
      }
      maxLength = max(maxLength, i - index + 1);
    }
    return maxLength;
  }
};



int main(){
  string s= "araaci";
  int  k = 2;

  LongestSubstringKDistinct *soln = new LongestSubstringKDistinct();
  cout << soln -> findLength(s, k) << endl;

  s = "araaci";
  k = 1;
  cout << soln -> findLength(s, k) << endl;

  s = "bbebi";
  k = 3;
  cout << soln -> findLength(s, k) << endl;

  s = "eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh";
  k = 16;
  cout << soln -> findLength(s, k) << endl;
  
  delete soln;
  
  return 0;
}
