#include <stdio.h>
#include <string.h>

void merge(int array[], int low, int mid, int high){
    int i,j,k;
    int n1 = mid-low +1;
    int n2 = high-mid;
    int L[n1];
    int R[n2];
    
    for(i=0;i<n1;i++) L[i] = array[low+i];
    for(i=0;i<n2;i++) R[i] = array[mid+1+i];
    
    i = 0;
    j = 0;
    k = low;
    
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            array[k] = L[i];
            k++; i++;
        }else{
            array[k] = R[j];
            k++;j++;
        }
    }
    
    while(i<n1){
        array[k] = L[i];
        k++; i++;
    }
    
    while(j<n2){
        array[k] = R[j];
        k++; j++;
    }
}


void mergeSort(int array[], int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}


main(){
    int array[10] = {1,2,30,4,5,26,7,8,9,0};
    mergeSort(array,0,9);
    int i = 0;
    for(i = 0; i<10;i++){
        printf("Aditya: %d\n",array[i]);
    }
    return;
}
