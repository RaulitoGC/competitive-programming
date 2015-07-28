#include <iostream>
#include <string>
using namespace std;

int i,j;

bool isReverse(string S, string T){
	if(S.size()!=T.size()) return false;
	for (i = 0,j=S.size()-1; i < S.size(); i++,j--){
		if(S[i]!=T[j]) return false;
	}
	return true;
}


int main(){

	string S;
	string T;
	while(cin>>S>>T){
		if(isReverse(S,T)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}