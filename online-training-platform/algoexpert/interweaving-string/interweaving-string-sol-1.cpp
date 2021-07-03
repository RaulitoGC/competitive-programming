using namespace std;

// Time : (n^2*m^2) n = one size, m = two size
// Space: O(1)
bool interweavingStrings(string one, string two, string three) {
	int i = 0, n = one.size();
	int j = 0, m = two.size();
	if(n + m > three.size()){
		return false;
	}
	for(int k = 0 ; k < three.size() ; k++){
		
		if( i < n && j < m && three[k] == one[i] && three[k] == two[j]){
			int first = i;
			int second = j;
			int pos = k;
			
			while( pos < three.size() && three[pos] == one[first]){
				first++;
				pos++;
			}
			
			pos = k;
			
			while( pos < three.size() && three[pos] == two[second]){
				second++;
				pos++;
			}

			if( second - j > first - i){
				j++;
			}else{
				i++;
			}
		}else if( i < n && three[k] == one[i]){
			i++;
		}else if( j < m && three[k] == two[j]){
			j++;
		}else{
			return false;
		}
	}
	
  return true;
}

