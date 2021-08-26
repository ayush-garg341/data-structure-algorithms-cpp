using namespace std;

#include <iostream>

class HappyNumber {
 public:

  // can be done with set or hash map we can put all the values seen so far and check if next sum is in set or not.
  
  static bool find(int num) {
    int slow = num;
    int fast = num;
    
    while(true){
      slow = squareSum(slow);
      fast = squareSum(squareSum(fast));
      if(slow == fast && slow != 1){
	return false;
      }
      else if(slow==fast && slow == 1){
	return true;
      }
    }
    
    return false;
  }

  static int squareSum(int num){
    int sq_sum = 0;
    while(num!=0){
      int rem = num % 10;
      sq_sum += rem*rem;
      num = num/10;
    }
    return sq_sum;
  }
  
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
