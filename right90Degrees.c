#include <stdio.h>
#include <string.h>



int main()
{
   int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   int i = 0;
   int j = 0;
   for(i=0;i<3;i++){
       for(j=0;j<3;j++){
           printf("%d ",A[i][j]);
       }
       printf("\n");
   }
   printf("================\n");
   int temp = 0;
   for(i=0;i<(3/2);i++){
   	for(j=0;j<(3+1)/2;j++){
   		temp = A[i][j];
   		A[i][j] = A[3-1-j][i];
   		A[3-1-j][i] = A[3-1-i][3-1-j];
   		A[3-1-i][3-1-j] = A[j][3-1-i];
   		A[j][3-1-i] = temp;
   	}
   }
   
   for(i=0;i<3;i++){
       for(j=0;j<3;j++){
           printf("%d ",A[i][j]);
       }
       printf("\n");
   }
   
   return 0;
}
