#include <iostream>
#include <string>

using namespace std;
int main(){
    
    string input;
    int caso=1;
    while(cin>>input){
        if(input=="*") break;
        if(input=="Hajj")
            cout<<"Case "<<caso<<": Hajj-e-Akbar"<<endl;
        else
            cout<<"Case "<<caso<<": Hajj-e-Asghar"<<endl;
        }
    
    return 0;
    }
