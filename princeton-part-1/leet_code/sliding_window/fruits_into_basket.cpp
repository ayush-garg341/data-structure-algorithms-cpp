// special case of longest substring when k = 2;

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int k = 2;
    int maxLength = 0;
    int index = 0;
    unordered_map<char, int>distinct_char_map;
    for(int i = 0; i < arr.size(); i++){
      distinct_char_map[arr[i]]++;
	
      while( (int)distinct_char_map.size() > k){
	distinct_char_map[arr[index]]--;
	if(distinct_char_map[arr[index]]==0){
	  distinct_char_map.erase(arr[index]);
	}
	index ++;
      }
      maxLength = max(maxLength, i - index + 1);
    }
    return maxLength;
  }
};



int main(){
  vector<char>fruits = {'A', 'B', 'C', 'A', 'C'};

  MaxFruitCountOf2Types *soln = new MaxFruitCountOf2Types();
  cout << soln -> findLength(fruits) << endl;

  fruits = {'A', 'B', 'C', 'B', 'B', 'C'};
  cout << soln -> findLength(fruits) << endl;
  
  delete soln;
  
  return 0;
}
