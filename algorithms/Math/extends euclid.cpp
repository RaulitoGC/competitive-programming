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


tuple<long long, long long, long long > gcd(long long a, long long b){
  if(b == 0){
    return {1, 0 , a};
  }else{
    int x,y,g;
    tie(x,y,g) = gcd(b, a % b);
    return {y, x - (a / b) * y, g};
  }
}

int main(void) {
  	int a, b, x, y, d;
  	while (cin >> a >> b) {
	    d = gcd(a, b, x, y);

	    if (a == b) {
	      x = 0;
	      y = 1;
	    }

		cout << x << " " << y << " " << d << endl;
	}
    return 0;
  }