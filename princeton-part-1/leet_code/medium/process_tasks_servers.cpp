#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;


typedef pair < int, pair < int, int >>pi;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
      priority_queue <pi, vector<pi>, greater<pi>> free, running;
      int server_size = servers.size();
      int tasks_size = tasks.size();

      vector<int> server_pos;
      
      for(int i=0; i < server_size; i++){
	free.push(make_pair(0, make_pair(servers[i], i)));
      }

      int current_time = 0;
      
      
      for(int j = 0; j < tasks_size; j++){
	current_time = max(current_time, j);

	if(free.size()==0){
	  pi top = running.top();
	  current_time = top.first; // wait till server becomes free...
	}
	
	
	while(running.size()>0 && current_time >= running.top().first){
	  pi top = running.top();
	  free.push(make_pair(0, make_pair(top.second.first, top.second.second)));
	  running.pop();
	}

	pi top = free.top();
	running.push(make_pair(current_time+tasks[j], make_pair(top.second.first, top.second.second)));
	free.pop();
	
	server_pos.push_back(top.second.second);
      }
      
    };
};


int main(){
  vector<int> servers = {3,3,2};
  vector<int> tasks = {1,2,3,2,1,2};
  Solution soln;
  soln.assignTasks(servers, tasks);
  return 0;
}
