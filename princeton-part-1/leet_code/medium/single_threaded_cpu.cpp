#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

typedef pair <pair < int, int >, pair<int, int>>pi;

class Solution{
public:
  vector <int> getOrder(vector<vector <int>> & tasks){
    priority_queue <pi, vector<pi>, greater<pi>> available_tasks;
    stack<pi>currently_running_task;
    
    vector<int>order;

    int size = tasks.size();
    int current_time = 0;
    for(int i=0; i < size; i++){
      current_time = max(tasks[i][0], current_time);
      if(available_tasks.size()==0){
	available_tasks.push(make_pair(make_pair(tasks[i][0], tasks[i][1]), make_pair(tasks[i][0]+tasks[i][1], i)));
      }
      else if(current_time != available_tasks.top().first.second){
	if(currently_running_task.size() > 0){
	  if(current_time >= currently_running_task.top().second.first){
	    currently_running_task.pop();
	    available_tasks.push(make_pair(make_pair(tasks[i][1], tasks[i][0]), make_pair(tasks[i][0]+tasks[i][1], i)));
	    currently_running_task.push(available_tasks.top());
	    order.push_back(currently_running_task.top().second.second);
	    available_tasks.pop();
	  }
	  else{
	    available_tasks.push(make_pair(make_pair(tasks[i][1], tasks[i][0]), make_pair(tasks[i][0]+tasks[i][1], i)));
	  }
	}
	else{
	  if(currently_running_task.empty()){
	    currently_running_task.push(available_tasks.top());
	    order.push_back(currently_running_task.top().second.second);
	    available_tasks.pop();
	  }
	  available_tasks.push(make_pair(make_pair(tasks[i][1], tasks[i][0]), make_pair(tasks[i][0]+tasks[i][1], i)));
	}
      }
	
      else{
	available_tasks.push(make_pair(make_pair(tasks[i][1], tasks[i][0]), make_pair(tasks[i][0]+tasks[i][1], i)));
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
