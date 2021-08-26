using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int i = 0;
    int j = arr.size()-1;

    int l = n-1;
    
    while(i <= j){
      int sq_i = arr[i]*arr[i];
      int sq_j = arr[j]*arr[j];

      if(sq_i > sq_j){
	squares[l] = sq_i;
	i++;
	l--;
      }
      else{
	squares[l] = sq_j;
	j--;
	l--;
      }
    }
    
    return squares;
  }
};


int main(){
  SortedArraySquares *sas = new SortedArraySquares();
  vector<int>nums = {-2, -1, 0, 2, 3};

  vector<int>sq_nums = sas -> makeSquares(nums);

  for(int i = 0; i < sq_nums.size(); i++){
    cout << sq_nums[i] << " ";
  }

  cout << endl;

  nums = {-3, -1, 0, 1};
  sq_nums = sas -> makeSquares(nums);

  for(int i = 0; i < sq_nums.size(); i++){
    cout << sq_nums[i] << " ";
  }

  cout << endl;
  
  return 0;
}
