#include <iostream>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

bool condition(int i, int j){
    cout<<i<<" "<<j<<endl;
    return true;
}

int main(){

    int n,k;
    int pi,ti;
    while(cin>>n>>k){
        map<int, map<int,int> > mymap;
        pair<int,int> mypair;
        while(n--){
            cin>>pi>>ti;
            mymap[pi][ti]++;

        } 

        typedef map<int, int> inner_map;
        typedef map<int, inner_map> outer_map;

        for (outer_map::iterator i = mymap.begin(), iend = mymap.end(); i != iend; ++i){
            inner_map &innerMap = i->second;
            for (inner_map::iterator j = innerMap.begin(), jend = innerMap.end(); j != jend; ++j){
                cout<<"["<<i->first<<"]"<<"["<<j->first<<"] = "<<j->second<<endl;
            }
        }  
    }
    return 0;
}