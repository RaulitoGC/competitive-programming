#include <iostream>
using namespace std;

long long n;

long long BinaryTree(long long init){
	int cont = 1;
	if(n<init) return 0 ;
	
	cont+=BinaryTree(init*10);
	cont+=BinaryTree(init*10 + 1);
	return cont;
}


int main(){
	while(cin>>n){
		cout<<BinaryTree(1)<<endl;
	}
	return 0;
}

