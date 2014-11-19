#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *alterString(char *name){
    char *newName = (char *)malloc(sizeof(char)*strlen(name));
    newName[strlen(name)] = '\0';
    
    int i = 0;
    int j = 0;
    int cnt = 0;
    
    while(name[i] != '\0'){
        cnt = 0;
        newName[j] = name[i];
        while(name[i] == name[i+1]){
            i++;
            cnt++;
        }
        
        newName[j+1] = cnt+1 + '0';
        j = j+2;
        i++;
    }
    
    newName[j] = '\0';
    return newName;
}

int main(){
    char name[100] = "aaabbbdddeefdgdfgnjnnndf";
    char *newName;
    newName = alterString(name);
    printf("%s\n",newName);
    return 0;
}
