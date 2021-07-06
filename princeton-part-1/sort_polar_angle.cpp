#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lpr pair<int,int>

pair<int, int> refPoint = make_pair(0, 0);


int quadrant(lpr x){
  if(x.first >= 0 && x.second >= 0){
    return 1;
  }
  if(x.first <=0 && x.second >= 0){
    return 2;
  }
  if(x.first <=0 && x.second <= 0){
    return 3;
  }

  if(x.first >= 0 && x.second <= 0){
    return 4;
  }
  
}

bool compareFn(lpr a, lpr b){
  int quada = quadrant(a);
  int quadb = quadrant(b);

  if(quada > quadb){
    return false;
  }

  // compute the cross product of vectors (refPoint -> a) first (refPoint -> b)
  int det = (a.first - refPoint.first) * (b.second - refPoint.second) - (b.first - refPoint.first) * (a.second - refPoint.second);
  if (det > 0)
    return true;
  if (det < 0)
    return false;


  // points a and b are on the same line from the refPoint
  // check which point is closer to the refPoint
  int d1 = (a.first - refPoint.first) * (a.first - refPoint.first) + (a.second - refPoint.second) * (a.second - refPoint.second);
  int d2 = (b.first - refPoint.first) * (b.first - refPoint.first) + (b.second - refPoint.second) * (b.second - refPoint.second);
  return d1 < d2;
  
}


int main(){
  vector<lpr>points;
  points.push_back(make_pair(-2, 3));
  points.push_back(make_pair(1, 2));
  points.push_back(make_pair(3, -1));
  points.push_back(make_pair(-2, -2));
  points.push_back(make_pair(2, 2));
  points.push_back(make_pair(1, 3));
  points.push_back(make_pair(3, 3));
  
  sort(points.begin(), points.end(), compareFn);

  for(int i = 0; i < points.size(); i++){
    cout << points[i].first << " " << points[i].second << endl;
  }
  return 0;
}


// This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. 
