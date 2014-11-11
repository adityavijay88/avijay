#include <stdio.h>
#include <string.h>

int LIS(int num[], int l, int h){
    int i = 0;
    int j = 0;
    int ret = 0;
    int best[h-l+1];
    for(i=0;i<h-l+1;i++){
        best[i] = 1;
    }
    for(i=0;i<=h;i++){
        for(j=0;j<i;j++){
            if(num[i] > num[j] && best[i] < best[j] + 1){
                best[i] = best[j] + 1;
            }
        }
    }
    for(i=0;i<10;i++){
        ret = (ret>best[i])?ret:best[i];
    }
    return ret;
}

main()
{
   int num[10] = {14,12,16,18,10,11,13,10,15,19};
   int ret = LIS(num,0,9);
   printf("Longest incresing seq length is: %d\n",ret);
   return;
}
