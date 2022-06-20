#include "AlgorithmSortAll.h"


AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k){
}

int AlgorithmSortAll::select() {
    int N;
    cin >> N;
    pArr = new int[N];
    for(int m = 0; m<N;m++) {
        int number;
        cin >> number;
        pArr[m] = number;
    }
    int j;
    int moved;
    int i;
    for (int i = 0; i < N; i++){
        moved = pArr[i];
        j = i;
        while (j > 0 && pArr[j-1] > moved) {
            pArr[j] = pArr[j-1];
            j--;
        }
        pArr[j] = moved;
    }
    return pArr[k];
}

