#ifndef _STACK_
#define _STACK_
#include "StackItem.h"

class Stack{
public:
    Stack();
    ~Stack();
    StackItem *head;
    void push(StackItem*);

    StackItem* pop();
    StackItem* top();

    bool isEmpty();

    Stack* flush();

};
#endif