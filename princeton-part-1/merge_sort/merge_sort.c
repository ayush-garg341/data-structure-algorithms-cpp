#include<stdio.h>
#include<stdlib.h>
#include"merge_sort.h"

void MergeSort(int A[], int low, int high, int size){
  if(low < high){
    int mid = (low + high)/2;
    MergeSort(A, low, mid, size);
    MergeSort(A, mid+1, high, size);
    Sort(A, low, mid, high, size);
  }
}


void Sort(int A[], int low, int mid, int high, int size){
  int auxArr[size];
  int k = 0;
  int i = low;
  int j = mid + 1;
  while(i <= mid && j <= high){
    if(A[j] < A[i]){
      auxArr[k++] = A[j++];
    }
    else {
      auxArr[k++] = A[i++];
    }
  }

  while(i<=mid){
    auxArr[k++] = A[i++];
  }

  while(j<=high){
    auxArr[k++] = A[j++];
  }

  for(i=high; i >= low; i--)
    {
        A[i] = auxArr[--k];  
    }
}


void PrintArray(int A[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}



int main(){
  int A[] = {4, 8, 10, 9, 5, 6, 7, 11, 1, 3};
  int low = 0;
  int high = sizeof(A)/sizeof(int);
  MergeSort(A, low, high-1, high);
  PrintArray(A, high);
  return 0;
}
