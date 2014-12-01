#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int num[], int low, int high){
	int right = high;
	int left = low;
	int pivot = low;
	int pivot_val = num[pivot];
	
	while(left<right){
		while(num[left] <= pivot_val) left++;
		while(num[right] > pivot_val) right--;
		if(left<right){
			swap(&num[right], &num[left]);
		}
	}
	num[low] = num[right];
	num[right] = pivot_val;
	return right;
}

void sort(int num[], int low, int high){
	if(low<high){
		int p = partition(num, low, high);
		sort(num, low, p-1);
		sort(num, p+1, high);
	}
}

int main(){
	int num[10] = {9,8,7,6,5,4,3,2,1,0};
	sort(num,0,9);
	for(int i=0; i<10;i++){
		printf("--- %d\n",num[i]);
	}
	return 0;
}
