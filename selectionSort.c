#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *num, int n){
    int m = 0;
    int i = 0;
    int j = 0;
    
    for(i= 0; i<n;i++){
        m = i;
        for(j=i; j<n;j++){
            if(num[m] > num[j]){
                m = j;
            }
        }
        swap(&num[m],&num[i]);
    }
}

int main()
{
   int num[10] = {9,8,7,6,5,4,3,2,1,0};
   int n = sizeof(num)/sizeof(num[0]);
   sort(num,n);
   for(int i = 0; i<10;i++){
       printf("%d\n",num[i]);
   }
   return 0;
}
