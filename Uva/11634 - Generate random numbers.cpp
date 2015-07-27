#include <cstdio>
#include <string.h>

using namespace std;

int main() {
    long n, cont;
    while(scanf("%ld", &n)==1) {
        if(n==0) break;
        bool random[10000];
        memset(random,true,sizeof(random));
        cont = 0;
        while(random[n]) {
            cont++;
            random[n] = false;
            n = n*n;
            n /= 100;
            n %= 10000;
        }
        printf("%ld\n", cont);
    }
    return 0;
}