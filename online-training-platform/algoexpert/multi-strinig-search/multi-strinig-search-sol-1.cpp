#include <vector>
using namespace std;

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
  unordered_map<string, int> us;
	
	int n = smallStrings.size();
	for(int i = 0 ; i < n ; i++){
		us[smallStrings[i]] = i;
	}
	
	vector<bool> res(n, false);
	int m = bigString.size();
	for(int i = 0 ; i < m ; i++){
		for(int j = 1 ; j <= m ; j++){
			string subStr = bigString.substr(i, j);
			if(us.find(subStr) != us.end()){
				res[us[subStr]] = true;
			}
		}	
	}
	
  return res;
}

