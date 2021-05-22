#include <vector>
using namespace std;

int maximizeExpression(vector<int> array) {
  
	int n = array.size();
	if(n < 4){
		return 0;
	}
	
	vector<int> maxA(n, INT_MIN);
	vector<int> maxAminusB(n, INT_MIN);
	vector<int> maxAminusBplusC(n, INT_MIN);
	vector<int> maxAminusBplusCminusD(n, INT_MIN);
	
	maxA[0] = array[0];
	for(int i = 1 ; i < n ; i++){
		maxA[i] = max(maxA[i - 1], array[i]);
	}
	
	for(int i = 1 ; i < n ; i++){
		maxAminusB[i] = max(maxA[i - 1] - array[i], maxAminusB[i - 1]);
	}
	
	for(int i = 2 ; i < n ; i++){
		maxAminusBplusC[i] = max(maxAminusB[i - 1] + array[i], maxAminusBplusC[i - 1]);
	}
	
	for(int i = 3 ; i < n ; i++){
		maxAminusBplusCminusD[i] = max(maxAminusBplusC[i - 1] - array[i], maxAminusBplusCminusD[i - 1]);
	}
		
  return maxAminusBplusCminusD[n - 1];
}

