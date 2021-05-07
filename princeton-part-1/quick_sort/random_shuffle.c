#include<stdlib.h>
#include <time.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}


void randomize(int arr[], int n){
  //Use a different seed value so that we don't get same
  // result each time we run this program
  srand ( time(NULL) );
  
  for (int i = n-1; i > 0; i--)
    {
      // Pick a random index from 0 to i
      int j = rand() % (i+1);
      swap(&arr[i], &arr[j]);
    }
}
