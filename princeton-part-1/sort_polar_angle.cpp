#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lpr pair<int,int>

pair<int, int> refPoint = make_pair(0, 0);

bool compareFn(lpr a, lpr b){
  int a_x = a.first - refPoint.first;
  int a_y = a.second - refPoint.second;

  int b_x = b.first - refPoint.first;
  int b_y = b.second - refPoint.second;

  cout << "( " << a_x << " " << a_y << " )" << " ( " << b_x << " " << b_y << " )" << endl;

  cout << b_x*a_y - b_y*a_x << endl;

  return b_x*a_y - b_y*a_x > 0 ? 1 : 0;
}


int main(){
  vector<lpr>points;
  points.push_back(make_pair(-2, 3));
  points.push_back(make_pair(1, 2));
  points.push_back(make_pair(3, -1));
  points.push_back(make_pair(-2, -2));
  
  sort(points.begin(), points.end(), compareFn);

  for(int i = 0; i < points.size(); i++){
    cout << points[i].first << " " << points[i].second << endl;
  }
  return 0;
}
