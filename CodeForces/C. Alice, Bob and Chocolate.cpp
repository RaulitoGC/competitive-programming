#include <iostream>
using namespace std;

typedef long long ll;


int main(){

	int n,i,j;
	bool flag;
	while(cin>>n){
		ll v[n + 2],tempA,tempB;

		for (i = 1; i <= n; ++i){
			cin>>v[i];
		}
		if(n == 1) cout<<"1 0"<<endl;
		else{
			i = 1;
			j = n;
			tempA = 0;
			tempB = 0;
			while(i+1 != j){
				if(v[i] + tempA <= v[j] + tempB){
					tempA += v[i];
					i++;
				}
				else{
					tempB += v[j];
					j--;
				} 
					
			}				
			cout<<i<<" "<<n-i<<endl;	
		}
	
		
	
		
	}

	return 0;
}