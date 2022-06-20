#include "Stack.h"

Stack::Stack() {
    this->head = 0;
}

Stack::~Stack() {
    if(!isEmpty()) {
        delete this->head;
        head = 0;
    }
}

void Stack::push(StackItem *item) {
    StackItem *temp = this->head;
    this->head = item;
    item->next = temp;
}

StackItem* Stack::pop() {
    StackItem *temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    return temp;
}

StackItem* Stack::top() {
    return this->head;
}

bool Stack::isEmpty() {
   return head == 0;
}
Stack* Stack::flush() {
    delete this;
    return nullptr;
}

