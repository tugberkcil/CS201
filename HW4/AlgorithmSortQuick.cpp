#include <iostream>
#include "AlgorithmSortQuick.h"

using namespace std;

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {
}

int AlgorithmSortQuick::select() {
    int c;
    cin >> c;

    int* n = 0;
    n = new int[c];
    for (int i = 0; i < c; i++) {
        cin >> n[i];
    }
    return quickselect(n, 0, c - 1, this->k);
}

int AlgorithmSortQuick::quickselect(int* n, int left, int right, int k) {

    if (left + 10 <= right) {
        insertionSort(n, left, right);
        return n[k];
    }
    if (left == right) {
        return n[left];
    }

    int p = partition(n, left, right);
    int length = p - left + 1;
    if (length == k) {
        return n[p];
    }
    else if (k < length) {
        return quickselect(n, left, p - 1, k);
    }
    else {
        return quickselect(n, p + 1, right, k - length);
    }
}

int AlgorithmSortQuick::partition(int* arr, int arr_left, int arr_right){

    int center = (arr_left + arr_right) / 2;
    if (arr[center] < arr[arr_left])
        swap(arr[arr_left], arr[center]);
    if (arr[arr_right] < arr[arr_left])
        swap(arr[arr_right], arr[arr_left]);
    if (arr[arr_right] < arr[center])
        swap(arr[center], arr[arr_right]);

    swap(arr[center], arr[arr_right - 1]);
    int a = arr[arr_right - 1];
    return a;
}

void AlgorithmSortQuick::insertionSort(int *n, int left, int right) {
    int key, j;
    int size = right - left;

    for (int i = 1; i <=size; i++){
        key = n[i];
        j = i;
        while (j > 0 && n[j - 1] > key) {
            n[j] = n[j - 1];
            j--;
        }
        n[j] = key;
    }
}