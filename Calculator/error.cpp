#include <iostream>
#include "error.h"

int no_of_errors;

double error(const char* s) {
	std::cerr << "error: " << s << "\n";
	no_of_errors++;
	return 1;
}