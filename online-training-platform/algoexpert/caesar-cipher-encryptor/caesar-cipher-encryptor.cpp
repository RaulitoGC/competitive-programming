using namespace std;

string caesarCypherEncryptor(string str, int key) {

	int sz = str.size();
	key = key % 26;
	cout << key << endl;
	for(int i = 0 ; i < sz ; i++){
		int diff = ('z' - str[i]);
		cout << diff << endl;
		if( key <= diff ){
			str[i] = (char)( (int) str[i] + key);
		}else{
			str[i] = (char)( (int) 'a' + (key - diff - 1));
		}
	}
	cout << str << endl;
  return str;
}

