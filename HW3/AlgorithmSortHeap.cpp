#include "AlgorithmSortHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k){
    heap = new BinaryHeap(this->k);

}

int AlgorithmSortHeap::select() {
    int N;
    cin >> N;

    for(int i = 0; i < k; i++) {
        int number;
        cin >> number;
        heap->insert(number);
    }
    int l = N - k;
    while(l-- > 0){
        int s;
        cin >> s;
        if(s >= heap->getMin()) {
            heap->deleteMin();
            heap->insert(s);
        }
    }
    int c = heap->getMin();
    return c;

}

AlgorithmSortHeap::~AlgorithmSortHeap() {
    delete heap;
}
