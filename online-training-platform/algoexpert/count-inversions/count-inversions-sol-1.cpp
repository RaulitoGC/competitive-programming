#include <vector>
using namespace std;

int countInversions(vector<int> array) {
  int inversors = 0;
	int n = array.size();
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(array[i] > array[j]) {
				inversors++;
			}
		}
	}
  return inversors;
}

