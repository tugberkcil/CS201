#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;
    heap = new int[capacity + 1];
    size = 0;
}

void BinaryHeap::insert(int element) {
    if (size >= capacity) {
        return;
    }
    heap[++size] = element;
    percolateUp(size);
}
void BinaryHeap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}
int BinaryHeap::getMin() {
    if(size < 1)
        return -1;
    return heap[1];
}

void BinaryHeap::deleteMin() {
    if(size < 1)
        return;
    else if(size == 1){
        size--;
        return;
    }
    heap[1] = heap[size];
    size--;
    percolateDown(1);
}

void BinaryHeap::percolateUp(int n){
    if(n/2 == 0)
        return;
    else if(heap[n/2] < heap[n])
        return;
    swap(n, n/2);
    percolateUp(n/2);
}

void BinaryHeap::percolateDown(int hole) {
    if(hole * 2 > size)
        return;
    else if(hole * 2 + 1 > size){
        if(heap[hole] > heap[hole * 2])
            swap(hole, 2 * hole);
    }
    else{
        int min = 0;
        if(heap[2 * hole + 1] > heap[2 * hole])
            min = 2 * hole;
        else
            min= 2 * hole + 1;
        if(heap[hole] > heap[min]) {
            swap(hole, min);
            percolateDown(min);
        }

    }
}

BinaryHeap::~BinaryHeap() {
    delete[] heap;
}
