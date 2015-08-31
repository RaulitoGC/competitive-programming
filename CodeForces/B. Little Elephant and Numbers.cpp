#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool compare(vector<int> v, vector<int> temp){
	int l = v.size();
	int ltemp=temp.size();
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < ltemp; ++j){
			if(v[i]==temp[j]) return true;
		}
	}

	return false;
}

void digits(long long n,vector<int> &v){
	
	while(n){
		v.push_back(n%10);
		n/=10;
	}

}

bool haveOne(long long n){
	while(n){
		if(n%10 == 1) return true;
		n/=10;
	}
	return false;
}

void show(vector<int> v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int cont,l;
	long long n;
	vector<int> v,temp;
	while(cin>>n){
		cont=0;
		digits(n,v);
		l =sqrt(n);
		for (long long i = 1; i < l; ++i){
			if(n%i == 0){
				digits(i,temp);
				if(compare(v,temp)) cont++;	
				temp.clear();
				digits(n/i,temp);
				if(compare(v,temp)) cont++;
				temp.clear();
			}
		}
		if(l*l == n || n%l== 0){
			digits(l,temp);
			if(compare(v,temp)) cont++;
			temp.clear();
			if(l*l!=n){
				digits(n/l,temp);
				if(compare(v,temp)) cont++;
				temp.clear();
			}

		}
		if(n==2 || n==3){
			cout<<1<<endl;
		}else{
			if(cont==2){
				if(haveOne(n)) cout<<2<<endl;
				else cout<<1<<endl;
			}else{
				cout<<cont<<endl;	
			}		
		}
		

		
		v.clear();
		
	}

	return 0;
}
