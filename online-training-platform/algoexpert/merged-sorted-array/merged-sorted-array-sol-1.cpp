using namespace std;

vector<int> doMerge(vector<int> arrayOne, vector<int> arrayTwo);

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
  
	int n = arrays.size();
	vector<int> res = arrays[0];
	for(int i = 1 ; i < n ; i++){
		res = doMerge(res, arrays[i]);
	}
	
  return res;
}

vector<int> doMerge(vector<int> arrayOne, vector<int> arrayTwo){
	int n  = arrayOne.size();
	int m = arrayTwo.size();
	
	int i = 0, j = 0;
	vector<int> sortedArray;
	
	while(i < n && j < m){
		if(arrayOne[i] <= arrayTwo[j]){
			sortedArray.push_back(arrayOne[i]);
			i++;
		}else{
			sortedArray.push_back(arrayTwo[j]);
			j++;
		}
	}
	
	while(i < n){
		sortedArray.push_back(arrayOne[i]);
		i++;
	}
	
	while(j < m){
		sortedArray.push_back(arrayTwo[j]);
		j++;
	}
	
	return sortedArray;
}

