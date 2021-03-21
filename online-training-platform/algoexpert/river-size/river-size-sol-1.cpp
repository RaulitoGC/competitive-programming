#include <vector>
using namespace std;

int getSize(int i, int j, vector<vector<int>> matrix, vector<vector<bool>> &visited){
	queue<pair<int,int>> Q;
	Q.push(make_pair(i,j));
	
	int size = 0;
	
	int n = matrix.size();
	int m = matrix[0].size();
	while(!Q.empty()){
		pair<int,int> current = Q.front();
		Q.pop();
		size++;
		int x = current.first;
		int y = current.second;
		visited[x][y] = true;
		if(x + 1 < n && matrix[x+1][y] == 1 && !visited[x+1][y]){
			Q.push(make_pair(x+1,y));
			visited[x+1][y] = true;
		}
		
		if(y + 1 < m && matrix[x][y+1] == 1 && !visited[x][y+1]){
			Q.push(make_pair(x,y+1));
			visited[x][y+1] = true;
		}
		
		if(x - 1 >= 0 && matrix[x-1][y] == 1 && !visited[x-1][y]){
			Q.push(make_pair(x-1,y));
			visited[x-1][y] = true;
		}
		
		if(y - 1 >= 0 && matrix[x][y-1] == 1 && !visited[x][y-1]){
			Q.push(make_pair(x,y-1));
			visited[x][y-1] = true;
		}
	}
	
	return size;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m,false));
	vector<int> res;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(matrix[i][j] == 1 && !visited[i][j]){
				res.push_back(getSize(i,j,matrix,visited));
			}
		}
	}
  return res;
}

