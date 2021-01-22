#include <vector>
using namespace std;

void swap(int i, int j, vector<int> &array){
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}

//Worst :  Time ->O(n) | Space O(1) | Sorted array
//Average :  Time ->O(n^2) | Space O(1) | not sorted
//Worst :  Time ->O(n^2) | Space O(1) | inverse sorted

vector<int> insertionSort(vector<int> array) {
	int size = array.size();
  for(int i = 0; i < size - 1 ; i++){	
		for(int j = i + 1; j > 0  && array[j] < array[j-1] ; j--){
			swap(j-1, j, array);
		}
	}
	return array;
}

