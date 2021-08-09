#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  int n = array.size();
	int idx = n - 1;
	vector<int> res(n);
	int first = 0, last = n - 1;
	while( first <= last && idx >= 0){
		if(array[first]*array[first] < array[last]*array[last]){
			res[idx] = array[last]*array[last];
			last--;
		}else{
			res[idx] = array[first]*array[first];
			first++;
		}
		idx--;
	}
  return res;
}

