#pragma once
#include "Header.h"

class NotFoundException {
public:
	NotFoundException(const char* str) {
		cout << endl << str << endl;
	}
};
