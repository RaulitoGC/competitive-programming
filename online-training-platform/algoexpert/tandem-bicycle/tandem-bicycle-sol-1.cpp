#include <vector>
using namespace std;

// Time: nLog(n)
// Size : O(1)
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
	sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
	
	int res = 0, n = blueShirtSpeeds.size();
	if(fastest){
		for(int i = 0 ; i < n ; i++){
			res += max(redShirtSpeeds[i], blueShirtSpeeds[n - i - 1]);
		}
	}else{
		for(int i = 0 ; i < n ; i++){
			res += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
		}
	}
	
  return res;
}

