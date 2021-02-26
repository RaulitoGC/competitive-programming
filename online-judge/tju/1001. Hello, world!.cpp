#include <iostream>

using namespace std;


int main(){
	int a;
	while(cin>>a){
		cout<<(char)a;;
		while(cin>>a && a!='\n'){
			cout<<(char)a;
		}
	}
	return 0;
}