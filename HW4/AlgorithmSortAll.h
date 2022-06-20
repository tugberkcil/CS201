#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm{
public:
    explicit AlgorithmSortAll(int);
protected:
    int select();
private:
    int *pArr;
};


