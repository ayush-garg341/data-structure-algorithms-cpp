#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int numTrees(int n) {
      vector<int>vec(n+1);

      vec[0] = 1;
      vec[1] = 1;

      for(int i = 2; i < n+1; i++ ){
	for(int j = 0; j < i; j++){
	  vec[i] += vec[i-j-1] * vec[j];
	}
      }

      return vec[n];
    }
};

int main(int argc, char* argv[]){
  Solution *soln = new Solution();
  cout << soln->numTrees(3) << endl;
  cout << soln->numTrees(5) << endl;
  cout << soln->numTrees(7) << endl;
  return 0;
}
