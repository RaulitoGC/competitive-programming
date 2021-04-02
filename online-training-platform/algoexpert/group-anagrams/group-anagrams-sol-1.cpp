#include <vector>

using namespace std;
//O(n*LlogL), L is the largest size of any word;
// O(n) : n is the size of words array
vector<vector<string>> groupAnagrams(vector<string> words) {
  map<string, vector<string>> M;
	int n = words.size();
	string current;
	for(int i = 0 ; i < n ; i++){
		current = words[i];
		sort(current.begin(), current.end());
		if(M.find(current) == M.end()){
			M[current] = vector<string>{words[i]};
		}else{
			M[current].push_back(words[i]);
		}
	}
	map<string, vector<string>>::iterator it;
	vector<vector<string>> res;
	for(it = M.begin() ; it != M.end() ; it++){
		res.push_back(it->second);
	}
  return res;
}

