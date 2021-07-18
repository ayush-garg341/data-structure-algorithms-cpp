#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
      int size = (int)rungs.size();
      int rung_num = 0;
      int prev_dist = 0;
      for(int i = 0; i < size; i++){
	if(i==0){
	  while(rungs[i] - prev_dist > dist){
	    rung_num += 1;
	    prev_dist += dist;
	  }
	}
	else{
	  prev_dist = rungs[i-1];
	  while( rungs[i]- prev_dist  > dist){
	    rung_num += 1;
	    prev_dist += dist;
	  }
	}
      }

      return rung_num;
    }
};


int main(int argc, char* argv[]){
  Solution soln;
  vector<int>rungs = {1, 3, 5, 10};
  int dist = 2;
  int min_count = soln.addRungs(rungs, 2);

  cout << min_count << endl;

  rungs = {3,6,8,10};
  dist = 3;
  cout << soln.addRungs(rungs, dist) << endl;

  rungs = {3,4,6,7};
  dist = 2;
  cout << soln.addRungs(rungs, dist) << endl;

  rungs = {5};
  dist = 10;
  cout << soln.addRungs(rungs, dist) << endl;

  rungs = {3};
  dist = 1;
  cout << soln.addRungs(rungs, dist) << endl;
  
  return 0;
}
