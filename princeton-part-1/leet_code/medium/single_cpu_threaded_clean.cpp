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
    int current_time = enqued_tasks.top().first;
    while(!enqued_tasks.empty()){
      while(!enqued_tasks.empty() && enqued_tasks.top().first <= current_time){
	pi  top = enqued_tasks.top();
	available_tasks.push(make_pair(top.second.first, make_pair(top.second.first, top.second.second)));
	enqued_tasks.pop();
      }

      if(available_tasks.empty()){
	current_time = enqued_tasks.top().first;
	continue;
      }
      
      order.push_back(available_tasks.top().second.second);
      current_time += available_tasks.top().second.first;
      available_tasks.pop();
    }
    
    while(!available_tasks.empty()){
      order.push_back(available_tasks.top().second.second);
      available_tasks.pop();
    };
    
    return order;
  };
};

int main(){

  Solution soln;
  //vector<vector<int>>tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};

  vector<vector<int>> tasks = {{35,36},{11,7},{15,47},{34,2},{47,19},{16,14},{19,8},{7,34},{38,15},{16,18},{27,22},{7,15},{43,2},{10,5},{5,4},{3,11}};
  
  vector<int> order = soln.getOrder(tasks);

  for(int i = 0; i < order.size(); i++){
    cout << "order = " << order[i] << endl;
  }
  
  return 0;
}


// The idea here is , we are creating the heap of shortest time taken from the heap min. according to second at which task arrive.
// The catch here is as we are processing the task with shortest time taken, we should consider the time at which the task will get finished i.e. ( taks[j][0] + task[j][1]  )  and upto that point needs to scan all the tasks that will get into shortest time taken......
