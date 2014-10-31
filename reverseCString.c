#include <stdio.h>
#include <string.h>

void reverse(char *string){
    int i = 0;
    int j = strlen(string)-1;
    char ch = ' ';
    while(i<j){
        ch = string[i];
        string[i] = string[j];
        string[j] = ch;
        i++; j--;
    }
}


int main(){
    char name[10] = "Aditya";
    reverse(name);
    printf("%s\n",name);
    return 0;
}
