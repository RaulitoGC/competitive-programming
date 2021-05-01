#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
	
	int n = scores.size();
	
  vector<int> rewardsNumbers(n, 1);
	
	for(int i = 1 ; i < n ; i++){
		if(scores[i] > scores[i-1]){
			rewardsNumbers[i] = rewardsNumbers[i - 1] + 1;
		}
	}
	
	for(int i = n - 2; i >= 0 ; i--){
		if(scores[i] > scores[i+1]){
			rewardsNumbers[i] = max(rewardsNumbers[i], rewardsNumbers[i + 1] + 1);
		}
	}
	
	
  return accumulate(rewardsNumbers.begin(), rewardsNumbers.end(), 0);
}

