#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    typedef pair < int, pair < int, int >>pi;
    priority_queue <pi, vector<pi>, greater<pi>>enqued_tasks, available_tasks;

    vector<int> order;
    
    int size = tasks.size();

    for(int i = 0; i< size; i++){
      enqued_tasks.push(make_pair(tasks[i][0], make_pair(tasks[i][1], i)));
    }

    int current_time=0;

    while(!enqued_tasks.empty()){

      current_time = max(current_time, enqued_tasks.top().first);
      
      if(available_tasks.size() > 0){
	if(order.size() == 0){
	  order.push_back(available_tasks.top().second.second);
	  available_tasks.pop();
	}
	else if(current_time < (tasks[order.back()][0] + tasks[order.back()][1])){
	  pi  top = enqued_tasks.top();
	  available_tasks.push(make_pair(top.second.first, make_pair(top.second.first, top.second.second)));
	  enqued_tasks.pop();
	}
	else if(current_time >= (tasks[order.back()][0] + tasks[order.back()][1])){
	  pi top = enqued_tasks.top();
	  available_tasks.push(make_pair(top.second.first, make_pair(top.second.first, top.second.second)));
	  enqued_tasks.pop();
	  order.push_back(available_tasks.top().second.second);
	  available_tasks.pop();
	}
      }
      else{
	pi  top = enqued_tasks.top();
	available_tasks.push(make_pair(top.second.first, make_pair(top.second.first, top.second.second)));
	enqued_tasks.pop();
      }
    }

    while(!available_tasks.empty()){
      order.push_back(available_tasks.top().second.second);
      available_tasks.pop();
    }

    return order;
    
  };
};


int main(){

  Solution soln;
  vector<vector<int>>tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
  vector<int> order = soln.getOrder(tasks);

  for(int i = 0; i < order.size(); i++){
    cout << "order = " << order[i] << endl;
  }
  
  return 0;
}
