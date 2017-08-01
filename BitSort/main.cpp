#include "bit_array.h"
#include <stdexcept>
#include <iostream>

int main() {
	try {
	bit_array A(12);
		A.print();
		A.set(1);
		A.print();
		A.set(2);
		A.print();
		A.clr(1);
		A.print();
		A.set(12);
	} catch(std::invalid_argument Err) {
		std::cout<<"Cought "<<Err.what()<<"\n";
	}
}