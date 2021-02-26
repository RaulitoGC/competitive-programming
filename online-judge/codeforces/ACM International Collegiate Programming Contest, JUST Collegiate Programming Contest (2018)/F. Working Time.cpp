#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
#define z() Sleep(2000)

#define loop(i,n) for(int i = 0; i < n ; i++)

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

#define MAX 10

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;



int getValue(string str){
    string hour = str.substr(0,2);
    
    string minutes = str.substr(3,4);
    
    stringstream hs(hour);
    stringstream ms(minutes);
    int h;
    int m;
    hs>>h;
    ms>>m;
    
    return h*60 + m;
}

int main(){
    
    int T,n,m;
    string s,e;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int sum = 0;
        while(n--){
            cin>>s>>e;
            debug2(getValue(e), getValue(s));
            sum += (getValue(e) - getValue(s));
        }

        if( sum >= m*60) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }

	return 0;
}
