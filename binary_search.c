#include <stdio.h>
#include <string.h>

int foo(int A[], int low, int high, int obj){
    while(low<high){
        if(obj > A[high] || obj <A[low]){
            return 0;
        }
        int middle = (low+high)/2;
        if(A[middle] == obj) return 1;
        if(obj < A[middle]){
            high = middle;
        }else{
            low = middle;
        }
    }
    return 0;
}
int binSearch(int A[], int obj){
    int result = foo(A, 0,9, obj);
    return result;
}
main()
{
   int A[10] = {0,1,2,3,4,5,6,7,8,9};
   int res = binSearch(A, 1);
   if(res){
       printf("Number found!\n");
   }else{
       printf("Number not found!\n");
   }
   return 0;
}
