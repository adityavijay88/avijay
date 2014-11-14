#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool myfunction(string a, string b){
    return a.size() > b.size();
}

bool util(string str, bool isOriginalWord, map<string, bool> &mymap){
    if(!isOriginalWord && mymap.find(str) != mymap.end()){
        return true;
    }
        for(int i=1; i<str.size();i++){
            string left = str.substr(0,i);
            string right = str.substr(i,str.size());
            if(mymap.find(right) != mymap.end() && util(right,false,mymap)){
                return true;
            }
        }
    mymap[str] = false;
    return false;
}
int main()
{
    vector <string> list;
    list.push_back("cat");
    list.push_back("dog");
    list.push_back("walkcatdograt");
    list.push_back("catdogwalk");
    list.push_back("rat");
    
    map <string, bool> mymap;
    
    for(int i=0; i<5;i++){
        mymap[list[i]] == true;
    }
    
    sort(list.begin(), list.end(),myfunction);
    
    for(int i=0; i<list.size();i++){
        if(util(list[i],true,mymap)){
            cout<< "The longest possible string is: "<<endl;
            cout<<list[i]<<endl;
            return 0;
        }
    }
    
   return 0;
}
