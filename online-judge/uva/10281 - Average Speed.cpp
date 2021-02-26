#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello Family"<<"\n"

#define loop(i,n) for(int i = 0; i < n ; i++)

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;



char str[1000];
int hh, mm, ss, t1, t2 = 0;
double v = 0, res = 0.0;

int main(){
    
    while(gets(str)){
        sscanf(str, "%d:%d:%d",&hh, &mm, &ss);
        t1 = hh * 3600 + mm*60 + ss;
        if(str[8] != '\0'){
            res += ((t1 - t2) * v)/3600.0;
            sscanf(str + 8, "%lf",&v);
        }else{
            res += ((t1 - t2) * v)/3600.0;
            printf("%s %.2lf km\n", str, res);    
        }
        t2 = t1;
    }

	return 0;
}
