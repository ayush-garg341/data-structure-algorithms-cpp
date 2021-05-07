#include<stdio.h>
#include<stdlib.h>
#include "random_shuffle.h"

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


void QuickSelect(int arr[], int low, int high, int kthSmallest){
  if(high <= low){
    return;
  }
  int j = Partition(arr, low, high);
  if(j==kthSmallest){
    return;
  }
  else if(kthSmallest > j){
    QuickSelect(arr, j+1, high, kthSmallest);
  }
  else if(kthSmallest < j){
    QuickSelect(arr, low, j-1,  kthSmallest);
  }
}


int main(){
  int A[] = {10, 11, 9, 12, 19, 15, 13, 20, 21, 8, 4};
  int arr_size  = sizeof(A)/sizeof(int);
  int kthSmallest;

  randomize(A, arr_size);

  printf("Enter the kth Smallest element you want to find\n");
  scanf("%d", &kthSmallest);

  if(kthSmallest>arr_size){
    printf("Enter valid kth smallest element position that you want to find\n");
  }
  
  QuickSelect(A, 0, arr_size-1, kthSmallest-1);
  printf("%d is the %dthSmallest element in an array\n", A[kthSmallest-1], kthSmallest);
  return 0;
}
