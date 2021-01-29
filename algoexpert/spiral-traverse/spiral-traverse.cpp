#include <bits/stdc++.h>

using namespace std;

//Time : O(n)
// Space: O(n)
vector<int> spiralTraverse(vector<vector<int>> array) {
  int xStart, xEnd, yStart, yEnd;
	vector<int> res;
	
	int n = array.size();
	if(n == 0) return res;
	int m = array[0].size();
	
	xStart = 0;
	xEnd = n - 1;
	yStart = 0;
	yEnd = m - 1;
	cout << xStart<<xEnd<<yStart<<yEnd<<endl;
	while(true){
		for(int j = yStart ; j <= yEnd ; j++){
			// cout << "s1" <<j<< endl;
			res.push_back(array[xStart][j]);
		}
		xStart++;
		if(xStart > xEnd || yStart > yEnd) break;
		for(int i = xStart ; i <= xEnd ; i++){
			cout << "s2" << endl;
			res.push_back(array[i][yEnd]);
			
		}
		yEnd--;
		if(xStart > xEnd || yStart > yEnd) break;
		for(int j = yEnd; j >= yStart ; j--){
			cout << "s3" <<j<< endl;
			res.push_back(array[xEnd][j]);
			
		}
		xEnd--;
		if(xStart > xEnd || yStart > yEnd) break;
		for(int i = xEnd; i >= xStart ; i--){
			cout << "s4" << endl;
			res.push_back(array[i][yStart]);
			
		}
		yStart++;
		if(xStart > xEnd || yStart > yEnd) break;
		cout << xStart << " " << xEnd << endl;
		cout << yStart << " " << yEnd << endl;
	}
	
	
  return res;
}

