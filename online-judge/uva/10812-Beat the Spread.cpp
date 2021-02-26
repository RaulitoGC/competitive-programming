#include<iostream>
using namespace std;
 
int main(){
int N;
while(cin>>N){
    while(N){
        int s,d;
        cin>>s>>d;
        if(s>=d){
                if((!(s&1) and !(d&1)) or ((s&1) and (d&1))) cout<<(s+d)/2<<" "<<(s-d)/2<<endl;
                else cout<<"impossible"<<endl;
        }else cout<<"impossible"<<endl;
        N--;
        }
}
return 0;
}
