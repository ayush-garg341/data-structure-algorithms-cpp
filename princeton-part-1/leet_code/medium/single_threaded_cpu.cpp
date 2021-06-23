#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution{
#define ll long long int
#define p pair<int,int>
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int i=0;
    vector<int>res;
    for(auto &v:tasks)
      v.push_back(i++);

    for(int i = 0; i < tasks.size(); i++){
      cout << "(" << tasks[i][0] << " " << tasks[i][1] <<  " " << tasks[i][2] << ") "; 
    }

    cout << endl;
    
    sort(tasks.begin(),tasks.end());
    
    for(int i = 0; i < tasks.size(); i++){
      cout << "(" << tasks[i][0] << " " << tasks[i][1] <<  " " << tasks[i][2] << ") "; 
    }

    cout << endl;
    
    priority_queue<p,vector<p>,greater<p>>pq;
    ll time=tasks[0][0];i=0;
    while(i<tasks.size() || !pq.empty())
      {
	while(i<tasks.size() && tasks[i][0]<=time)
	  {
	    pq.push({tasks[i][1],tasks[i][2]});
	    i++;
	  }
	if(pq.empty())
	  {
	    time=tasks[i][0];
	    continue;
	  }
	res.push_back(pq.top().second);
	time+=pq.top().first;
	pq.pop();
      }
    return res;
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
