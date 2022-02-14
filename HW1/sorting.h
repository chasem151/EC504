#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

using namespace std;

static int swapCount = 0;

void swap(int* a, int* b)
{
    //swapCount++;
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}


/* See Knuth's shuffles https://en.wikipedia.org/wiki/Random_permutation */



void insertionsort(int a[],  int n)
{ 
// You program this
  int j, temp;
  for(int i = 0; i < n; i++){
    temp = a[i];
    j = i-1;
    while((temp < a[j]) && (j >= 0)){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
  }
}



// Order Theta(NlogN) sorting


void mergeSort(int a[], int a_tmp[], int l, int r)
{
    // you program this.  a_tmp can be used for merging 
    int i, j, k;
    if (r < l){
      int mid = (l+r)/2;
      mergeSort(a, a_tmp, l, mid);
      mergeSort(a, a_tmp, mid+1, r);
      for(i=mid+1; i>l; i--){
        a_tmp[i-1] = a[i-1];
      }
      for(j=mid; j<r; j++){
        a_tmp[r+mid-j] = a[j+1];
      }
      for(k=l; k<=r; k++){
        if (a_tmp[i] < a_tmp[j]){
          a[k] = a_tmp[i++];
        }
        else if (a_tmp[i] >= a_tmp[j]){
          a[k] = a_tmp[j--];
        }
      }
    }
  }

// 
void mergeSortblend(int a[], int a_tmp[], int l, int r)
{
 // You program this
 int i,j,k, mid;
 
 if (r <= l){
   return;
 }
 if (r-l > 32){
   mid = (l+r)/2;
   mergeSortblend(a,a_tmp, l, mid);
   mergeSortblend(a,a_tmp, mid+1, r);
   for(i=mid+1; i>l; i--){
     a_tmp[i-1] = a[i-1];
   }
   for(j=mid;j<r;j++){
     a_tmp[r+mid-j] = a[j+1];
   }
   for(k=l;k<=r;k++){
     if(a_tmp[i] < a_tmp[j]){
       a[k] = a_tmp[i++];
     }
     else if(a_tmp[j] <= a_tmp[i]){
       a[k] = a_tmp[j--];
     }
   }
 }
 else{
   for(i=l+1;i<=r;i++){
     k = a[i];
     j = i-1;
     while(j>=l && a[j] > k){
       a[j+1] = a[j];
       j--;
     }
     a[j+1] = k;
   }
 }
}

void checkInorder(int a[],int left, int right){
  //checks  that a is in order from left to right
  for (int i = left;i <right; i++){
    if (a[i] > a[i+1]){
      int tmp = i;
    }
  }
}
void simpleTimsort(int a[], int a_tmp[], int n)
{ 
   //You program this
  const int mrun = 32;
  int runstack[6000];
  int perstack=0;
  runstack[perstack] = 0;
  int i, j, z, key, l, m, r;
  int c=1;
  int run[n];
  int lastprevious, last;
  for(z=1;z<n;z++){
    if(z==0){
        run[z] = a[z];
        c++;
    }
    else{
      if(a[z] >= run[z-1]){
        run[z] = a[z];
        c++;
      }
      else{
        if(c < mrun){
          int j = z;
          int temp = a[z];
          while((temp < run[z-1]) && (j>= runstack[perstack])){
            run[j] = temp;
            j--;
          }
          run[j] = temp;
          c++;
        }
        else{
          c = 1;
          perstack++;
          runstack[perstack] = z;
          run[z] = a[z];
        }
      }
    }
    if(z == n-1){
      perstack++;
      runstack[perstack] = n;
    }

  while(perstack > 1){
    i = runstack[perstack-2];
    j = runstack[perstack-1];
    k = i;
    int v = i;
    int l = j;
    r = n;
    for (i=i; i<l;i++){
      if(j >= n){
        break;
      }
      if(run[i] <= run[j]){
        a_tmp[k] = run[i];
        k++;
        continue;
      }
      else{
        a_tmp[k] = run[j];
        k++;
        j++;
      }
    }
    for(i=i;i<l;i++){
      a_tmp[k] = run[i];
      k++;
      j++;
    }
    while(j < n){
      a_tmp[k] = run[j];
      k++;
      j++;
    }
    perstack--;
    runstack[perstack] = n;
    copy(run, run+v, run);
    copy(a_tmp+v, a_tmp+n, run+v);
}
copy(a_tmp, a_tmp+n, a);
}// end function





#endif 
