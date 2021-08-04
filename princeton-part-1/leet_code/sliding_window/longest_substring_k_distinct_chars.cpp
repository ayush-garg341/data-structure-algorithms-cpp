#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int distinct_chars = 0;
    int index = 0;
    unordered_map<char, int>distinct_char_map;
    for(int i = 0; i < str.length(); i++){
      if(distinct_char_map.find(str[i])==distinct_char_map.end() || distinct_char_map[str[i]]==0){
	distinct_char_map[str[i]]++;
	distinct_chars++;
      }

     
      while(distinct_chars > k){
	if(distinct_char_map[str[index]] > 1){
	  distinct_char_map[str[index++]] -= 1;
	}
	else{
	  distinct_chars -= 1;
	  distinct_char_map[str[index++]] -= 1;
	}
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
