using namespace std;

// Time o(n)
// Space o(1)
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	int sz = array.size();
	int j = 0;
	for(int i = 0 ; i < sz ; i++){
		if(array[i] == sequence[j]){
			j++;
		}
	}
	cout << j << endl;
  return j == sequence.size();
}

