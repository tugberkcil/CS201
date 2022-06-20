#ifndef _SEL_
#define _SEL_

#include <iostream>


using namespace std;

class SelectionAlgorithm{
public:
    explicit SelectionAlgorithm(int);
    virtual ~SelectionAlgorithm() = default;
    virtual int select() = 0;
protected:
    int k;
};
#endif //_SEL_



