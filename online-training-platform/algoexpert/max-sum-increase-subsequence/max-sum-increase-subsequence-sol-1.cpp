#include <vector>
using namespace std;

vector<int> buildSequence(vector<int> array, vector<int> sequence, int currentIdx){
	vector<int> result;
	while(currentIdx != INT_MIN){
		result.push_back(array[currentIdx]);
		currentIdx = sequence[currentIdx];
	}
	reverse(result.begin(), result.end());
	return result;
}

//Time: O(n^2)
// Space: O(n)
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
	vector<int> sequence(array.size(), INT_MIN);
	vector<int> sums = array;
	
	int n = array.size(), maxSumIdx = 0;

	for(int i = 0 ; i < n ; i++){
		int currentNumber = array[i];
		for(int j = 0 ; j < i ; j++){
			int anotherNumber = array[j];
			if(anotherNumber < currentNumber && currentNumber + sums[j] > sums[i]){
				sums[i] = currentNumber + sums[j];
				sequence[i] = j;
			}
		}
		if(sums[i] > sums[maxSumIdx]){
			maxSumIdx = i;
		}
	}
	
	return {
		{sums[maxSumIdx]},
		buildSequence(array, sequence, maxSumIdx)
	};
}

