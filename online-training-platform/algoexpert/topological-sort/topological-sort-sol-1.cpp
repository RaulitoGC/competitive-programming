#include <vector>
using namespace std;

struct Edge{
	int from;
	int to;
	
	Edge(int _from, int _to){
		from = _from;
		to = _to;
	}
};


int dfs(int idx, int from, 
				vector<bool> &visited, vector<bool> &visiting,
				vector<int> &ordering, unordered_map<int, vector<Edge*>> &graph){
	
	visiting[from] = true;
	
	vector<Edge*> edges = graph[from];
	for(int i = 0; i < edges.size() ; i++){
		if(!visited[edges[i]->to]){
			if(visiting[edges[i]->to]){
				return INT_MAX;
			}
			idx = dfs(idx, edges[i]->to, visited, visiting, ordering, graph);
		}
	}
	
	if(idx == INT_MAX){
		return INT_MAX;
	}
	ordering[idx] = from;
	visiting[from] = false;
	visited[from] = true;
	
	return idx - 1;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
	
	int n = jobs.size();
	vector<bool> visited(n  + 1, false);
	vector<bool> visiting(n, false);
	vector<int> ordering(n, 0);
	unordered_map<int, vector<Edge*>> graph;
	int idx = n - 1;
	
	for(int i = 0 ; i < n ; i++){
		graph[jobs[i]] = {};
	}
	
	for(int i = 0 ; i < deps.size() ; i++){
		int from = deps[i][0];
		int to = deps[i][1];
		graph[from].push_back(new Edge(from, to));
	}
	
	for(int i = 0; i < n ; i++){
		if(!visited[jobs[i]]){
			idx = dfs(idx, jobs[i], visited, visiting, ordering, graph);
			if(idx == INT_MAX){
				return {};
			}
		}
	}
	
  return ordering;
}

