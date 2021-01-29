#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	int count = 0;
	int size = array.size();
	
  for(int i = 0 ; i < size; i++){
		if(array[i] == toMove){
			count++;
		}
	}
	
	int idx = 0;
	for(int i = 0 ; i < size ; i++){
		if(array[i] != toMove){
			array[idx] = array[i];
			idx++;
		}
	}
	
	for(int i = idx ; i < size ; i++){
		array[i] = toMove;
	}
	
	return array;
}

