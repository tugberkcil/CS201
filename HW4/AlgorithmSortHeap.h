#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"

class AlgorithmSortHeap : public SelectionAlgorithm {
public:
    AlgorithmSortHeap(int);
    ~AlgorithmSortHeap();
protected:
    int select();
private:
    BinaryHeap *heap;
};


