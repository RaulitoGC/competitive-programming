#include <vector>

using namespace std;

bool isOutOfBound(int row, int column, int width, int height){
	return row > height || row < 0 || column > width || column < 0;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
  
	if(array.empty()) return {};
	
	
	int height = array.size() - 1, width = array[0].size() - 1;
	int row = 0, col = 0;
	bool isGoignDown = true;
	
	vector<int> zigzagNumbers;
	
	while(!isOutOfBound(row, col, width, height)){
		
		zigzagNumbers.push_back(array[row][col]);
		
		if(isGoignDown){
			if(col == 0 || row == height){
				isGoignDown = false;
				if(row == height){
					col++;
				}else{
					row++;
				}
			}else{
				col--;
				row++;
			}
		}else{
			if(row == 0 || col == width){
				isGoignDown = true;
				if(col == width){
					row++;
				}else{
					col++;
				}
			}else{
				col++;
				row--;
			}
		}		
	}
	
  return zigzagNumbers;
}

