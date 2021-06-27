using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  int canPartition(const vector<int> &num) { 
    int mim = canPartitionRecursive(num, 0, 0, 0);
    return mim; 
  }

private:
  int canPartitionRecursive(const vector<int> &num, int sum1, int sum2, int currentIndex){
    if(currentIndex == num.size()){
      return abs(sum1 - sum2);
    }

    int diff1 = canPartitionRecursive(num, sum1+num[currentIndex], sum2, currentIndex+1);

    int diff2 = canPartitionRecursive(num, sum1, sum2+num[currentIndex], currentIndex+1);

    return min(diff1, diff2);
  }
  
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
