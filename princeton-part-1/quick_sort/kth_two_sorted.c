#include<stdio.h>

int kthSmallest(int A[], int m, int B[], int n, int k_req){
  int i,j,k;
  i = j = k = 0;
  while(i<m && j<n){
    if(A[i] < B[j]){
      if(k==k_req){
	return A[i];
      }
      i++;
      k++;
    }
    else{
      if(k==k_req){
	return B[j];
      }
      j++;
      k++;
    }
  }

  while(i<m){
    if(k==k_req){
      return A[i];
    }
    i++;
    k++;
  }


  while(j<n){
    if(k==k_req){
      return B[j];
    }
    j++;
    k++;
  }
  
}

int main(){
  int A[] = {2,4,6,8,10};
  int B[] = {1,3,5,7,9};
  int k_req = 6;
  
  int kth_smallest = kthSmallest(A, 5 ,B, 5, k_req-1);

  printf("%d\n", kth_smallest);
  
  return 0;
}
