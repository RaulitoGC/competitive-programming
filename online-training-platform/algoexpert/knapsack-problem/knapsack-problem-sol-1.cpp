#include <vector>
using namespace std;


vector<int> buildIdxSequence(vector<vector<int>> items, vector<vector<int>> knapsack){
	int n = knapsack.size() - 1;
	int m = knapsack[0].size() - 1;
	
	vector<int> idxSequence;
	
	while(n > 0){
		int value = items[n - 1][0];
		int weight = items[n - 1][1];
		
		if(knapsack[n][m] != knapsack[n - 1][m]){
			idxSequence.push_back(n - 1);
			m -= weight;
		}
		n--;
		
		if(weight == 0){
			break;
		}
	}
	
	return idxSequence;
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  
	int n = items.size();
	
	vector<vector<int>> knapsack(n + 1, vector<int>(capacity + 1, 0));
	
	for(int i = 1; i <= n ; i++){
		int value = items[i - 1][0];
		int weight = items[i - 1][1];
		for(int j = 0 ; j <= capacity; j++){
			if(j < weight){ 
				knapsack[i][j] = knapsack[i-1][j];
			}else{
				knapsack[i][j] = max(
					knapsack[i-1][j - weight] + value, 
					knapsack[i-1][j]
				);
			}
		}
	}
	cout << knapsack[n][capacity] << endl;
  return {
      vector<int>{knapsack[n][capacity]},   // total value
      buildIdxSequence(items, knapsack), // item indices
  };
}

  