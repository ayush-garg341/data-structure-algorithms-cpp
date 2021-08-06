#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int index = 0;
    unordered_map<char, int>umap;
    int maxRepeatingCharCount = 0;
    for(int i = 0; i < str.length(); i++){
	umap[str[i]]++;
	maxRepeatingCharCount = max(maxRepeatingCharCount, umap[str[i]]);
      
	while( i -  index + 1 - maxRepeatingCharCount > k){
	  umap[str[index]]--;
	  index++;
	}

	maxLength = max(maxLength, i - index + 1);
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

  cout << "  ======  " << endl;
  
  s = "abbb";
  k = 1;
  cout << soln->findLength(s, k) << endl;

    

  delete soln;
  
  return 0;
}
