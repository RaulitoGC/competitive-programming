#include <vector>
using namespace std;

int findMinimunSpaces(
	int idx,
	string pi,
	unordered_set<string> numbersTable,
	unordered_map<int,int> &cache
){
	
	int n = pi.size();
	if( idx >= n){
		return -1;
	}
	
	if(cache.find(idx) != cache.end()){
		return cache[idx];
	}
	
	int minSpaces = INT_MAX;
	for(int i = idx ; i < n ; i++){
		string prefix = pi.substr(idx,i + 1 - idx);
		
		if(numbersTable.find(prefix) != numbersTable.end()){
			int minSpacesForSuffix = findMinimunSpaces(
				i + 1,
				pi,
				numbersTable,
				cache
			);
			if(minSpacesForSuffix == INT_MAX){
				minSpaces = min(minSpaces, minSpacesForSuffix);
			}else{
				minSpaces = min(minSpaces, minSpacesForSuffix + 1);
			}
		}
	}
	
	cache[idx] = minSpaces;
	
	return minSpaces;
}

//Space: O(n + m) : n = #digits of pi, m = # favorite numbers
// Time: O(n^3 + m)
int numbersInPi(string pi, vector<string> numbers) {
	
	int n = numbers.size();
  unordered_set<string> numbersTable;
	
	for(int i = 0; i < n ; i++){
		numbersTable.insert(numbers[i]);
	}
	
	unordered_map<int, int> cache;
	int minSpaces = findMinimunSpaces(0, pi, numbersTable, cache);
  return minSpaces == INT_MAX ? -1 : minSpaces;
}

