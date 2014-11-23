#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct MaxHeap{
    int size;
    int *num;
}heap;

void *swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheapify(heap *h, int index){
    int largest = index;
    int right = 2*index+2;
    int left = 2*index+1;
    
    if(left < h->size && h->num[left] > h->num[largest]){
        largest = left;
    }
    if(right < h->size && h->num[right] > h->num[largest]){
        largest = right;
    }
    if(largest != index){
        swap(&h->num[largest],&h->num[index]);
        maxheapify(h,largest);
    }
}

heap *buildMaxheap(int *t_num, int t_size){
    heap *newHeap = (heap*)malloc(sizeof(heap));
    newHeap->size = t_size;
    newHeap->num = t_num;
    for(int i = (newHeap->size-2)/2; i>=0; i--){
        maxheapify(newHeap,i);
    }
    return newHeap;
}

void heapSort(int *num, int t_size){
    heap *h = buildMaxheap(num,t_size);
    while(h->size > 1){
        swap(&h->num[0],&h->num[h->size-1]);
        h->size--;
        maxheapify(h,0);
        
    }
}

int main()
{
   int num[10] = {9,8,7,6,5,4,3,2,1,0};
   heapSort(num,10);
   for(int i = 0; i < 10; i++){
       printf("%d\n",num[i]);
   }
   return 0;
}
