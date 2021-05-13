#include<stdio.h>

void exchange(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}


void printArray(int A[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}
