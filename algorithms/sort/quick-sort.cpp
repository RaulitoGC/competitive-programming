#include <bits/stdc++.h>
using namespace std;

// Time =  Worst Case[O(n^2)],  Best and average Case[O(nLogn)]
// 
void quickSort(vector<int> &array, int startIdx, int endIdx){
	
  // Base case in order to finish the recursion
	if(startIdx >= endIdx){
		return;
	}
	
  // Pivot can be random or endIdx, in this case is startId
	int pivotIdx = startIdx; 
	
  // Create leftIdx and rightIdx in order  to compare these with the pivot
  // and verify if these are in the correct position
	int leftIdx = startIdx + 1;
	int rightIdx = endIdx;
	
  // Iterate from leftIdx to rightIdx
	while( rightIdx >= leftIdx){

    // Since pivotIdx is the value choosen in order to compare with leftIdx and rightIdx
    // we only swap if these values are not in their correct position
    // Incorrect position = PivotValue  < leftValue and rightValue < pivotValue
		if(array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]){
			swap(array[leftIdx], array[rightIdx]);
		}
		
    // Validate if leftValue is in the correct position, if it is, we can move to 
    // the next left position = leftIdx++
		if(array[leftIdx] <= array[pivotIdx]){
			leftIdx++;
		}
		
    // Validate if rightValue is in the correct position, if it is, we can move to 
    // the next right position = rightIdx--
		if(array[pivotIdx] <= array[rightIdx]){
			rightIdx--;
		}
	}
	
  // After we traverse from startIdx to endIdx
	swap(array[pivotIdx], array[rightIdx]);
	
  // After the swap, pivot value is in the correct position, also, since
  // it was swaped from rightIdx, we need to make quicksort from 
  // [ startIdx, right -1] and [right + 1, endIdx]
  // Quicksort from start to right - 1
	quickSort(array, startIdx, rightIdx - 1);
  // Quick sort from right + 1 to endIdx
	quickSort(array, rightIdx + 1, endIdx);
}

