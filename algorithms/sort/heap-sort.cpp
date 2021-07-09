#include <vector>
using namespace std;


void buildMaxHeap(vector<int> &array);
void siftDown(int currentIdx, int endIdx, vector<int> &heap);

vector<int> heapSort(vector<int> array) {
  buildMaxHeap(array);
	for(int i = array.size() - 1 ; i >= 0 ; i--){
		swap(array[0], array[i]);
		siftDown(0, i - 1, array);
	}
  return array;
}


void buildMaxHeap(vector<int> &array) {
	int firstParentIdx = (array.size() - 2)/2;	
	for(int currentIdx = firstParentIdx; currentIdx >= 0 ; currentIdx--){
		siftDown(currentIdx, array.size() - 1, array);
	}
}

void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
	int childOneIdx = currentIdx * 2 + 1;
	while(childOneIdx <= endIdx){
		int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
		int idxToSwap;
		if(childTwoIdx != -1){
			if(heap[childTwoIdx] > heap[childOneIdx]){
				idxToSwap = childTwoIdx;
			} else {
				idxToSwap = childOneIdx;
			}
		} else{
			idxToSwap = childOneIdx;
		}

		if(heap[idxToSwap] > heap[currentIdx]){
			swap(heap[currentIdx], heap[idxToSwap]);
			currentIdx = idxToSwap;
			childOneIdx = currentIdx * 2 + 1;
		} else{
			return;
		}
	}
}