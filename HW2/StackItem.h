//============================================================================
// Name        : StackItem.h
// Author      : Hasan Sozer
// Version     : 1.0
// Copyright   : (c) 2012 Ozyegin University
// Description : Includes the header file of the StackItem class that will be 
//               used as part of the program to be submitted as Homework 2,  
//               which is assigned in the context of the course CS201, 
//				 Data Structures and Algorithms.
//============================================================================

#ifndef __STACKITEM__
#define __STACKITEM__

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// constant definitions for operator types
#define OPERATOR_LEFTPAR		0
#define OPERATOR_RIGHTPAR		1
#define OPERATOR_MINUS			2
#define OPERATOR_PLUS			3
#define OPERATOR_DIVISION		4
#define OPERATOR_MULTIPLICATION 5

class StackItem {

public:
	bool isOperator; // set to true, if the stack item stores an operator; false, if it keeps an operand in an expression
	int op; // set to the type of operator (one of the constants above) if isOperator is true
	int n; // set to the value of the operand if isOperator is false
	StackItem *next; // will be used if the stack is implemented with a linked list approach
	
	StackItem(bool,int); // constructor. The second argument represents an operator type / operand value if the first argument is true / false
	StackItem(string);// constructor that parses a string representation of an operand/operator
    ~StackItem();
    int value();
	string toString(); // returns a string representation of the operator/operand
private:
	void init(bool, int); // private method that is utilized by the constructors to initialize the member attributes
};

#endif
