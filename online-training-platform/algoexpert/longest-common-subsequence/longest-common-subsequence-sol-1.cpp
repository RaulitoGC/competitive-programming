#include <vector>
using namespace std;

// Time: O(n*m*min(n,m)) : n = first string size, m = second string size
// Space: O(n*m*min(n,m)) : n = first string size, m = second string size

vector<char> longestCommonSubsequence(string str1, string str2) {
  
	int n = str1.size();
	int m = str2.size();
	
	vector<vector<string>> lcs(n + 1, vector<string>(m + 1, ""));
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			if(str1[i - 1] == str2[j - 1]){
				lcs[i][j] = lcs[i - 1][j - 1] + str1[i - 1];
			}else{
				if(lcs[i-1][j].size() > lcs[i][j-1].size()){
					lcs[i][j] = lcs[i-1][j];	
				}else{
					lcs[i][j] = lcs[i][j-1];
				}
			}
		}
	}
	
	vector<char> result;
	string lcsValue = lcs[n][m];
	for(int i = 0; i < lcsValue.size() ; i++){
		result.push_back(lcsValue[i]);
	}
	
  return result;
}

