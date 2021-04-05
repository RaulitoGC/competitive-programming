using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
  
	int n = buildings.size();
	if(n == 0) return {};
	vector<int> res;
	int indexOfTalestBuilding;
	if(direction == "EAST"){
		
		indexOfTalestBuilding = n - 1;
		res.push_back(indexOfTalestBuilding);
		for(int i = n - 2 ; i >= 0 ; i--){
			if(buildings[i] > buildings[indexOfTalestBuilding]){
				indexOfTalestBuilding = i;
				res.push_back(indexOfTalestBuilding);
			}
		}
		
		sort(res.begin(), res.end());
	}else{
		
		indexOfTalestBuilding = 0;
		res.push_back(indexOfTalestBuilding);
		for(int i = 1 ; i < n ; i++){
			if(buildings[i] > buildings[indexOfTalestBuilding]){
				indexOfTalestBuilding = i;
				res.push_back(indexOfTalestBuilding);
			}
		}
		
	}
	
  return res;
}

