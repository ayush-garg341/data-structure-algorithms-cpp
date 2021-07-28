#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;


class Quick{
public:
  int partition(vector<int>&nums, int low, int high){
    int i = low+1;
    int j = high;
    while(true){
      while(nums[i] < nums[low]){
	i++;
	if(i==high){
	  break;
	}
      }

      while(nums[j] > nums[low]){
	j--;
	if(j==low){
	  break;
	}
      }

      if(i >= j){
	break;
      }

      swap(nums[i], nums[j]);
    }

    swap(nums[low], nums[j]);

    return j;
  }

  void qSort(vector<int>&nums, int low, int high){
    if(high < low){
      return;
    }
    int j = partition(nums, low, high);
    qSort(nums, low, j-1);
    qSort(nums, j+1, high);
  
  }

  int quickSelect(vector<int>&nums, int low, int high, int kth){
    int j = partition(nums, low, high);
    while(low < high){
      if(j == kth-1){
	return nums[kth-1];
      }
      else if(j > kth-1){
	j = partition(nums, low, j-1);
      }
      else if(j < kth-1){
	j = partition(nums, j+1, high);
      }
    }
  }
};


int main(){
  vector<int>nums = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  shuffle(nums.begin(), nums.end(), default_random_engine());
  int low = 0;
  int high = nums.size()-1;

  Quick *qs = new Quick();
  
  qs->qSort(nums, low, high);

  for(int i=0; i < nums.size(); i++){
    cout << " " << nums[i];
  }

  cout << endl;
  
  shuffle(nums.begin(), nums.end(), default_random_engine());
  
  int kth = qs->quickSelect(nums, low, high, 12);

  cout << kth << endl;

  delete qs;
  
  return 0;
}
