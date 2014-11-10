#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

string decToBin(int i){
    string str;
    while(i != 0){
        if(i%2 == 0){
            str = str + '0';
        }else{
            str = str + '1';
        }
        i = i >> 1;
    }
    return str;
}
void generateSubset(int set[], int max){
    string str;
    vector<vector<int> > result;
    vector<int>temp;
    int j = 0;
    for(int i=0;i<pow(2,max);i++){
        str = decToBin(i);
        cout<<str<<endl;
        j = 0;
        while(j<str.size()){
            if(str[j] == '1'){
                temp.push_back(set[j]);
            }
            j++;
        }
        result.push_back(temp);
        temp.clear();
    }
    cout<<"------"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"[";
        for(int j=0; j<result[i].size();j++){
            cout << result[i][j];
        }
        cout<<"]";
        cout<<endl;
    }
}
int main()
{
   int set[3] = {1,2,3};
   generateSubset(set,3);
   return 0;
}
