using namespace std;

int levenshteinDistance(string str1, string str2) {
  int s1 = str1.size();
	int s2 = str2.size();
	
	if(s1 == 0 && s2 == 0) return 0;
	if(s1 == 0 && s2 != 0) return s2;
	if(s1 != 0 && s2 == 0) return s1;
	
	int matrix[s1 + 1][s2 + 1];
	
	matrix[0][0] = (str1[0] == str2[0])? 0 : 1;
	
	for(int i = 1 ; i < s1 ; i++){
		if(str1[i] == str2[0]){
			matrix[i][0] = matrix[i-1][0];
		}else{
			matrix[i][0] = matrix[i-1][0] + 1;
		}
	}
	
	for(int j = 1 ; j < s2 ; j++){
		if(str2[j] == str1[0]){
			matrix[0][j] = matrix[0][j-1];
		}else{
			matrix[0][j] = matrix[0][j-1] + 1;
		}		
	}
	
	for(int i = 1 ; i < s1 ; i++){
		for(int j = 1 ; j < s2 ; j++){
			if(str1[i] == str2[j]){
				matrix[i][j] = 	matrix[i - 1][j - 1];
			}else{
				matrix[i][j] = 	min(matrix[i-1][j-1], min(matrix[i][j-1],matrix[i-1][j])) + 1;
			}
		}
	}
	
	for(int i = 0 ; i < s1 ; i++){
		for(int j = 0 ; j < s2 ; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
  return matrix[s1 - 1][s2 - 1];
}

