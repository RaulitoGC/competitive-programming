#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define MOD 256
map<char,int> TT;


int processChar(char c){
	if(TT[c]!=0) return TT[c];

}


void init(){
	for (int i = 32; i <= 126; ++i){
		TT[(char)i] = 0;
	}
}

int main(){
	
	string text;
	int l,i;
	init();
	while(getline(cin,text)){
		l = text.size();
		for (i = 0; i < l; ++i){
			cout<<processChar(text[i])<<endl;;
		}	
	}

	return 0;
}