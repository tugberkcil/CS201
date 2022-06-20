#ifndef ALGORITHMSORTQUICK
#define ALGORITHMSORTQUICK


#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm{
public:
    AlgorithmSortQuick(int k);
    int select();
    int quickselect(int* n, int left, int right, int k);
    int partition(int* n, int arr_left, int arr_right);
    void insertionSort(int* n, int left, int right);
};


#endif