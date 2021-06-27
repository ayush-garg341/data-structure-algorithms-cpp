#include<iostream>
#include<vector>
using namespace std;

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    bool can = canPartitionRecursive(num, sum, 0);
    return can;
  }

private:
  bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex){
    if(sum==0){
      return true;
    }

    if(currentIndex >= num.size() || num.empty()){
      return false;
    }

    if(num[currentIndex] <= sum){
      if(canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)){
	return true;
      }
    }

    return canPartitionRecursive(num, sum, currentIndex + 1);
    
  }
  
};


int main(){
  SubsetSum cPtr;
  vector<int>num = {1, 2, 7, 1, 5};
  int s = 10;
  bool can1 = cPtr.canPartition(num, s);
  cout << can1 << endl;

  num = {1, 2, 3, 7};
  s = 6;
  bool can2 = cPtr.canPartition(num, s);
  cout << can2 << endl;
  
  num = {1, 3, 4, 8};
  s = 6;
  bool can3 = cPtr.canPartition(num, s);
  cout << can3 << endl;
  
  return 0;
  
}
