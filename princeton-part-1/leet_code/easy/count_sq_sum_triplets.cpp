#include<iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
      
      unordered_map<int, int> umap;

      for(int i = 1; i <=n; i++){
	umap[i*i]++;
      }
      
        int count = 0;
        for(int i=1; i<=n; i++){
	  for(int j = 1; j<=n; j++){
	    if (umap.find(i*i + j*j) == umap.end()){
	      continue;
	    }
	    else{
	      count ++;
	    }
	  }
        }
        
        return count;
    }
};


int main(){
  Solution soln;
  //cout << soln.countTriples(5) << endl;
  cout << soln.countTriples(10) << endl;
  return 0;
}
