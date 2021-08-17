#include <vector>
using namespace std;

vector<int> doMerge(vector<int> first, vector<int> second, int &countInversions){
	
	int i = 0, j = 0;
	int n = first.size(), m = second.size();
	vector<int> sortedArray;
	
	while( i < n && j < m){
		if(first[i] <= second[j]){
			sortedArray.push_back(first[i]);
			i++;
		}else{
			sortedArray.push_back(second[j]);
			j++;
			countInversions += (n - i);
		}
	}

	while( i < n ){
		sortedArray.push_back(first[i]);
		i++;
	}
	
	while( j < m ){
		sortedArray.push_back(second[j]);
		j++;
	}
	
	return sortedArray;
}

// Time : O(nLogn)
// Space : O(nLogn)
vector<int> mergeSort(vector<int> array, int &countInversions){
	int n = array.size();
	
	if(n == 1){
		return array;
	}

	int middle = n / 2;

	vector<int> left(array.begin(), array.begin() + middle);
	vector<int> right(array.begin() + middle, array.end());
	
	return doMerge(
		mergeSort(left, countInversions), 
		mergeSort(right, countInversions), 
		countInversions
	);

}

int countInversions(vector<int> array) {
	if(array.empty()){
		return 0;
	}
	int countInversions = 0;
  mergeSort(array, countInversions);
  return countInversions;
}



