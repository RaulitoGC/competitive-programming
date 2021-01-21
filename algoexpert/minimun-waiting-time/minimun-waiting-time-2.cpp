using namespace std;

//Time : O(nLogn)
//Space : O(1)
int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());
	int sum = 0;
	int acum = 0;
	for(int i = 1 ; i < queries.size() ; i++){
		sum += queries[i - 1];
		acum += sum;
		cout << sum << endl;
	}
  return acum;
}


