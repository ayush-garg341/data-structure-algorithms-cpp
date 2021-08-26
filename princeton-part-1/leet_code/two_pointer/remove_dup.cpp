#include<iostream>
#include<vector>

using namespace std;


class RemoveDuplicates {
 public:
  vector<int> removeUsingExtraSpace(vector<int>& arr) {
    // TODO: Write your code here
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
      if(arr[i] != temp.back()){
	temp.push_back(arr[i]);
      }
    }
    
    return temp;
  }

  static int remove(vector<int>&array){
    int nextnondup = 1;
    for(int i = 1; i < array.size(); i++){
      if(array[nextnondup-1]!=array[i]){
	array[nextnondup] = array[i];
	nextnondup++;
      }
    }
    return nextnondup;
  }
};


int main(){
  vector<int> nums = {2, 3, 3, 3, 6, 9, 9};
  RemoveDuplicates *rd = new RemoveDuplicates();
  vector<int>newNum = rd->removeUsingExtraSpace(nums);

  for(auto num:newNum){
    cout << num << " " ;
  }
  
  cout << endl;


  cout << "length of non-dup sub array = " << rd->remove(nums) << endl;
  
  delete rd;

  return 0;
}
