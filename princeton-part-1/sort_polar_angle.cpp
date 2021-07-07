#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Point{
  int x, y;
};


/*
0 -> co-linear
1 -> clockwise
2 -> anti clockwise
 */

Point p0 = {0,0};


int distSq(Point p1, Point p2){
  return (p1.x - p2.x)*(p1.x - p2.x) +
    (p1.y - p2.y)*(p1.y - p2.y);
}


int orientation(Point p1, Point p2){
  int cross_prod = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);

  if(cross_prod==0){
    return cross_prod;
  }
  
  return cross_prod > 0 ? 1 : 2;  
  
}


int compare(const void *p1, const void *p2){
  Point *vp1 = (Point *)p1;
  Point *vp2 = (Point *)p2;

  int dir = orientation(*vp1, *vp2);

  if(dir==0){
    return (distSq(p0, *vp1) >= distSq(p0, *vp2))? 1 : -1;
  }

  return dir == 1 ? -1 : 1; 
}


int main(){

  Point points[] = {
		    {3, -2}, {0, 3}, {1, 1}, {1, 3}, {-2, 4},
		    {-1, -1}, {3, -1}
  };

  int n = sizeof(points)/sizeof(points[0]);
  
  qsort(&points[0], n, sizeof(Point), compare);

  for(int i = 0 ; i < n; i++){
    cout << points[i].x << " " << points[i].y << endl;
  }

  return 0;
}


// sort:- This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. 


// qsort:-  void qsort (void* base, size_t num, size_t size, int (*comparator)(const void*,const void*));
/*

int comparator(const void* p1, const void* p2);

Return value meaning
<0 The element pointed by p1 goes before the element pointed by p2
0  The element pointed by p1 is equivalent to the element pointed by p2
>0 The element pointed by p1 goes after the element pointed by p2

 */
