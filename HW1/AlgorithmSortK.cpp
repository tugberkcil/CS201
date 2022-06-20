#include "AlgorithmSortK.h"


AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortK::select() {
    cin >> N;
    Arr = new int[this->k];
    for(int i=0;i<k;i++){
        cin >> Arr[i];
    }
    swapping();
    finalop();

    int kthLargest = Arr[k-1];
    return kthLargest;
}
void AlgorithmSortK::swapping() {
    for(int i=0;i<k;i++){
        for(int j=0;j<k-1;j++){
            if(Arr[j] < Arr[j+1]){
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}
void AlgorithmSortK::finalop() {
    for(int i=0;i<N-k;i++) {
        int nm = 0;
        cin >> nm;

        if (nm < Arr[k]) {
            continue;
        } else {
            for (int j = 0; j < k; j++) {
                if (nm > Arr[j]) {
                    int temp = Arr[j];
                    Arr[j] = nm;
                    for (int m = k - 1; m > j; m--) {
                        if (m == j + 1) {
                            Arr[m] = temp;
                        } else {
                            Arr[m] = Arr[m - 1];
                        }
                    }
                    break;
                }
            }
        }
    }
}

