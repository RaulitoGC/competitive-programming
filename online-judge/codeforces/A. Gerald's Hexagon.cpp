#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int a1,a2,a3,a4,a5,a6;
	while(cin>>a1>>a2>>a3>>a4>>a5>>a6){
		
		int borders = a1*a2 + a3*a4 + a5*a6;
		borders<<=1;
		int rest = (a1>a4)? a1-a4:a4-a1;
		cout<<borders+rest*rest<<endl;
		}
	
	return 0;
	}
