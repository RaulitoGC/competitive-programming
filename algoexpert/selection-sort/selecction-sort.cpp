#include <vector>
using namespace std;

int smallestPosition(int start, vector<int> array){
	int position = start;
	for(int i = start + 1 ; i < array.size() ; i++){
		if(array[i] < array[position]){
			position = i;
		}
	}
	return position;
}

void swap(int i, int j, vector<int> &array){
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}


// Time: O(n^2)
// Space : O(1)
vector<int> selectionSort(vector<int> array) {
	int size = array.size();
  for(int i = 0 ; i < size ; i++){
		int position = smallestPosition(i, array);
		swap(i, position, array);
	}
	return array;
}

