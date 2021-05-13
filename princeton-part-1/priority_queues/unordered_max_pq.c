#include <stdio.h>
#include "pq.h"

int N = 0;

int isEmpty(){
  return N==0;
}

void insert(int A[], int element){
  A[N++] = element;
}

int deleteElem(int A[]){
  int max_index = 0;
  for(int i = 1; i < N; i++){
    if(A[max_index] < A[i]){
      max_index = i;
    }
  }
  exchange(&A[max_index], &A[N-1]);
  int max = A[N-1];
  N = N-1;
  return max;
}

int main(){

  int capacity = 20;
  int A[capacity];

  insert(A, 5);
  insert(A, 10);
  insert(A, 3);
  insert(A, 20);
  insert(A, 18);
  
  int deleted_elem = deleteElem(A);

  printf("delete number is %d\n", deleted_elem);

  printf("size of the array is %d\n", N);

  printArray(A, N);

  deleted_elem = deleteElem(A);

  printf("delete number is %d\n", deleted_elem);

  printf("size of the array is %d\n", N);

  printArray(A, N);
  
  return 0;
}
