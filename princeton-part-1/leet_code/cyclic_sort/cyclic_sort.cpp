using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    // TODO: Write your code here

    int i = 0;
    while(i < nums.size()){
      if(nums[i]!=i+1){
	int pos = nums[i]-1;
	swap(nums[i], nums[pos]);
      }
      else{
	i++;
      }
    }
  }
};



int main(){
  CyclicSort *cs = new CyclicSort();
  vector<int> nums = {3, 1, 5, 4, 2};
  cs->sort(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }

  cout << endl;

  nums = {2, 6, 4, 3, 1, 5};
  cs->sort(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }

  cout << endl;


  nums = {1, 5, 6, 4, 3, 2};
  cs->sort(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }

  cout << endl;

  return 0;
}
