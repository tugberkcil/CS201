#include "TestBed.h"


TestBed::TestBed() = default;

void TestBed :: setAlgorithm(int type){
    int k;
    cin >> k;
    if(type == 1){
        algorithm = new AlgorithmSortAll(k);
    }
    else if(type == 2){
        algorithm = new AlgorithmSortK(k);
    }
    else if(type == 3){
        algorithm = new AlgorithmSortHeap(k);
    }
    else if(type == 4){
        algorithm = new AlgorithmSortQuick(k);
    }
}

void TestBed::execute() {
    int algType;
    cin >> algType;
    setAlgorithm(algType);

    clock_t start = clock();

    int sum = algorithm->select();

    clock_t end = clock();

    double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;


    cout << "Result: " << sum << endl;
    cout <<"Duration (sec): " << cpu_time << endl;
}


TestBed::~TestBed(){
    delete algorithm;
    algorithm = nullptr;
}



