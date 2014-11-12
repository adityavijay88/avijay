#include <stdio.h>
#include <string.h>

int main()
{
    char *num = "2332";
    char *units[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    char *teens[] = {" ","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                    "seventeen","eighteen","nineteen"};
    char *tens[] = {" ", " ","twenty","thirty","fourty","fifty","sixty","seventy",
                    "eighty","ninety"};
    char *tens_power[] = {"hundred","thousand"};
    int len = strlen(num);
    
    /*code supports only 4 digits numbers*/
    if(len == 0 || len > 4){
        printf("Invalid number to process!\n");
        return;
    }
    while(*num != '\0'){
        if(len >=3){
            int i = *num - '0';
            if(i != 0){
                printf("%s ", units[*num - '0']);
                printf("%s ", tens_power[len-3]);
            }
            len--;
        }else{
            if(*num == 1){
                int i = *num-'0'+*(num+1)-'0';
                printf("%s ",teens[i]);
                return;
            }else if(*num == '2' && *(num+1) == '0'){
                printf("twenty ");
                return;
            }else{
              int i = *num - '0';
              printf("%s ",i?tens[i]: " ");
              ++num;
              if(*num != '\0'){
                  printf("%s ",units[*num-'0']);
              }
            }
        }
        num++;
    }
   return 0;
}
