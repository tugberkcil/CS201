#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;
    heap = new int[capacity + 1];
    size = 0;
}
BinaryHeap::~BinaryHeap() {
    delete[] heap;
}

void BinaryHeap::insert(int element) {
    if (size < capacity) {
        size++;
        int location =size;
        for (; location > 1 && element < heap[location / 2]; location /= 2)
            heap[location] = heap[location/2];
        heap[location] = element;
    }
}

void BinaryHeap::deleteMin() {
    if(size < 1)
        return;
    heap[1] = heap[size];
    heap[size] = 0;
    size--;
    percolateDown(1);
}
int BinaryHeap::getMin() {
    if(size < 1)
        return -1;

    return heap[1];
}
int BinaryHeap::access(int hole) {
    if((hole*2+1 <= size) && (heap[hole*2+1] >= 0))
        return heap[hole*2+1];
    return INT_MAX;
}
int BinaryHeap::access1(int a,int leftChild, int rightChild){
    if(leftChild >= rightChild)
        return a*2+1;
    return a*2;
}
void BinaryHeap::percolateDown(int hole) {

    if(hole*2 <= size && heap[hole*2] >= 0){
        int leftChild = heap[hole*2];
        int a = leftChild;
        int rightChild = access(hole);
        int b = rightChild;
        int swapIndex = access1(hole, a, b);
        if(heap[hole] > heap[swapIndex]) {
            swap(hole, swapIndex);
            percolateDown(swapIndex);
        }
    }
}
void BinaryHeap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}



