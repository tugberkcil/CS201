#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include <ctime>

class TestBed{
public:
    TestBed();
    ~TestBed();
    void execute();
private:
    SelectionAlgorithm *algorithm;
    void setAlgorithm(int type);
};
