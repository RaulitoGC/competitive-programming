using namespace std;


bool isPalindromic(string str, int init, int end){
	cout << init << " -- " << end  << endl;
	while(init <= end){
		if(str[init] != str[end]) return false;
		init++; end--;
	}
	return true;
}

string longestPalindromicSubstring(string str) {
	int n = str.size();
	string res = "", current = "";
	for(int i = 0 ; i < n ; i++){
		for(int j = n - 1; j >= i ; j--){
			if(str[i] == str[j] && isPalindromic(str, i , j)){
				current = str.substr(i, j - i + 1);
				cout << current << endl;
				if(res.size() < current.size()){
					res = current;
				}
			}
		}
	}
	
  return res;
}

