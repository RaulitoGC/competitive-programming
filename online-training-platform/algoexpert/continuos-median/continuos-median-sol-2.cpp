using namespace std;

bool MAX_HEAP_FUNC(int a, int b);
bool MIN_HEAP_FUNC(int a, int b);

class Heap {
public:
  vector<int> heap;
	function<bool(int, int)> comparisonFunc;

  Heap(function<bool(int, int)> func, vector<int> array) { 
		comparisonFunc = func;
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
				if(comparisonFunc(heap[childTwoIdx], heap[childOneIdx])){
					idxToSwap = childTwoIdx;
				} else {
					idxToSwap = childOneIdx;
				}
			} else{
				idxToSwap = childOneIdx;
			}
			
			if(comparisonFunc(heap[idxToSwap], heap[currentIdx])){
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
			if(comparisonFunc(heap[currentIdx], heap[parentIdx])){
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
	
	int length(){
		return heap.size();
	}

  int remove() {
		swap(0, heap.size() - 1, heap);
		int valueToRemove = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
    return valueToRemove;
  }

  void insert(int value) {
    heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
	
	void swap(int i, int j, vector<int> &heap){
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
public:
	Heap lowers, greaters;
  double median;
	
	ContinuousMedianHandler()
		: lowers(MAX_HEAP_FUNC, {}), greaters(MIN_HEAP_FUNC, {}) {
			median = 0;
		}

  void insert(int number) {
    if(lowers.length() == 0 || number < lowers.peek()){
			lowers.insert(number);
		}else{
			greaters.insert(number);
		}
		
		rebalanceHeaps();
		updateMedian();
  }
	
	void rebalanceHeaps(){
		if( lowers.length() - 2 == greaters.length()){
			greaters.insert(lowers.remove());
		}else if( greaters.length() - 2 == lowers.length()){
			lowers.insert(greaters.remove());
		}
	}
	
	void updateMedian(){
		if(lowers.length() == greaters.length()){
			median = (lowers.peek() + greaters.peek()) / 2.0;
		}else if(lowers.length() > greaters.length()){
			median = lowers.peek();
		}else{
			median = greaters.peek();
		}
	}

  double getMedian() { return median; }
};

bool MAX_HEAP_FUNC(int a, int b){ return a > b; }
bool MIN_HEAP_FUNC(int a, int b){ return a < b; }

