#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int size = numeric_limits<int>::max();
    int sum = 0;
    int index = 0;
    for(int i = 0; i < arr.size(); i++){
      sum += arr[i];
      while(sum >= S){
	cout << sum << " " << i << " " << index << endl;
	size = min(size, i - index + 1);
	sum = sum - arr[index];
	index++;
      }
    }
    
    return size;
  }
};


int main(){
  vector<int>nums = {2,1,5,2,3,2};
  int sum = 7;

  nums = {2, 1, 5, 2, 8};

  nums = {3, 4, 1, 1, 6};

  sum = 8;

  nums = {1,1,1,1,1,5};
  sum = 5;
  
  MinSizeSubArraySum *soln = new MinSizeSubArraySum();
  cout << soln -> findMinSubArray(sum, nums) << endl;
  return 0;
}
