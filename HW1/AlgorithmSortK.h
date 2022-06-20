#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm{
public:
    explicit AlgorithmSortK(int);
protected:
    int select();
private:
    int* Arr;
    int N;
    void swapping();
    void finalop();
};

