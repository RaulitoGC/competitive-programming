#include <vector>
using namespace std;

//Time : O(n)
//Space : O(1)
int kadanesAlgorithm(vector<int> array) {
	if(array.empty()) return 0;
	int maxSum = array[0];
	int localMaxSum = array[0];
  for(int i = 1 ; i < array.size() ; i++){
		localMaxSum = max(localMaxSum + array[i], array[i]);
		maxSum = max(maxSum, localMaxSum);
	}
  return maxSum;
}

