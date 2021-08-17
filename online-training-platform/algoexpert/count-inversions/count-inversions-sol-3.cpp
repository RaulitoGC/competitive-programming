#include <vector>
using namespace std;

int countSubArrayInversions(vector<int> &array, int start, int end);
int mergeSortAndCountInversions(vector<int> &array, int start, int middle, int end);


// Time : O(nLogn)
// Space : O(n)
int countInversions(vector<int> array) {
  return countSubArrayInversions(array, 0, array.size());
}


int countSubArrayInversions(vector<int> &array, int start, int end){
	if( end -  start <= 1){
		return 0;
	}
	
	int middle = start + ((end - start) / 2);
	
	int leftInversions = countSubArrayInversions(array, start, middle);
	int rightInversions = countSubArrayInversions(array, middle, end);
	int mergedArrayInversions = mergeSortAndCountInversions(array, start, middle, end);
	
	return leftInversions + rightInversions + mergedArrayInversions;
}

int mergeSortAndCountInversions(vector<int> &array, int start, int middle, int end){
	vector<int> sortedArray;
	int i = start, j = middle, inversions = 0;
	
	while(i < middle && j < end){
		if(array[i] <= array[j]){
			sortedArray.push_back(array[i]);
			i++;
		}else{
			sortedArray.push_back(array[j]);
			j++;
			inversions += (middle - i);
		}
	}
	
	while(i < middle){
		sortedArray.push_back(array[i]);
		i++;
	}
	
	while(j < end){
		sortedArray.push_back(array[j]);
		j++;
	}
	
	int n = sortedArray.size();
	for(int idx = 0 ; idx < n ; idx++){
		array[start + idx] = sortedArray[idx];
	}
	
	return inversions;
}