#include <bits/stdc++.h>
using namespace std;
map<char,int> M;

void init(){

	M[' '] = 1;
	M['a'] = 1;
	M['b'] = 2;
	M['c'] = 3;

	M['d'] = 1;
	M['e'] = 2;
	M['f'] = 3;

	M['g'] = 1;
	M['h'] = 2;
	M['i'] = 3;

	M['j'] = 1;
	M['k'] = 2;
	M['l'] = 3;

	M['m'] = 1;
	M['n'] = 2;
	M['o'] = 3;

	M['p'] = 1;
	M['q'] = 2;
	M['r'] = 3;
	M['s'] = 4;

	M['t'] = 1;
	M['u'] = 2;
	M['v'] = 3;

	M['w'] = 1;
	M['x'] = 2;
	M['y'] = 3;
	M['z'] = 4;

}

int main(){

	int n,l,cont,c;
	string ss;
	
	init();
	scanf("%d",&n);
	c=1;
	while(getline(cin,ss)){
		if(ss.empty()) continue;
		l = ss.size();
		cont = 0;
		for(int i = 0; i<l; i++){
			cont+= M[ss[i]];
		}
		printf("Case #%d: %d\n",c,cont);
		c++;
	}

	return 0;
}
