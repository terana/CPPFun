#include "AST.h"
#include <iostream>

int main () {
	AST ast("1 + 2 * 3");
	ast.print();
	ast.draw();
	std::cout << ast.evaluate() << '\n';
}