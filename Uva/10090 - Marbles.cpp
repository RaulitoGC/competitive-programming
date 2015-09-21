#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }

  int x1, y1;
  int d = gcd(b%a, a, x1, y1);
  x = y1 - (b/a) * x1;
  y = x1;

  return d;
}

int main(void) {
    
    int n,c1,n1,c2,n2,x,y,d;
  	while (cin>>n){
      cin>>c1>>n1>>c2>>n2;
	    d = gcd(n1, n2, x, y);
      if(n%d!=0){cout<<"failed"<<endl;}
      else{
        if (n1 == n2) {
          x = 0;
          y = 1;
        }

        cout<<(n/d)*x<<" "<<(n/d)*y<<endl;
      }
	}
    return 0;
  }