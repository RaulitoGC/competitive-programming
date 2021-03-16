#include <vector>
using namespace std;

bool validateCycle(vector<int> v, int start){
	
	int child = start;
	int father = v[child];
	cout << "start -> " << start<< endl;
	while(child != father){
		cout << child << " -  bf" << father << endl;
		if(start == father){
			return true;
		}
		
		child = father;
		
		father = v[child];
		cout << child << " -  af" << father << endl;
	}
	
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  int n = edges.size(), m, dest;
	
	vector<int> v(n + 1);
	for(int i = 0 ; i <= n ; i++){
		v[i] = i;
	}
	
	for(int i = 0 ; i < n ; i++){
		m = edges[i].size();
		for(int j = 0 ; j < m ; j++){
			dest = edges[i][j];
			v[dest] = i;
			cout << i << " " << dest << endl;
			if(i == dest || validateCycle(v, dest)){
				cout << " validate" << endl;
				return true;
			}
		}
	}
	
  return false;
}

