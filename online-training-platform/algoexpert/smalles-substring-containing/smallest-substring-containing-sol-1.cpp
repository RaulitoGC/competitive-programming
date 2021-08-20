using namespace std;

unordered_map<char, int> getCharCounts(string str);
pair<int, int> getSubstringBounds(string bigString, unordered_map<char,int> targetCharCounts);
pair<int, int> getBounds(int idx1, int idx2, int idx3, int idx4);
string getStringFromBounds(string bigString, pair<int,int> bounds);

string smallestSubstringContaining(string bigString, string smallString) {
	
	unordered_map<char,int> targetCharCounts = getCharCounts(smallString);
	pair<int, int> bounds = getSubstringBounds(bigString, targetCharCounts);
	
  return getStringFromBounds(bigString, bounds);
}

unordered_map<char, int> getCharCounts(string str){
	unordered_map<char, int> charCounts;
	int n = str.size();
	for(int i = 0 ; i < n ; i++){
		charCounts[str[i]]++;
	}
	return charCounts;
}

pair<int, int> getSubstringBounds(string bigString, unordered_map<char,int> targetCharCounts){
	unordered_map<char, int> subStringCharCounts;
	int numbUniqueChars = targetCharCounts.size();
	pair<int, int> bounds = make_pair(0, INT_MAX);
	int numbUniqueCharDone = 0;
	
	int leftIdx = 0, rightIdx = 0, n = bigString.size();
	
	while(rightIdx < n){
		char rightChar = bigString[rightIdx];
		if(targetCharCounts.find(rightChar) == targetCharCounts.end()){
			rightIdx++;
			continue;
		}
		
		subStringCharCounts[rightChar]++;
		
		if(subStringCharCounts[rightChar] == targetCharCounts[rightChar]){
			numbUniqueCharDone++;
		}
		
		while(numbUniqueCharDone == numbUniqueChars && leftIdx <= rightIdx){
			bounds = getBounds(leftIdx, rightIdx, bounds.first, bounds.second);
			char leftChar = bigString[leftIdx];
			if(targetCharCounts.find(leftChar) == targetCharCounts.end()){
				leftIdx++;
				continue;
			}
			
			if(subStringCharCounts[leftChar] == targetCharCounts[leftChar]){
				numbUniqueCharDone--;
			}
			
			subStringCharCounts[leftChar]--;
			leftIdx++;
		}
		rightIdx++;
	}
	
	return bounds;
}

pair<int, int> getBounds(int idx1, int idx2, int idx3, int idx4){
	return (idx2 - idx1 < idx4 - idx3) ? make_pair(idx1, idx2): make_pair(idx3, idx4);
}

string getStringFromBounds(string bigString, pair<int,int> bounds){
	int start = bounds.first;
	int end = bounds.second;
	
	return end == INT_MAX ? "" : bigString.substr(start, end - start + 1);
}

