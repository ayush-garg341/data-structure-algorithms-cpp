using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count =  0;
    sort(arr.begin(), arr.end());

    for(int  i = 0; i < arr.size(); i++){
      int j = i+1;
      int k = arr.size()-1;

      while(j < k){
	int triplet_sum  =  arr[i] + arr[j] + arr[k];
	if(triplet_sum < target){
	  count += k - j ;
	  j++;
	}
	else{
	  k--;
	}
      }
    }
    
    return count;
  }

  static vector<vector<int>> searchTripletsList(vector<int> &arr, int target) {
    int count =  0;
    sort(arr.begin(), arr.end());

    vector<vector<int>>triplet_list;

    for(int  i = 0; i < arr.size(); i++){
      int j = i+1;
      int k = arr.size()-1;

      while(j < k){
	int triplet_sum  =  arr[i] + arr[j] + arr[k];
	if(triplet_sum < target){
	  count += k - j;
	  int l = k;
	  while(l > j){
	    triplet_list.push_back({arr[i], arr[j], arr[l]});
	    l--;
	  }
	  
	  j++;
	}
	else{
	  k--;
	}
      }
    }
    
    return triplet_list;
  }
  
};


int main(){
  TripletWithSmallerSum *trip = new TripletWithSmallerSum();

  vector<int>nums = {-1, 0, 2, 3};
  int target = 3;

  cout << trip -> searchTriplets(nums, target) << endl;


  nums = {-1, 4, 2, 1, 3};
  target = 5;
  
  cout << trip -> searchTriplets(nums, target) << endl;

  vector<vector<int>>triplet_list = trip -> searchTripletsList(nums, target);
  
  for(auto vec: triplet_list){
    cout << "[ ";
    for(auto num:vec){
      cout << num << " " ;
    }
    cout << "]";
  }
  cout << endl;
  
  return 0;
}
