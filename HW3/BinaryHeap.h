#ifndef __BINARYHEAP__
#define __BINARYHEAP__
#include <iostream>
#include <climits>
using namespace std;

class BinaryHeap {

public:
    BinaryHeap(int);
    ~BinaryHeap();
    void insert(int);
    void deleteMin();
    int getMin();
private:
    int *heap;
    int size;
    int capacity;
    void percolateDown(int);
    void percolateUp(int);
    void swap(int, int);
};

#endif
