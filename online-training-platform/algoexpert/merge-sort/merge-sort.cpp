#include <vector>
using namespace std;

vector<int> mergeSortedArray(vector<int> firstArray, vector<int> secondArray);

vector<int> mergeSort(vector<int> array) {
  int n = array.size();
	if(n == 1){
		return array;
	}
	
	int midIdx = n/2;
	cout << midIdx << endl;
	vector<int> left(array.begin(), array.begin() + midIdx);
	vector<int> right(array.begin() + midIdx, array.end());
	
	for( int num: left){
		cout << num << " ";
	}
	
	cout << "| ";
	for( int num: right){
		cout << num << " ";
	}
	
	cout << endl;
	
  return mergeSortedArray(mergeSort(left), mergeSort(right));
}

vector<int> mergeSortedArray(vector<int> firstArray, vector<int> secondArray){
	int n = firstArray.size();
	int m = secondArray.size();

	vector<int> sortedArray;
	int i = 0, j = 0;
	
	while(i < n && j < m){
		if(firstArray[i] <= secondArray[j]){
			sortedArray.push_back(firstArray[i]);
			i++;
		}else{
			sortedArray.push_back(secondArray[j]);
			j++;
		}
	}
	
	while(i < n){
		sortedArray.push_back(firstArray[i]);
		i++;
	}
	
	while(j < m){
		sortedArray.push_back(secondArray[j]);
		j++;
	}
	
	return sortedArray;
}

