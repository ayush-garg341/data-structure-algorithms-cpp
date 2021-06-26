#include<iostream>
#include<vector>

using namespace std;

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for(int i = 0; i < num.size(); i++){
      sum += num[i];
    }

    if(sum % 2 != 0){
      return false;
    }
    
    bool can = canPartitionRecursive(num, sum/2,  0);

    return can;
  }

private:
  bool canPartitionRecursive(const vector<int> &num, int sum,  int currentIndex){

    if(sum == 0){
      return true;
    }
    
    if(currentIndex >= num.size() || num.empty()){
      return 0;
    }

    if(num[currentIndex] <= sum){
      if(canPartitionRecursive(num, sum - num[currentIndex], currentIndex+1)){
	return true;
      }
    }

    return canPartitionRecursive(num, sum, currentIndex+1);
    
    
  }
  
};


int main(){
  const vector<int> nums = {1, 2, 3, 4};
  PartitionSet ptr;
  bool can = ptr.canPartition(nums);
  cout << can << endl;
  return 0;
}
