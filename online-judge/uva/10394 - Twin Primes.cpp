#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
#define N 20000005
bool v[N];
long twinPrimes[N];  

void criba (){
    memset(v,true,sizeof(v));
    v[0]=v[1]=false;
 
    for(int i=4; i<N; i+=2)
        v[i]= false;
 
    for (int i = 3; i*i<=N; i++) {
        if ( v[i]) {
            for (int j=i*i; j<N; j+=2*i )
                v[j]=false;
        }
    }
}

void fillTwinPrimes(){
    long i,n=1;
    twinPrimes[n-1]= 3;
    twinPrimes[n]= 5;
    n+=2;
    for(i=5;i<N;i+=6){
        if(v[i] && v[i+2]){
            twinPrimes[n-1]=i;
            twinPrimes[n]=i+2;
            n+=2;
        }
    }
}

int main(){
    criba();
    fillTwinPrimes();
    long n;
    while(scanf("%ld",&n)!=EOF){
      printf("(%ld, %ld)\n",twinPrimes[2*(n-1)],twinPrimes[2*n-1]);  
    }

    return 0;
}
