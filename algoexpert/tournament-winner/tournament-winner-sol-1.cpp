#include <bits/stdc++.h>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  int size = competitions.size();
	map<string, int> M;
	string home,away;
	int winner;
	for(int i = 0  ; i < size ; i++){
		home = competitions[i][0];
		away = competitions[i][1];
		winner = results[i];
		if(winner == 1){
			M[home] += 3;
			M[away] += 0;
		}else{
			M[home] += 0;
			M[away] += 3;
		}
	}
	
	map<string,int>::iterator it;
	int maxPoints = -1;
	string maxName = "";
	
	for(it = M.begin() ; it != M.end() ; it++){
		if(maxPoints == -1){
			maxName = it->first;
			maxPoints = it->second;
		}else{
			if(maxPoints < it->second){
				maxName = it->first;
				maxPoints = it->second;
			}
		}
	}
	
  return maxName;
}

