#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;
        int merged_arr[nums1.size() + nums2.size()];
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                merged_arr[k] = nums1[i];
                i++;
                k++;
            }
            else{
                merged_arr[k] = nums2[j];
                j++;
                k++;
            }
        }
        
        while(i<nums1.size()){
            merged_arr[k] = nums1[i];
            k++;
            i++;
        }
        
        while(j<nums2.size()){
            merged_arr[k] = nums2[j];
            k++;
            j++;
        }
        
        if((nums1.size() + nums2.size()) %2 !=0){
	  int mid = (nums1.size() + nums2.size())/2;
            return merged_arr[ mid ];
        }
	
        return ( merged_arr[(nums1.size() + nums2.size())/2 ] +  merged_arr[(nums1.size() + nums2.size())/2 - 1] ) / 2.00000;
    }
};


int main(){
  vector<int>num1 = {1, 2};
  vector<int>num2 = {3, 4};
  Solution soln;
  double median  = soln.findMedianSortedArrays(num1, num2);
  cout << "median = " << median << "\n";
}
