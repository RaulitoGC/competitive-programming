#include <iostream>
#include <string>
using namespace std;
int main(){

    string cad;
    int l,i;
    int flag=1;
    while(getline(cin,cad)){
         l=cad.size();
         for(i=0;i<l;i++){
            if(cad[i]=='\"'){
               if(flag%2)  cout<<"``";
               else cout<<"''";
            flag++;
            }
            else cout<<cad[i];
            }
         cout<<endl;
      }
    return 0;    
    }
