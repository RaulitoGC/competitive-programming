using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());
	int sum = 0;
	int size = queries.size();
	int left;
	for(int i = 0 ; i < size ; i++){
		left = size - (i + 1);
		sum += queries[i]*left;
	}
  return sum;
}


