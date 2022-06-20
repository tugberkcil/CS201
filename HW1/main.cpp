#include <iostream>
#include <string>
#include <fstream>
#include "TestBed.h"

using namespace std;

int main(int argc, char* argv[]) {
	string testfile;
	if (argc < 2) {
		cout << "Enter a test file name:" << endl;
		cin >> testfile;
	}
	else {
		testfile = argv[1];
	}
	ifstream file(testfile.c_str());
	if (file.is_open()) {
		cin.rdbuf(file.rdbuf());
	}
	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}
    TestBed *bed = new TestBed();
    bed->execute();

    delete bed;
    bed = nullptr;

    return 0;
}
