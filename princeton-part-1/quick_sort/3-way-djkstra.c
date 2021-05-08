#include<stdio.h>
#include<stdlib.h>
#include "random_shuffle.h"


void Print(int arr[], int n){
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void RandomizedSort(int arr[], int low, int high){
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
  
  RandomizedSort(arr, low, lt-1);
  RandomizedSort(arr, gt+1, high);
}


int main(){
  int A[] = {11, 11, 3, 4, 8, 2, 1, 11, 10, 3, 9, 10, 10, 20, 20, 21, 31};
  int arr_size  = sizeof(A)/sizeof(int);
  randomize(A, arr_size);

  printf("========== Original Array ============\n");
  Print(A, arr_size);

  RandomizedSort(A, 0, arr_size-1);

  printf("=========== Sorted Array ===============\n");

  Print(A, arr_size);
  
  return 0;
}
