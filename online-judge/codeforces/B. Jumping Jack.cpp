#include <iostream>
using namespace std;

long long n,cont;

void jump(long long x, long long level){
	if( n == (x+level) || n == (x-level)) return ;
	cout<<x+level<<" "<<x-level<<endl;
	cont++;
	jump(x+level,level++);
	jump(x-level,level++);
}

int main(){
	
	while(cin>>n){
		cont = 0;
		jump(0,0);
		cout<<cont<<endl;
	}
	return 0;
}