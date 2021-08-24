#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution{
public:
  vector<int> stringAnagrams(string str, string pattern){
    unordered_map<char, int>umap;
    int window_start = 0, matched=0;

    vector<int>indices;
    
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
	indices.push_back(window_start);
      }

      if(window_end >= pattern.length()-1){
	char start_char = str[window_start++];
	if(umap.find(start_char)!=umap.end()){
	  if(umap[start_char]==0){
	    matched--;
	  }
	  umap[start_char]++;
	}
      }
    }

    return indices;
    
  }
};


int main(){
  Solution *soln = new Solution();
  string str = "ppqp";
  string pattern = "pq";
  vector<int> list = soln -> stringAnagrams(str, pattern);

  cout << "[ " ;
  for(int i = 0; i < list.size(); i++){
    cout << list[i] << " ";
  }
  cout << "]" << endl;

  
  str = "abbcabc";
  pattern = "abc";
  //list = soln -> stringAnagrams(str, pattern);

  // cout << "[ " ;
  // for(int i = 0; i < list.size(); i++){
  //   cout << list[i] << " ";
  // }
  // cout << "]" << endl;
  
  delete soln;
  return 0;
}
