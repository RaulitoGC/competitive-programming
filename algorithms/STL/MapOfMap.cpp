#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<int, map<int,string> > mymap;

    mymap[1][3] = "hello1";
    mymap[1][4] = "Hello2";
    mymap[4][5] = "Hello3";
    mymap[2][7] = "Hello4";
    mymap[3][8] = "Hello5";

	typedef map<int, string> inner_map;
	typedef map<int, inner_map> outer_map;

	for (outer_map::iterator i = mymap.begin(), iend = mymap.end(); i != iend; ++i){
	    inner_map &innerMap = i->second;
	    for (inner_map::iterator j = innerMap.begin(), jend = innerMap.end(); j != jend; ++j){
	        cout<<"["<<i->first<<"]"<<"["<<j->first<<"] = "<<j->second<<endl;
	    }
	}

    return 0;
}