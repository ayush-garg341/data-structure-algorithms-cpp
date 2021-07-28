#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;


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



int main(){
  vector<int>nums = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  shuffle(nums.begin(), nums.end(), default_random_engine());
  int low = 0;
  int high = nums.size()-1;
  qSort(nums, low, high);

  for(int i=0; i < nums.size(); i++){
    cout << " " << nums[i];
  }

  cout << endl;
  
  return 0;
}
