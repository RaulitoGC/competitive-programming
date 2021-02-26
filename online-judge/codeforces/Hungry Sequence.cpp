#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1300000

using namespace std;

bool v[N];

void criba (){
    memset (v, true, sizeof (v));
    v [0] = v [1] = false;
 
    for ( int i = 4; i < N; i += 2 )
        v [i] = false;
 
    for ( int i = 3; i * i <= N; i++ ) {
        if ( v [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                v [j] = false;
        }
    }
}

int main() {
	criba();
	unsigned long long n;
	long long cont;
	while(cin>>n){
		
		if(n<=6){ 
			if(n==1) cout<<2<<endl;	
			if(n==2) cout<<2<<" "<<3<<endl;
			if(n==3) cout<<2<<" "<<3<<" "<<5<<endl;
			if(n==4) cout<<2<<" "<<3<<" "<<5<<" "<<7<<endl;
			if(n==5) cout<<2<<" "<<3<<" "<<5<<" "<<7<<" "<<11<<endl;	
			if(n==6) cout<<2<<" "<<3<<" "<<5<<" "<<7<<" "<<11<<" "<<13<<endl;
		}else{
			cont=0;
			int i;
			for(i=7 ;cont<n ;i+=6){
				if(v[i]){
					cout<<i<<" ";
					cont++;	
				}
				if(v[i+4] && cont+1<n){
					cout<<i+4<<" ";
					cont++;	
				}
			}
		}
	}
	 
	return 0;
}

