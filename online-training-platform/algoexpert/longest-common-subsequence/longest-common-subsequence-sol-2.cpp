#include <vector>
using namespace std;

vector<char> buildSequence(string str, vector<vector<int>> lengths){
	int i = lengths.size() - 1;
	int j = lengths[0].size() - 1;
	
	vector<char> result;
	
	while(i != 0 && j != 0){
		if(lengths[i][j] == lengths[i - 1][j]){
			i--;
		}else if(lengths[i][j] == lengths[i][j - 1]){
			j--;
		}else{
			result.push_back(str[i - 1]);
			i--;j--;
		}
	}
	reverse(result.begin(), result.end());
	return result;
}

// Time: O(n*m0 : n = first string size, m = second string size
// Space: O(n*m : n = first string size, m = second string size
vector<char> longestCommonSubsequence(string str1, string str2) {
  
	int n = str1.size();
	int m = str2.size();
	
	vector<vector<int>> lengths(n + 1, vector<int>(m + 1, 0));
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			if(str1[i - 1] == str2[j - 1]){
				lengths[i][j] = lengths[i - 1][j - 1] + 1;
			}else{
				lengths[i][j] = max(lengths[i-1][j], lengths[i][j-1]);
			}
		}
	}
	
  return buildSequence(str1, lengths);
}

