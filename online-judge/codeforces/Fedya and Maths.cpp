#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

	string n;
	while(cin>>n){
		if(n.size()==1){
			if(n=="4" || n=="8" || n=="0") cout<<4<<endl;
			else cout<<0<<endl;
		}else{
			n = n.substr(n.size() - 2);
			stringstream ss;
			int temp;
			ss<<n;
			ss>>temp;
			if(temp%4==0) cout<<4<<endl;
			else cout<<0<<endl;	
		}
		
	}
	return 0;
}