/*AUTHOR: avijay@usc.edu
  DATE: 11/10/2014
*/

#include <stdio.h>
#include <string.h>

int getMax(int n1, int n2){
    int c = n1-n2;
    int k = (c>>31)&0x01;
    int max = n1 - k*c;
    return max;
}

main()
{
   int n1 = -2;
   int n2 = -1;
   int ret = getMax(n1,n2);
   printf("The max of the two is: %d\n",ret);
   return;
}
