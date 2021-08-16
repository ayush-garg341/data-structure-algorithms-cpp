#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  int longestPeak(vector<int>array){

    int longest_peak = 0;
    
    vector<int>peaks_arr = findAllPeaksIndices(array);

    int i = 0;
    while(i < peaks_arr.size()){

      int j = peaks_arr[i];
      int k = j;

      int local_peak = 0;
      
      while(j > 0 && array[j-1] < array[j]){
	local_peak += 1;
	j--;
      }

      while(k < array.size()-1 && array[k+1] < array[k]){
	local_peak += 1;
	k++;
      }

      longest_peak = max(longest_peak, local_peak+1);

      i++;
    }
    
    return longest_peak;
  }

  vector<int> findAllPeaksIndices(vector<int>array){
    vector<int>peaks_arr;
    for(int i = 1; i < array.size()-1; i++){
      if(array[i] > array[i-1] && array[i] > array[i+1]){
	peaks_arr.push_back(i);
      }
    }

    return peaks_arr;
  }
  
};


int main(){
  vector<int>array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
  Solution *soln = new Solution();
  
  int peak_len = soln -> longestPeak(array);

  cout << peak_len << endl;

  return 0;
}
