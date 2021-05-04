#include <vector>

using namespace std;

vector<int> getSmaller(vector<int> array){
	vector<int> smaller;
	for(int i = 1 ; i < array.size() ; i++){
		if(array[i] < array[0]){
			smaller.push_back(array[i]);
		}
	}
	return smaller;
}

vector<int> getBiggerOrEqual(vector<int> array){
	vector<int> biggerOrEqual;
	for(int i = 1 ; i < array.size() ; i++){
		if(array[i] >= array[0]){
			biggerOrEqual.push_back(array[i]);
		}
	}
	return biggerOrEqual;
}

// Time: O(n^2)
// Space; O(n^2)
bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  int n = arrayOne.size();
	int m = arrayTwo.size();
	
	// Base case
	if(m != n) return false;
	if(n == 0 && m == 0) return true;
	if(arrayOne[0] != arrayTwo[0]) return false;
	
	vector<int> leftOne = getSmaller(arrayOne);
	vector<int> leftTwo = getSmaller(arrayTwo);
	
	vector<int> rightOne = getBiggerOrEqual(arrayOne);
	vector<int> rightTwo = getBiggerOrEqual(arrayTwo);
	
  return sameBsts(leftOne, leftTwo) && sameBsts(rightOne, rightTwo);
}

