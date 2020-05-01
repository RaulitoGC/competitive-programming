/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
  
    int bsMin(BinaryMatrix &binaryMatrix, int row, int min ,int max){
      int mid = 0;
      while(max-min > 1) {
        mid = (max + min)/2;
        if(binaryMatrix.get(row, mid) < 1) min = mid;
        else max = mid; 
      }
      if(binaryMatrix.get(row, min) == 1) return min;
      if(binaryMatrix.get(row, max) == 1) return max;
      return -1;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> v = binaryMatrix.dimensions();
      int columns = v[1], rows = v[0], x = rows - 1, c;
      bool l = false;
      for(int i = 0 ; i < rows ; i++){
        if(binaryMatrix.get(i, columns - 1) == 1){
          l = true;
          break;
        }
      }
      if(!l) return -1;
      
      for(int i = 0 ; i < rows ; i++){
        c = bsMin(binaryMatrix, i, 0, columns - 1);
        if(c < x && c != -1){
          x = c;
        }
      }
      return x;
    }
};