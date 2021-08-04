#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int index = 0;
    unordered_map<char, int>umap;
    for(int i = 0; i < str.size(); i++){

      if(umap.find(str[i])!=umap.end()){
	index = max(index, umap[str[i]]+1);
      }
      umap[str[i]] = i;
      maxLength = max(maxLength, i - index + 1);

    }
    
    return maxLength;
  }
};



int main(){
  string s = "abcabcbb";
  NoRepeatSubstring *soln = new NoRepeatSubstring();
  cout << soln->findLength(s) << endl;

  s = "abbbb";
  cout << soln->findLength(s) << endl;

  // s = "abccde";
  // cout << soln->findLength(s) << endl;

  s = "bpfbhmipx";
  cout << soln->findLength(s) << endl;

  // cout << " ====== " << endl;

  s = "an++--viaj";
  cout << soln->findLength(s) << endl;
  
  return 0;
}
