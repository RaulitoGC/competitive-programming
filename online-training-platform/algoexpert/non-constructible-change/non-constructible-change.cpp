#include <vector>
using namespace std;
// Time : O(nLogn)
// Space : O(1)
int nonConstructibleChange(vector<int> coins) {
	sort(coins.begin(), coins.end());
	int k = 0;
	int size = coins.size();
	for(int i = 0 ; i < size; i++){
		if( k + 1 < coins[i]){
			break;
		}
		k+=coins[i];
	}
  return k+1;
}

