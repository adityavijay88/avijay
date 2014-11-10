#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void gp(string str, int l, int h,int &n, vector<string>&res){
    if(l>n) return;
    if(l==n && h==n){
        res.push_back(str);
    }else{
        gp(str+"(",l+1,h,n,res);
        if(l>h){
            gp(str+")",l,h+1,n,res);
        }
    }
}

void generateP(int n){
    vector<string>res;
    if(n==0) return ;
    gp("",0,0,n,res);
    
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
int main()
{
   generateP(3);
   return 0;
}
