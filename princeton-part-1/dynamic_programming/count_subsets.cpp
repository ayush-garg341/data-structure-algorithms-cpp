using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    int count = countSubsetsRecursive(num, sum, 0);
    return count;
  }

private:
  int countSubsetsRecursive(const vector<int>num, int sum, int currentIndex){
    if(sum==0){
      return 1;
    }
    if(currentIndex >= num.size() || num.empty()){
      return 0;
    }

    int count = 0;
    if(num[currentIndex] <= sum){
      count += countSubsetsRecursive(num, sum-num[currentIndex], currentIndex+1);
    }

    count += countSubsetsRecursive(num, sum, currentIndex + 1);

    return count;
    
  }
  
};


int main(){
  SubsetSum ss;
  vector<int>num = {1, 1, 2, 3};
  int sum = 4;
  int count = ss.countSubsets(num, sum);
  cout << count << endl;

  num = {1, 2, 7, 1, 5};
  sum = 9;
  count = ss.countSubsets(num, sum);
  cout << count << endl;

  return 0;
}
