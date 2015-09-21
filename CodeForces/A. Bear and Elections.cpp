#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int a,sum,temp;
	while(cin>>a){
		temp = -1;
		sum=0;
		vector<int> v(a,0);
		cin>>v[0];
		for (int i = 1; i < a; ++i){
			cin>>v[i];
			//sum+=v[i];
			temp = max(temp,v[i]);
		}
		int cont=0;
		while(temp > v[0]){
			for (int i = 1; i < a ;++i){
				if(v[i]){
					v[i]--;
					temp--;
					v[0]++;
					cont++;
					if(v[0] > temp) break;
				} 
			}
			cout<<" "<<v[0]<<" "<<temp<<endl;
		}
			
		cout<<cont<<endl;
		

	}
	return 0;
}