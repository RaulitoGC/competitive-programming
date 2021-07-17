#include <vector>
using namespace std;

vector<char> getNewPattern(string pattern);
int getCountsAndFirstYPos(vector<char> pattern, unordered_map<char, int> &counts);

vector<string> patternMatcher(string pattern, string str) {
  int n = pattern.size();
	int m = str.size();
	
	if( n > m){
		return {};
	}
	
	vector<char> newPattern = getNewPattern(pattern);
	bool didSwitch = newPattern[0] != pattern[0];
	
	unordered_map<char, int> counts;
	counts['x'] = 0;
	counts['y'] = 0;
	int firstYPos = getCountsAndFirstYPos(newPattern, counts);
	
	if(counts['y'] != 0){
		for(int lenOfX = 1 ; lenOfX < m ; lenOfX++){
			double lenOfY = ( (double)m - (double)lenOfX * (double)counts['x'] ) / (double)counts['y'];
			if( lenOfY <= 0 || fmod(lenOfY, 1) != 0){ // lenfOfY % 1 != 0 : If lenfOfY is decimal or not
				continue;
			}
			
			int yIdx = firstYPos * lenOfX;
			string x = str.substr(0, lenOfX);
			string y = str.substr(yIdx, lenOfY);
			
			vector<string> potencialMatch(m, "");
			transform(newPattern.begin(), newPattern.end(), potencialMatch.begin(),
							 [x, y](char c) -> string { 
								 return (c == 'x') ? x : y;
								 });
			if(str == accumulate(potencialMatch.begin(), potencialMatch.end(),
													string(""))){
				return !didSwitch ? vector<string>{x, y} : vector<string>{ y, x};
			}
		}
	}else{
		double lenOfX = m / counts['x'];
		
		if(fmod(lenOfX, 1) == 0){
			string x = str.substr(0, lenOfX);
			vector<string> potencialMatch(m, "");
			transform(newPattern.begin(), newPattern.end(), potencialMatch.begin(),
							 [x](char c) -> string { return x;});
			if(str == accumulate(potencialMatch.begin(), potencialMatch.end(),
													string(""))){
				return !didSwitch ? vector<string>{x, ""} : vector<string>{ "", x};
			}
		}
	}
	
	
  return {};
}

vector<char> getNewPattern(string pattern){
	vector<char> patternLetters(pattern.begin(), pattern.end());
	
	if(pattern[0] == 'x'){
		return patternLetters;
	}else{
		transform(patternLetters.begin(), patternLetters.end(), patternLetters.begin(),
						 [](char c) -> char { return c == 'y' ? 'x' : 'y'; });
		return patternLetters;
	}
}

int getCountsAndFirstYPos(vector<char> pattern, unordered_map<char, int> &counts){
	
	int firstYPos = -1, n = pattern.size();
	
	for(int i = 0 ; i < n ; i++){
		counts[pattern[i]]++;
		if(pattern[i] == 'y' && firstYPos == -1){
			firstYPos = i;
		}
	}
	
	return firstYPos;
}

