#include <iostream>
#include "error.h"
#include "lex.h"
#include "syn.h"
#include "table.h"

table var_names(10);

int main(int argc, char* argv[]) {
	var_names.insert("pi")->value = 3.1415926535897932385;
	var_names.insert("e")->value = 2.7182818284590452354;
	while (std::cin) {
		get_token();
		if (curr_tok == END) 
			break;
		if (curr_tok == PRINT) 
			continue;
		std::cout << expr() << '\n';
	}
	return no_of_errors;
}
