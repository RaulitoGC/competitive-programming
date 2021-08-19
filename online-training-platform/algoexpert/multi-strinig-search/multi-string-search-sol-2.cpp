#include <vector>
using namespace std;


bool isMatch(string bigString, string subStr);

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
  
	int n = smallStrings.size();

	vector<bool> res(n);
	
	for(int i = 0 ; i < n ; i++){
		res[i] = isMatch(bigString, smallStrings[i]);
	}
	
  return res;
}

bool isMatch(string bigString, string subStr){
	int n = bigString.size();
	int m = subStr.size();
	if(m > n){
		return false;
	}
	
	cout <<" size -> " << n - m << endl;
	for(int start = 0 ; start <= n - m ; start++){
			int j = 0;
			int i = start;
			string currentSubstr = "";		
			while(i < n){
				cout << " current -> " << currentSubstr << endl;
				if(bigString[i] == subStr[j]){
					currentSubstr += subStr[j];
					j++;
					if(currentSubstr == subStr){
						return true;
					}
				}else{
					j = 0;
					currentSubstr = "";
				}
			i++;
		}
	}

	
	//cout << currentSubstr << " - "  << subStr<< endl;
	return false;
}

