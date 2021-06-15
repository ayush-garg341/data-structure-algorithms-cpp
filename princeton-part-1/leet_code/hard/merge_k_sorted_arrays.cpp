#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<pair<int , int>, int> my_pair;

class Solution{

public:

  struct mycmp{
    bool operator()(my_pair a, my_pair b){
      return a.second > b.second;
    };
  };
  
  vector<int> mergeKSortedArrays(vector<vector<int>> & arrays){

    vector<int> final_nums_arr;
    
    int k = arrays.size();
    
    priority_queue <my_pair, vector<my_pair>, mycmp> pq;

    for(int i=0; i<k; i++){
      if(arrays[i].size()!=0){
	pq.push(make_pair(make_pair(i, 0), arrays[i][0]));
      }
    }

    while(!pq.empty()){
      my_pair current = pq.top();
      pq.pop();

      int array_num = current.first.first;
      int element_num = current.first.second;
      int element = current.second;

      final_nums_arr.push_back(element);

      if(element_num < arrays[array_num].size()-1){
	element_num++;
	pq.push(make_pair(make_pair(array_num, element_num), arrays[array_num][element_num]));
      }
      
    }

    return final_nums_arr;
    
  }
  
};


int main(){

  vector<int> num1 = {1, 3, 5, 7, 9};
  vector<int> num2 = {2, 4, 8, 12, 20};
  vector<int> num3 = {6, 10, 14, 16, 18};

  vector<vector<int>> final_arr;
  final_arr.push_back(num1);
  final_arr.push_back(num2);
  final_arr.push_back(num3);

  Solution soln;

  vector<int> final_num_arr = soln.mergeKSortedArrays(final_arr);

  cout << "\n";
  
  for(int j = 0; j<final_num_arr.size(); j++){
    cout << " " << final_num_arr[j];
  }

  cout << "\n";
  
  return 0;
}
