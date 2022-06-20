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
    int size ;
    int capacity;
    int rightChild;
    int swapIndex;
    int access(int);
    int access1(int,int,int);
    void percolateDown(int);
    void swap(int, int);
};

#endif


