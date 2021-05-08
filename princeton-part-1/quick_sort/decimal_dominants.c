/* Given an array with nn keys, design an algorithm to find all values that occur more than n/10n/10 times. */

#include<stdio.h>
#include<stdlib.h>
#include "random_shuffle.h"


void Print(int arr[], int n){
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void RandomizedSort(int arr[], int low, int high, int repeated_more_than){
  if(high <= low){
    return;
  }
  int v = arr[low];
  int i = low+1;
  int gt = high;
  int lt = low;

  while(i <= gt){
    if(arr[i] < v){
      swap(&arr[i], &arr[lt]);
      i++;
      lt++;
    }
    else if(arr[i] > v){
      swap(&arr[i], &arr[gt]);
      gt--;
    }
    else{
      i++;
    }
  }

  if( (gt-lt+1) > repeated_more_than){
    printf("%d is repeated more than %d i.e. %d times \n", arr[lt] , repeated_more_than, gt-lt+1);
  }
  
  RandomizedSort(arr, low, lt-1, repeated_more_than);
  RandomizedSort(arr, gt+1, high, repeated_more_than);
}


int main(){
  int A[] = {11, 11, 3, 4, 8, 2, 1, 11, 10, 3, 9, 10, 10, 20, 20, 21, 31, 35, 11, 12, 11, 40, 10, 23, 10, 20, 3};
  int arr_size  = sizeof(A)/sizeof(int);
  randomize(A, arr_size);

  int repeated_more_than = arr_size/10;

  printf("========== Original Array ============\n");
  Print(A, arr_size);

  RandomizedSort(A, 0, arr_size-1, repeated_more_than);

  printf("=========== Sorted Array ===============\n");

  Print(A, arr_size);
  
  return 0;
}
