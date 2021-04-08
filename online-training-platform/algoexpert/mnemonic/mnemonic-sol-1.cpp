#include <vector>
using namespace std;

map<int,vector<char>> M = {
	{0, {'0'}},						{1, {'1'}},
	{2, {'a','b','c'}},		{3, {'d','e','f'}},
	{4, {'g','h', 'i'}},		{5, {'j', 'k', 'l'}},
	{6, {'m', 'n', 'o'}},	{7, {'p', 'q', 'r', 's'}},
	{8, {'t', 'u', 'v'}},	{9, {'w', 'x', 'y', 'z'}}
};

void phoneNumberMnemonicsHelper(int index, string phoneNumber, vector<char> &current, vector<string> &res){
	if(index == phoneNumber.size()){
		string mnemonic = "";
		for(int i = 0 ; i < current.size() ; i++){
			mnemonic += current[i];
		}
		res.push_back(mnemonic);
	}else{
		int number = phoneNumber[index] - '0';
		vector<char> letters = M[number];
		for(int i = 0 ; i < letters.size() ; i++){
			current[index] = letters[i];
			phoneNumberMnemonicsHelper(index + 1, phoneNumber, current, res);
		}
	}
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  int n = phoneNumber.size();
	vector<char> current(n, '0');
	vector<string> res;
	phoneNumberMnemonicsHelper(0, phoneNumber, current, res);
  return res;
}



