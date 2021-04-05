using namespace std;

int firstNonRepeatingCharacter(string str) {
  vector<char> V(26, 0);
	int n = str.size();
	int idx = 0;
	for(int i = 0 ; i < n ; i++){
		idx = str[i] - 'a';
		V[idx]++;
	}
	
	for(int i = 0 ; i < n ; i++){
		idx = str[i] - 'a';
		if(V[idx] == 1){
			return i;
		}
	}
	
  return -1;
}

