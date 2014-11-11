/*AUTHOR: avijay@usc.edu
  DATE: 11/10/2014
*/

#include <stdio.h>
#include <string.h>

int m = -1;
int n = -1;

void getIndex(int num[]){
    int i = 0;
    int j = 0;
    int k = 0;
    int min = 0;
    int max = 0;
    /*get right first unsorted point*/
    for( i=1;i<13;i++){
        if(num[i] < num[i-1]){
            break;
        }
    }
    while(i){
        if(num[i] > num[i-1]){
            break;
        }
        i--;
    }
    min = num[i];
    
    /*get left first unsorted point*/
    for(j = 11; j>0; j--){
        if(num[j+1] < num[j]){
            break;
        }
    }
    while(j<13){
        if(num[j] > num[j+1]){
            break;
        }
    }
    max = num[j];
    //printf("max = %d, min = %d\n",max,min);
    /*get max and min from this array*/
    for(k=i;k<j;k++){
        if(num[k] > max){
            max = num[k];
        }
        if(num[k] < min){
            min = num[k];
        }
    }
    //printf("max = %d, min = %d\n",max,min);
    /*get left stretched point*/
    for(i=0;i<13;i++){
        if(num[i] > min){
            break;
        }
    }
    m = i;
    /*get right stretched point*/
    for(j=12;j>0;j--){
        if(num[j] < max){
            break;
        }
    }
    n = j;
}

int main()
{
    int num[13] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    getIndex(num);
    printf("m: %d, n: %d\n",m,n);
   return 0;
}
