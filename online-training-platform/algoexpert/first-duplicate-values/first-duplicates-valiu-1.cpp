#include <vector>
using namespace std;

// Time : O(n)
// Space: O(n)
int firstDuplicateValue(vector<int> array) { 
	int size = array.size();
	vector<int> v(size + 1, 0);
	
	for(int i = 0 ; i < size ; i++){
		v[array[i]]++;
		if(v[array[i]] == 2){
			return array[i];
		}
	}
	return -1; 
}

