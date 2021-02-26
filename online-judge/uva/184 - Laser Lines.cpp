#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};

int main(){

	while(true){
		vector<Point> points;
		Point temp;
		while(scanf("%d %d",&temp.x,&temp.y)==2){
			if(!temp.x && temp.y) break;
			points.push_back(temp),
		}
		if(points.size()==0) break;
		printCollinear(points);
	}
	return 0;
}