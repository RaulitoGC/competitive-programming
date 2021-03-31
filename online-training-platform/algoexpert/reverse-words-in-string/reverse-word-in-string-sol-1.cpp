#include <bits/stdc++.h>
using namespace std;

string reverseWordsInString(string str) {
  int idx = str.size() - 1;
	string res = "";
	while(idx >= 0){
		if(str[idx] == ' '){
			res += str[idx];
			idx--;
		}else{
			int init = idx - 1;
			while(init >= 0 && str[init] != ' ') init--;
			if(init < 0) init = 0;
			else init++;
			int fin = idx;
			res += str.substr(init, fin - init + 1);
			idx = init - 1;
		}
	}
  return res;
}

