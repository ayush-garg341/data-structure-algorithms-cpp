using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    int result = countRibbonPiecesRecursive(ribbonLengths, total, 0);
    return result == numeric_limits<int>::min() ? -1 : result;
  }

  int countRibbonPiecesRecursive(const vector<int> &ribbonLengths, int total, int currentIndex){
    if(total==0){
      return 0;
    }

    if(ribbonLengths.size()==0 || currentIndex >= ribbonLengths.size()){
      return numeric_limits<int>::min();
    }

    int count1 = numeric_limits<int>::min();
    if(ribbonLengths[currentIndex] <= total){
      int res = countRibbonPiecesRecursive(ribbonLengths, total-ribbonLengths[currentIndex], currentIndex);
      if(res != numeric_limits<int>::min()){
	count1 = res + 1;
      }
    }

    int count2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex + 1);

    return max(count1, count2);
  }
  
};

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{3, 5, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
  return 0;
}
