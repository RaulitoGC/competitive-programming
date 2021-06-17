
#include <vector>
using namespace std;

class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> array) {
		heap = buildHeap(array); 
	}

  vector<int> buildHeap(vector<int> &array) {
    int firstParentIdx = (array.size() - 2)/2;
		for(int currentIdx = firstParentIdx; currentIdx >= 0 ; currentIdx--){
			siftDown(currentIdx, array.size() - 1, array);
		}
    return array;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
		int childOneIdx = currentIdx * 2 + 1;
		while(childOneIdx <= endIdx){
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if(childTwoIdx != -1){
				if(heap[childTwoIdx] < heap[childOneIdx]){
					idxToSwap = childTwoIdx;
				} else {
					idxToSwap = childOneIdx;
				}
			} else{
				idxToSwap = childOneIdx;
			}
			
			if(heap[idxToSwap] < heap[currentIdx]){
				swap(currentIdx, idxToSwap, heap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			} else{
				return;
			}
		}
  }

  void siftUp(int currentIdx, vector<int> &heap) {
		int parentIdx = (currentIdx - 1) / 2;
		while(currentIdx > 0 ) {
			if(heap[currentIdx] < heap[parentIdx]){
				swap(currentIdx, parentIdx, heap);
				currentIdx = parentIdx;
				parentIdx = ( currentIdx - 1) / 2;
			}else{
				return;
			}
		}
  }

  int peek() {
    return heap[0];
  }

  void remove() {
		swap(0, heap.size() - 1, heap);
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
  }

  void insert(int value) {
    heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
	
	bool isEmpty(){
		return heap.empty();
	}
	
	void swap(int i, int j, vector<int> &heap){
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};

vector<int> sortKSortedArray(vector<int> array, int k) {
	
	int n = array.size();
	if(n == 0) return {};
	
	vector<int> arrayForHeap(
		array.begin(), 
		array.begin() + min(k + 1, n)
	);
	
	MinHeap* minHeap = new MinHeap(arrayForHeap);
	
	int nextIdxToInsertElement = 0;
	
	for(int idx = k + 1; idx < n ; idx++){
		array[nextIdxToInsertElement] = minHeap->peek();
		minHeap->remove();
		
		nextIdxToInsertElement++;
		minHeap->insert(array[idx]);
	}
	
	while(!minHeap->isEmpty()){
		array[nextIdxToInsertElement] = minHeap->peek();
		minHeap->remove();
		nextIdxToInsertElement++;
	}
	
  return array;
}


