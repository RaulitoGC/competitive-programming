#include <bits/stdc++.h>
using namespace std;

class MinHeap{

  private:
    vector<int> heap;
    vector<int> buildHeap(vector<int> array){
      int sz = array.size() - 1;
      int firstParentIdx = (sz - 1)/2;
      while(firstParentIdx >= 0){
        siftDown(firstParentIdx, array);
        firstParentIdx--;
      }
      return array;
    }

    void siftUp(int i){
      if(i < 0) return;
      int parentIdx = (i - 1)/2;
      if(heap[i] > heap[parentIdx]){
        swap(heap[i], heap[parentIdx], heap);
      }
      siftUp(parentIdx);
    }

    void siftDown(int i, vector<int> &array){
      int childOneIdx = i*2+1;
      //cout << "childone -> " << childOneIdx << endl;
      if(childOneIdx > array.size() - 1){
        return;
      }

      int childTwoIdx = childOneIdx + 1;
      //cout << "chidltwoidx -> " << childTwoIdx << endl;
      if(childTwoIdx > array.size() - 1){
        return;
      }


      int parentIdx = i;
      //6 4 3 5 6
      // cout << parentIdx <<endl;
      // cout<< array[parentIdx] << endl; // 6
      // cout << array[childOneIdx] << endl;// 4
      // cout << array[childTwoIdx] << endl;// 3
      if(array[parentIdx] < array[childOneIdx] && array[parentIdx] < array[childTwoIdx]){
        // cout << "break" << endl;
        return;
      }else if(array[childOneIdx] < array[childTwoIdx] && array[childOneIdx] < array[parentIdx]){
        swap(childOneIdx, parentIdx, array);
        siftDown(childOneIdx, array);
      }else if(array[childOneIdx] > array[childTwoIdx] && array[childTwoIdx] < array[parentIdx]){
        swap(childTwoIdx, parentIdx, array);
        siftDown(childTwoIdx, array);
      }
    }

    void swap(int i, int j, vector<int> &array){
      array[i] = array[i] ^ array[j];
      array[j] = array[i] ^ array[j];
      array[i] = array[i] ^ array[j];
    }

  public:
    
    MinHeap(vector<int> array){
      heap = buildHeap(array);
    }

    // O(1)
    // Also called peek()
    int top(){
      for(int i = 0 ; i < heap.size() ; i++){
        cout << heap[i]<< " ";
      }
      cout << endl;
      return heap[0];
    }

    void insert(int value){
      heap.push_back(value);
      int sz = heap.size() - 1;
      siftUp(sz);      
    }

    void remove(){
      int sz = heap.size() - 1;
      swap(heap[0], heap[sz], heap);
      int valueToRemove = heap.back();
      heap.pop_back();
      siftDown(heap[0], heap);
    }
    
};


int32_t main(){

  vector<int> array;
   //6 4 3 5 6
  array.push_back(6);
  array.push_back(4);
  array.push_back(3);
  array.push_back(5);
  array.push_back(6);
  MinHeap* minHeap = new MinHeap(array);
  cout << minHeap->top() << endl;
}