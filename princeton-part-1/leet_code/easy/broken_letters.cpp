#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
      int count = 0;
      int index;
      string word = "";
      for(int i = 0; i < text.length(); i++){
	if(text[i]==' '){
	  cout << word << endl;
	  count += countWords(word, brokenLetters);
	  word="";
	}
	else{
	  word = word + text[i];
	  if(i==text.length()-1){
	    cout << word << endl;
	    count += countWords(word, brokenLetters);
	  }
	}
      }
      
      return count;
    }

  int countWords(string word, string brokenLetters){
    int localCount = 0;

    if(brokenLetters==""){
      return 1;
    }
    
    for(int br = 0; br < brokenLetters.length(); br++){
      if(word.find(brokenLetters[br]) != string::npos){
	localCount = 0;
	break;
      }
      else{
	localCount = 1;
      }
    }
    return localCount;
  }
};



int main(){
  Solution soln;
  cout << soln.canBeTypedWords("leet code", "e") << endl;
  cout << soln.canBeTypedWords("hello world", "ad") << endl;
  cout << soln.canBeTypedWords("leet code", "lt") << endl;
  cout << soln.canBeTypedWords("abc de", "") << endl;

  return 0;
}
