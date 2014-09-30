#include <stdio.h>
#include <string.h>

main()
{
   int number = 100;
   int i = 0;
   int temp = number;
   
   while(temp){
       if(temp%2){
           printf("1\n");
       }else{
           printf("0\n");
       }
       temp = temp/2;
   }
   
   return 0;
}
