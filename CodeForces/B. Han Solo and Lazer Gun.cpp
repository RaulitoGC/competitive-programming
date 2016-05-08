#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int n;
	double x0,y0,xi,yi,temp;
	bool flag=false;
	while(cin>>n>>x0>>y0){
		set<double> shots;
		flag = false;
		temp =0.0;
		while(n--){
			cin>>xi>>yi;
			if(xi==x0){
				flag = true;
				continue;
				}
			temp = (yi-y0)/(xi-x0);
			shots.insert(temp);
			}
		if(flag) cout<<shots.size() + 1<<"\n";
		else cout<<shots.size()<<"\n";
		
		
		}
	return 0;
	}
