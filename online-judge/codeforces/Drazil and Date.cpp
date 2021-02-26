#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long a,b,s;

	while(cin>>a>>b>>s){
		a=abs(a);
		b=abs(b);
		s=abs(s);
		if((a+b==s) || ((a+b)%2==0 && s%2==0 && s>=a+b) || ((a+b)%2!=0 && s%2!=0 && s>=a+b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}