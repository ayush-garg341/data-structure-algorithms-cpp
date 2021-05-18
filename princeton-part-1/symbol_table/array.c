#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototype.h"

struct st{
  char *key;
  int value;
};

void insertArray(struct st symbol_table[], char *x, int val){
  symbol_table[val-1].key = (char *)x;
  symbol_table[val-1].value = val;
}


void MergeString(struct st symbol_table[], int low, int mid, int high, int size){
  struct st auxArr[size];
  int k = 0;
  int i = low;
  int j = mid + 1;
  while(i <= mid && j <= high){
    if(strcmp((char *)symbol_table[j].key, (char *)symbol_table[i].key ) < 0){
      auxArr[k++] = symbol_table[j];
      j++;
    }
    else {
      auxArr[k++] = symbol_table[i];
      i++;
    }
  }

  while(i<=mid){
    auxArr[k++] = symbol_table[i];
    i++;
  }

  while(j<=high){
    auxArr[k++] = symbol_table[j];
    j++;
  }

  for(i=high; i >= low; i--)
    {
      k--;
      symbol_table[i] = auxArr[k];
    }
}



void sortKeys(struct st symbol_table[], int low, int high, int size){
  if(low < high){
    int mid = (low + high)/2;
    sortKeys(symbol_table, low, mid, size);
    sortKeys(symbol_table, mid+1, high, size);
    MergeString(symbol_table, low, mid, high, size);
  }
}


void printKey(struct st symbol_table[], int size){
  for(int i = 0; i<size; i++){
    printf("%s ", (char *)symbol_table[i].key);
  }
  printf("\n");
  for(int i = 0; i<size; i++){
    printf("%d ", symbol_table[i].value);
  }
  
  printf("\n");
}



int binarySearch(struct st symbol_table[], char* key_to_find, int low, int high){

  printf("low = %d, high = %d\n", low, high);
  
  int middle = ( low + high ) / 2;

  int string_comp = strcmp((char *)symbol_table[middle].key, key_to_find);

  if(low > high){
    return -1;
  }
  
  if( string_comp == 0 ){
    return middle;
  }
  else if (string_comp < 0){
    binarySearch(symbol_table, key_to_find, middle+1, high);
  }
  else if(string_comp > 0){
    binarySearch(symbol_table, key_to_find, low, middle-1);
  }
  
}



int main(){

  struct st symbol_table[11];
  insertArray(symbol_table, (char *)"first", 1);
  insertArray(symbol_table, (char *)"second", 2);
  insertArray(symbol_table, (char *)"third", 3);
  insertArray(symbol_table, (char *)"fourth", 4);
  insertArray(symbol_table, (char *)"fifth", 5);
  insertArray(symbol_table, (char *)"sixth", 6);
  insertArray(symbol_table, (char *)"seventh", 7);
  insertArray(symbol_table, (char *)"eighth", 8);
  insertArray(symbol_table, (char *)"ninth", 9);
  insertArray(symbol_table, (char *)"tenth", 10);
  insertArray(symbol_table, (char *)"elevent", 11);

  sortKeys(symbol_table, 0, 10, 11);

  printKey(symbol_table, 11);

  int key_pos = binarySearch(symbol_table, (char *)"fourth", 0, 10);

  if(key_pos==-1){
    printf("key not found\n");
    return 0;
  }
  
  printf("key position is %d\n", key_pos+1);

  key_pos = binarySearch(symbol_table, (char *)"third", 0, 10);

  if(key_pos==-1){
    printf("key not found\n");
    return 0;
  }
  
  printf("key position is %d\n", key_pos + 1);


  key_pos = binarySearch(symbol_table, (char *)"sdhbfdsjhjbwejhbcewjdhew", 0, 10);
  if(key_pos==-1){
    printf("key not found\n");
    return 0;
  }
  
  return 0;
}
