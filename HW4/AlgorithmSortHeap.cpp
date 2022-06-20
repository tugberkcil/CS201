#include "AlgorithmSortHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k){
    this->k = k;
}

int AlgorithmSortHeap::select() {
    int N;
    cin >> N;

    BinaryHeap *heap = new BinaryHeap(k);
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        heap->insert(num);
    }

    for(int i = k; i < N; i++){
        int num;
        cin >> num;
        if (num >= heap->getMin()) {
            heap->deleteMin();
            heap->insert(num);
        }
    }
    int kth = heap->getMin();
    return kth;

}
AlgorithmSortHeap::~AlgorithmSortHeap() {
    delete heap;
}



