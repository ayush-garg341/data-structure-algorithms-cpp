#include<iostream>
using namespace std;


class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {

    int count = 0;
    
    if(s1.length()==0 || s2.length()==0){
      return count;
    }
    
    for(int i = 0; i < s1.length()-1; i++){
      string word = "" + s1[i];
      for(int j = i+1; j < s1.length(); j++){
	word += s1[j];
	if(word.length() <= s2.length()){
	  if(s2.find(word)!=string::npos){
	    int len = word.length();
	    count = max(count, len); 
	  }
	}
      }
    }
    
    return count;
  }
};


int main(){

  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;
  delete lcs;
  
  return 0;
}
