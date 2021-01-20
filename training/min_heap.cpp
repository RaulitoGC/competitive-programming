#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { 
		heap = buildHeap(vector); 
		for(int i = 0 ; i < heap.size() ; i++){
			cout << heap[i] << " ";
		}
		cout << endl;
	}

  vector<int> buildHeap(vector<int> &vector) {
		int size = vector.size() - 1;
    int parentIdx = (size - 1)/2;
		
		while(parentIdx >= 0){
			siftDown(parentIdx, size, vector);
			parentIdx--;
		}
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
		if(currentIdx > endIdx){
			return;
		}
		
		int leftIdx = 2*currentIdx + 1;
		if(leftIdx <= endIdx){
			int rightIdx = 2*currentIdx + 2;
			if(rightIdx <= endIdx){
				if(heap[leftIdx] < heap[currentIdx] && heap[rightIdx] < heap[currentIdx]){
					if(heap[leftIdx] < heap[rightIdx]){
						swap(currentIdx, leftIdx, heap); 
						siftDown(leftIdx, endIdx, heap);
					}else{
						swap(currentIdx, rightIdx, heap);
						siftDown(rightIdx, endIdx, heap);
					}
				}else if(heap[leftIdx] < heap[currentIdx]){
					swap(currentIdx, leftIdx, heap);
					siftDown(leftIdx, endIdx, heap);
				}else if(heap[rightIdx] < heap[currentIdx]){
					swap(currentIdx, rightIdx, heap);
					siftDown(rightIdx, endIdx, heap);
				}
			}else if(heap[leftIdx] < heap[currentIdx]){
				swap(currentIdx, leftIdx, heap); 
				siftDown(leftIdx, endIdx, heap);
			}
		}			
  }

  void siftUp(int currentIdx, vector<int> &heap) {
		if(currentIdx < 0) return;
		
    int parentIdx = (currentIdx - 1)/2;
		if(heap[parentIdx] > heap[currentIdx]){
			swap(parentIdx, currentIdx, heap);
			siftUp(parentIdx, heap);
		}
  }

  int peek() {
    return heap.front();
  }

  int remove() {
		int size = heap.size() - 1;
		swap(0, size, heap);
		int valueToRemove = heap.back();
		heap.pop_back();
		siftDown(0, size, heap);
    return valueToRemove;
  }

  void insert(int value) {
    heap.push_back(value);
		int size = heap.size() - 1;
		siftUp(size, heap);
		cout << peek() << endl;
  }
	
	void swap(int i, int j, vector<int> &heap){
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};

