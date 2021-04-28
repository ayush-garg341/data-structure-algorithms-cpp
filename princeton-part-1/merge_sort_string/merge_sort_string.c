#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"merge_sort_string.h"

# define MAX_STRING_SIZE 20

void MergeSortString(char (*arr)[20], int low, int high, int size){
  if(low < high){
    int mid = (low + high)/2;
    MergeSortString(arr, low, mid, size);
    MergeSortString(arr, mid+1, high, size);
    MergeString(arr, low, mid, high, size);
  }
}


void MergeString(char (*arr)[20], int low, int mid, int high, int size){
  char auxArr[size][20];
  int k = 0;
  int i = low;
  int j = mid + 1;
  while(i <= mid && j <= high){
    if(strcmp(arr[j], arr[i])<0){
      strcpy(auxArr[k++], *(arr + j));
      j++;
    }
    else {
      strcpy(auxArr[k++], *(arr + i));
      i++;
    }
  }

  while(i<=mid){
    strcpy(auxArr[k++], *(arr + i));
    i++;
  }

  while(j<=high){
    strcpy(auxArr[k++], *(arr + j));
    j++;
  }

  for(i=high; i >= low; i--)
    {
      k--;
      strcpy(*(arr + i), auxArr[k]);
    }
}


void PrintArray(char (*arr)[20], int size){
  for(int i=0; i<size; i++){
    printf("%s ", *(arr + i));
  }
  printf("\n");
}



int main(){
  char arr[7][MAX_STRING_SIZE] = {
				 "Ayush",
				 "Arnim",
				 "Vishal",
				 "Udit",
				 "Ritik",
				 "Aryan",
				 "Abhinav"
				 
  };
  int low = 0;
  int high = 7;
  for(int i=0; i<7; i++){
    printf("%s ", arr[i]);
  }
  printf("\n");
  MergeSortString(arr, low, high-1, high);
  PrintArray(arr, high);
  return 0;
}
