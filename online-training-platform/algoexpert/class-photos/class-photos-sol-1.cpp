#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  int size = redShirtHeights.size();
	
	sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
	bool red = true, blue = true;
	for(int i = 0 ; i < size ; i++){
		if(redShirtHeights[i] < blueShirtHeights[i]){
			red = false;
		}else if(redShirtHeights[i] > blueShirtHeights[i]){
			blue = false;
		}else{
			red = blue = false;
			break;
		}
	}
	
  return red || blue;
}

