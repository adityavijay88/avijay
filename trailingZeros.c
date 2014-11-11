/*AUTHOR: avijay@usc.edu
  DATE: 11/10/2014
*/

#include <stdio.h>
#include <string.h>

int numZeros(int n){
    int ret = 0;
    int i = 0;
    for(i=5;n/i>=1;i*=5){
        ret += n/i;
    }
    return ret;
}
main()
{
   int n = 12;
   int ret = numZeros(n);
   printf("%d\n",ret);
   return;
}
