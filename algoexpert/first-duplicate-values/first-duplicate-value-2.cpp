#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) { 
	int size = array.size();
	for(int i = 0 ; i < size ; i++){
		int idx = abs(array[i]) - 1;
		cout << idx << endl;
		if(array[idx] < 0){
			return idx + 1;
		}else{
			array[idx] = array[idx]*-1;
		}
		
	}
	return -1; 
}

