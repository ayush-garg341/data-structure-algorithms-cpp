#include<iostream>

using namespace std;


struct point{
  int x;
  int y;
};


class DoSegmentsIntersects{
public:
  bool segmentIntersects(struct point p1, struct point p2, struct point p3, struct point p4){
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p4);
    int d4 = direction(p1, p2, p3);

    if( ( (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0 )) && ( (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0 ) ) ){
      return true;
    }
    else if( d1 == 0 && onSegment(p3, p4, p1)){
      return true;
    }
    else if(d2 == 0 && onSegment(p3, p4, p2)){
      return true;
    }
    else if(d3 == 0 && onSegment(p1, p2, p4)){
      return true;
    }
    else if(d4 == 0 && onSegment(p1, p2, p3)){
      return true;
    }
    else{
      return false;
    }
    
  }

private:
  int direction(struct point pi, struct point pj, struct point pk){
    int normalize_pj_x = pj.x - pi.x;
    int normalize_pj_y = pj.y - pi.y;
    int normalize_pk_x = pk.x - pi.x;
    int normalize_pk_y = pk.y - pi.y;
    return ( normalize_pk_x*normalize_pj_y - normalize_pk_y*normalize_pj_x );
  }

  bool onSegment(struct point pi, struct point pj, struct point pk){
    if(min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= pk.y  && pk.y<= max(pi.y, pj.y)){
      return true;
    }
    return false;
  }
};


int main(){
  struct point p1 = {4, 0};
  struct point p2 = {4, 4};
  struct point p3 = {3, 2};
  struct point p4 = {2, 2};

  DoSegmentsIntersects intersects;
  bool doInt = intersects.segmentIntersects(p1, p2, p3, p4);

  cout << "intersects = "<< doInt << endl;

  return 0;
  
}

  
