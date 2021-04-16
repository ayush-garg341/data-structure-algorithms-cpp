#include<iostream>

#include<string>

using namespace std;

class StringSubseqInOrder{
public:
  string subsequences(string str){
    if(str.empty()){
      return "";
    };

    char firstLetter = str[0];
    string restOfWord = str.substr(1);

    string substringOfRest = subsequences(restOfWord);

    string result = "";
    
  }
};


int main(){
  
  return 0;
}
