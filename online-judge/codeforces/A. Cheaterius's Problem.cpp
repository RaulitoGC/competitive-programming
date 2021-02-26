#include <bits/stdc++.h>
using namespace std;

map<int,int> M;
int cont= 0;
bool flag;

void addMap(int a, int b, int c, int d){
    int t1,t2,t3,t4;
    t1 = a*1000 + b*100 + c*10 + d;
    t2 = b*1000 + c*100 + d*10 + a;
    t3 = c*1000 + d*100 + a*10 + b;
    t4 = d*1000 + a*100 + b*10 + c;

    if(M.count(t1)>0 || M.count(t2)>0 || M.count(t3)>0 || M.count(t4)>0){
        flag = false;
    }else{
        M[t1] = 10;
        M[t2] = 10;
        M[t3] = 10;
        M[t4] = 10;
    } 
}



int main(){

    int t,x,y,a,b,c,d;
    string ss;
    scanf("%d ",&t);
    for(int i=0; i<t;i++){
        scanf("%d %d",&x,&y);
        a = x/10;
        b = x%10;
        c = y%10;
        d = y/10;
        flag = true;
        if(i!=t-1) cin>>ss;
        addMap(a,b,c,d);
        if(flag) cont++;
    }

    printf("%d\n",cont);
    return 0;
}