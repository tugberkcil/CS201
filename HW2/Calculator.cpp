#include <utility>
#include "Calculator.h"

Calculator::Calculator(string infix){
    this->stack = new Stack();
    this->infixExpression = std::move(infix);
    this->postfixExpression =getPostfix();
}
Calculator::~Calculator(){
    delete stack;
}
string Calculator::getPostfix(){
    string postfix;
    string token;
    istringstream iss(infixExpression);
    iss >> token;
    while (token != ";") {
        StackItem* data = new StackItem(token);
        if (!data->isOperator) {
            postfix += token + " ";
            iss >> token;
        } else if (token == "(") {
            this->stack->push(new StackItem(token));
            iss >> token;
        } else if (token == ")") {
            while (stack->head->op != OPERATOR_LEFTPAR) {
                StackItem *temp = stack->pop();
                postfix += temp->toString() + " ";
                delete temp;
            }
            StackItem *temp = stack->pop();
            delete temp;
            iss >> token;
        } else {
            if (stack->isEmpty() || stack->top()->op == OPERATOR_LEFTPAR || hasHigherPrecedence(token, stack->top())) {
                stack->push(new StackItem(token));
                iss >> token;
            } else {
                while (!stack->isEmpty()) {
                    if ((stack->top()->op != OPERATOR_LEFTPAR) && !hasHigherPrecedence(token, stack->top())) {
                        StackItem *temp = stack->pop();
                        postfix += temp->toString() + " ";
                        delete temp;
                    } else {
                        stack->push(new StackItem(token));
                        iss >> token;
                        break;
                    }
                }
            }
        }
    }
    while (!stack->isEmpty()) {
        postfix += stack->pop()->toString() + " ";
    }
    postfix += " ;";
    return postfix;
}

int Calculator::calculate() {
    this->stack = this->stack->flush();
    this->stack = new Stack();
    istringstream iss(postfixExpression);
    string token;
    iss >> token;
    while (token.compare(";") != 0) {
        StackItem* p = new StackItem(token);
        if (!p->isOperator) {
            this->stack->push(new StackItem(token));
        } else {
            StackItem *s1 = this->stack->pop();
            StackItem *s2 = this->stack->pop();
            int n1 = s1->n;
            int n2 = s2->n;
            int output;
            delete s1;
            delete s2;
            if (p->op == 2) {
                output = n2 - n1;
            }
            if (p->op == 3) {
                output = n2 + n1;
            }
            if (p->op == 4) {
                output = n2 / n1;
            }
            if (p->op == 5) {
                output = n2 * n1;
            }
            this->stack->push(new StackItem(0,output));
        }
        iss >> token;
    }
    return this->stack->top()->n;
}
bool Calculator::hasHigherPrecedence(string op,StackItem* item) {
    if(item->op == OPERATOR_MULTIPLICATION || item->op == OPERATOR_DIVISION)
        return false;
    else return (op == "*" || op == "/");
}
