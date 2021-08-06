#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int distinct_chars = 0;
    int index = 0;
    unordered_map<char, int>umap;
    for(int i = 0; i < str.length(); i++){
      char start = str[i];
      int diff = 0;
      int j = i + 1;
      while(j < str.length()){
	if(str[j]!=start){
	  diff += 1;
	}
	if(diff > k){
	  break;
	}
	j++;
      }

      maxLength = max(maxLength, j-i);
      
    }
    return maxLength;
  }
};


int main(){
  string s = "aabccbb";
  int k = 2;
  
  CharacterReplacement *soln = new CharacterReplacement();
  cout << soln->findLength(s, k) << endl;

  cout << " =====  " << endl;
  
  s = "abbcb";
  k = 1;

  cout << soln->findLength(s, k) << endl;

  cout << "  ======  " << endl;
  
  s = "abccde";
  k = 1;

  cout << soln->findLength(s, k) << endl;

  delete soln;
  
  return 0;
}
