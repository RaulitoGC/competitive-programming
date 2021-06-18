#include <vector>
using namespace std;

class MinHeap {
public:
  vector<vector<int>> heap;

  MinHeap(vector<vector<int>> array) {
		heap = array;
		buildHeap(); 
	}

  void buildHeap() {
    int firstParentIdx = (heap.size() - 2)/2;
		for(int currentIdx = firstParentIdx; currentIdx >= 0 ; currentIdx--){
			siftDown(currentIdx, heap.size() - 1);
		}
  }

  void siftDown(int currentIdx, int endIdx) {
		int childOneIdx = currentIdx * 2 + 1;
		while(childOneIdx <= endIdx){
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if(childTwoIdx != -1){
				if(heap[childTwoIdx][1] < heap[childOneIdx][1]){
					idxToSwap = childTwoIdx;
				} else {
					idxToSwap = childOneIdx;
				}
			} else{
				idxToSwap = childOneIdx;
			}
			
			if(heap[idxToSwap][1] < heap[currentIdx][1]){
				swap(currentIdx, idxToSwap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			} else{
				return;
			}
		}
  }

  void siftUp(int currentIdx) {
		int parentIdx = (currentIdx - 1) / 2;
		while(currentIdx > 0 ) {
			if(heap[currentIdx][1] < heap[parentIdx][1]){
				swap(currentIdx, parentIdx);
				currentIdx = parentIdx;
				parentIdx = ( currentIdx - 1) / 2;
			}else{
				return;
			}
		}
  }

  vector<int> peek() {
    return heap[0];
  }

  void remove() {
		swap(0, heap.size() - 1);
		heap.pop_back();
		siftDown(0, heap.size() - 1);
  }

  void insert(vector<int> value) {
    heap.push_back(value);
		siftUp(heap.size() - 1);
  }
	
	bool isEmpty(){
		return heap.empty();
	}
	
	int length(){
		return heap.size();
	}
	
	void swap(int i, int j){
		vector<int> temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};

int laptopRentals(vector<vector<int>> times) {
  if(times.empty()){
		return 0;
	}
	
	sort(times.begin(), times.end(), [](
		const vector<int> & a, const vector<int> &b) -> bool { 
    return a[0] < b[0]; 
	});
	
	vector<vector<int>> timesWhenLaptopIsUsed = {times[0]};
	MinHeap* minHeap = new MinHeap(timesWhenLaptopIsUsed);
	
	for(int i = 1; i < times.size() ; i++){
		vector<int> currentInterval = times[i];
		if(currentInterval[0] >= minHeap->peek()[1]){
			minHeap->remove();
		}
		
		minHeap->insert(currentInterval);
	}
	
  return minHeap->length();
}

