#include<stdio.h>
#include<stdlib.h>
#include "random_shuffle.h"


void Print(int arr[], int n){
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}



int Partition(int arr[], int low, int high){
  int i = low+1;
  int j = high;
  while(1){
    while(arr[i] < arr[low]){
      i++;
      if(i>=high){
	break;
      }
    }

    while(arr[low] < arr[j]){
      j--;
      if(j<=low){
	break;
      }
    }

    if(i>=j){
      break;
    }
    swap(&arr[i], &arr[j]);
  }
  swap(&arr[j], &arr[low]);
  return j;
}


void QuickSort(int arr[], int low, int high){
  if(high <= low){
    return;
  }
  int j = Partition(arr, low, high);
  QuickSort(arr, low, j-1);
  QuickSort(arr, j+1, high);
}


int main(){
  int A[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  //int A[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int arr_size  = sizeof(A)/sizeof(int);
  randomize(A, arr_size);

  printf("========== Original Array ============\n");
  Print(A, arr_size);

  QuickSort(A, 0, arr_size-1);

  printf("=========== Sorted Array ===============\n");

  Print(A, arr_size);
  
  return 0;
}
