using namespace std;

string isPalindromic(string str, int idx, bool isEven){
	int left, right;
	if(isEven){
		left = idx - 1;
		right = idx;
	}else{
		left = idx - 1;
		right = idx + 1;
	}
	
	while(left >= 0 && right < str.size()){		
		if(str[left] != str[right]){
			break;
		}
		left--;
		right++;
	}
	return str.substr(left + 1, right - left - 1);
}

string longestPalindromicSubstring(string str) {
  int n = str.size();
	
	string longestPalindromic = str.substr(0,1), current = "";
	for(int i = 1 ; i < n ; i++){
		
		string even = isPalindromic(str, i, true);
		string odd = isPalindromic(str, i, false);
		
		if(even.size() > odd.size()){
			current = even;
		}else{
			current = odd;
		}
		
		if(current.size() > longestPalindromic.size()){
			longestPalindromic = current;
		}
	}
  return longestPalindromic;
}

