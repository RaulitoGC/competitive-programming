#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	int size = array.size();
  if(size == 0) return 0;
	if(size  == 2){
		return max(array[0], array[1]);
	}
	
	vector<int> v(size);
	v[0] = array[0];
	v[1] = max(array[0], array[1]);
	for(int i = 2; i < size ; i++){
		v[i] = max(v[i-1], v[i-2] + array[i]);
	}
  return v[size - 1];
}

