#include<stdio.h>
#include "pq.h"
#define CAPACITY 17

int present_elem = 0;


void insert(int heap[], int elem){
  if(present_elem >= CAPACITY - 1){
    printf("HEAP is full, further elements can not be added\n");
    return;
  }
  
  heap[++present_elem] = elem;
  if(present_elem==1){
    return;
  }
  else{
    swim(heap, present_elem);
  }
}


int deleteHeap(int heap[]){
  if(present_elem==0){
    printf("Heap is empty, no elements to delete\n");
    return 0;
  }
  else if(present_elem==1){
    return heap[present_elem--];
  }
  else if(present_elem==2){
    exchange(&heap[1], &heap[present_elem]);
    return heap[present_elem--];
  }

  exchange(&heap[1], &heap[present_elem]);
  
  sink(heap, present_elem);

  return heap[present_elem--];
  
}


int main(){
  int heap[CAPACITY];

  insert(heap, 15);
  insert(heap, 20);
  insert(heap, 18);
  insert(heap, 29);
  insert(heap, 30);
  insert(heap, 25);
  insert(heap, 22);
  insert(heap, 31);

  printHeap(heap, present_elem);

  int deleted_elem = deleteHeap(heap);
  printf("deleted element from heap is %d\n", deleted_elem);

  printHeap(heap, present_elem);

  deleted_elem = deleteHeap(heap);
  printf("deleted element from heap is %d\n", deleted_elem);

  printHeap(heap, present_elem);
  
  return 0;
}
