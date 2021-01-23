#include <bits/stdc++.h>

using namespace std;

string getSimpleRunLegthEnconding(int start, int end, char c){
	string res = "";
	int diff = end - start;
	cout << diff << endl;
	if(diff <= 9){
		res += to_string(diff) + c;
	}else{
		
		int parts = diff/9;
		int rest = diff%9;
		int idx = 1;
		while(idx <= parts){
			res += to_string(9) + c;
			idx++;
		}
		if(rest != 0){
			res += to_string(rest) + c;
		}
	}
	
	return res;
}

// Time : O(n)
// Space: O(n), n is te response in worst case
string runLengthEncoding(string str) {
  int size = str.size();
	
	string res = "";
	for(int i = 0; i < size ; ){
		int start = i;
		char select = str[start];
		int end = start + 1;
		while(end < size && select == str[end]){
			end++;
		}
		i = end;
		res += getSimpleRunLegthEnconding(start, end, select);
		
	}
	return res;
}