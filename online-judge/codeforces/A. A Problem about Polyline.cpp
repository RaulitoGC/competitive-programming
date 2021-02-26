#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b; scanf("%d%d",&a,&b);
    if(a<b) puts("-1");
    else {
        int t1 = a+b, t2 = a-b;
        int n1 = t1/(2*b)*2, n2 = t2/(2*b)*2;
        cout<<n1<<" "<<n2<<endl;
        double a1 = t1*1./n1, a2 = t2*1./n2;
        printf("%.10lf\n",min(a1,a2));
    }
    return 0;
}
