using namespace std;

bool hasSingleCycle(vector<int> array) {
	int size = array.size();
	vector<bool> visited(size, false);
	bool res = false;
  int index = 0, count = 1, next;
	visited[0] = true;
	
	while(true){
		
		
		if(array[index] + index >= size){
			next = index + array[index];
			next = next%size;
		}else if( array[index] + index < 0){
			int temp = -array[index];
			temp = temp%size;
			if(index - temp < 0){
				temp -= index;
				next = size - temp;
			}else{
				next = index - temp;
			}
		}else{
			next = array[index] + index;
		}
		
		if(!visited[next]){
			visited[next] = true;
			count++;
		}else{
			res = (count == size && next == 0);
			break;
		}
		index = next;
	}
	cout << res << endl;
  return res;
}

