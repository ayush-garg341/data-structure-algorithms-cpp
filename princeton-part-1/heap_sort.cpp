#include<iostream>
#include<vector>

using namespace std;

class HeapSort{
  int size;
  int N;
  vector<int> data;
  
public:

  HeapSort(vector<int> &nums){
    data = nums;
    size = nums.size();
    N = size;
  }
  
  vector <int> getSortedArray(){
    for(int k=(size/2); k>=1; k--){
      sink(k, size);
    }

    while(N>1){
      deleteMax();
    }
    
    return data;
  }
  

  void deleteMax(){
    exchange(1, N--);
    sink(1, N);
  }
  

  void sink(int k, int N){
    while(2*k <= N){
      int j = 2*k;
      if(j < N && isLess(j, j+1)){
	j++;
      }
      if(!isLess(k, j)){
	break;
      }
      exchange(k, j);
      k = j;
    }
  }

  void swim(int k){
    while(k>=1){
      int j = k/2;
      if(isLess(j, k)){
	exchange(j, k);
	k = k/2;
      }
      else{
	break;
      }
    }
  }

  void exchange(int pos_a, int pos_b){
    int temp = data[pos_a-1];
    data[pos_a-1] = data[pos_b-1];
    data[pos_b-1] = temp;
  }

  bool isLess(int pos_a, int pos_b){
    return data[pos_a-1] < data[pos_b-1];
  }
  
};


int main(){
  vector<int> nums = {-1, 10, 12, 5, 3, 6, 8, 7, 9, 1, 0};
  HeapSort hs(nums);
  vector<int> sorted_array = hs.getSortedArray();

  cout << "\n" <<"sorted elements ==" << "\n";
  
  for(int i=0; i <= sorted_array.size()-1; i++){
    cout  << " " << sorted_array[i];
  }

  cout << "\n";
}
