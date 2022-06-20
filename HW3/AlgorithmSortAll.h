#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm{
public:
    explicit AlgorithmSortAll(int);
    ~AlgorithmSortAll();
protected:
    int select();
private:
    int *pArr;
};
