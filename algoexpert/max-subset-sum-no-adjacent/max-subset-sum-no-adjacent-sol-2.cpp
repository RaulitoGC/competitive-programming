#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	int size = array.size();
  if(size == 0) return 0;
	if(size == 1) return array[0];
	if(size  == 2){
		return max(array[0], array[1]);
	}
	
	vector<int> v(size);
	v[0] = array[0];
	v[1] = max(array[0], array[1]);
	
	int first = array[0];
	int second = max(array[0], array[1]);
	int res = max(first, second);
	for(int i = 2; i < size ; i++){
		res = max(second, first + array[i]);
		first = second;
		second = res;
	}
  return res;
}


