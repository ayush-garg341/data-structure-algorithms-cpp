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



void printHeap(int heap[], int size){
  for(int i=1; i<=size; i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
}


int isLess(int a, int b){
  return a < b;
}

int isGreater(int a, int b){
  return a > b;
}


void swim(int heap[], int position){
  int k = position;
  while(k/2 >= 1){
    if(isLess(heap[k/2], heap[k])){
      exchange(&heap[k/2], &heap[k]);
      k = k/2;
    }
    else{
      break;
    }
  }
}


void sink(int heap[], int position){
  int present_elem = position;
  int k = 1;
  while(2*k+1 < present_elem){
    if(isLess(heap[2*k], heap[2*k + 1])){
      if(isLess(heap[k], heap[2*k + 1])){
	exchange(&heap[k], &heap[2*k + 1]);
	k = 2*k + 1;
      }
      else{
	break;
      }
    }
    else{
      if(isLess(heap[k], heap[2*k])){
	exchange(&heap[k], &heap[2*k]);
	k = 2*k;
      }
      else{
	break;
      }
    }
  }
}


void swimMin(int heap[], int position){
  int k = position;
  while(k/2 >= 1){
    if(isLess(heap[k], heap[k/2])){
      exchange(&heap[k/2], &heap[k]);
      k = k/2;
    }
    else{
      break;
    }
  }
}


void sinkMin(int heap[], int position){
  int present_elem = position;
  int k = 1;
  while((2*k+1) < present_elem){
    if(isLess(heap[2*k+1], heap[2*k])){
      if(isLess(heap[2*k+1], heap[k])){
	exchange(&heap[k], &heap[2*k + 1]);
	k = 2*k + 1;
      }
      else{
	break;
      }
    }
    else{
      if(isLess(heap[2*k], heap[k])){
	exchange(&heap[k], &heap[2*k]);
	k = 2*k;
      }
      else{
	break;
      }
    }
  }
}
