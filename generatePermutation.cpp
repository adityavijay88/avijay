#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int i = 1;


void permuteHelper(string prefix, string input){
    if(input.length() == 0){
        cout<< i++<<":";
        cout << prefix << endl;
    }else{
        for(int i=0;i<input.size();i++){
            permuteHelper(prefix + (input[i]),
                            input.substr(0,i)+(input.substr(i+1,input.length())));
        }
    }
}
void generatePermutation(string str){
    return permuteHelper("",str);
}
int main()
{
   string str = "adit";
   generatePermutation(str);
   return 0;
}
