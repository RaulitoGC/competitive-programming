#include <vector>
using namespace std;

bool isValidNumber(string number){
	int n = stoi(number);
	if(n > 255) return false;
	
	return number == to_string(n);
}

vector<string> validIPAddresses(string strt) {
  vector<string> res;
	int n = strt.length();
	for(int i = 1 ; i < min(n, 4); i++){
		vector<string> current = {"","","",""};
		
		current[0] = strt.substr(0,i);
		if(!isValidNumber(current[0])){
			continue;
		}
		
		for(int j = i + 1;  j < i + min(n - i, 4) ; j++){
			current[1] = strt.substr(i, j - i);
			if(!isValidNumber(current[1])){
				continue;
			}
			
			for(int k = j + 1 ; k < j + min(n - j, 4) ; k++){
				current[2] = strt.substr(j, k - j);
				current[3] = strt.substr(k);
				
				if(isValidNumber(current[2]) && isValidNumber(current[3])){
					res.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
				}
			}
		}
	}
  return res;
}



