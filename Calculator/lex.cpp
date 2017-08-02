#include <iostream>
#include <ctype.h>
#include "error.h"
#include "lex.h"

token_value curr_tok;
double number_value;
char name_string[256];

token_value get_token() {
	char ch;
	do { // пропускает обобщенные пробелы за исключением '\n'
		if(!std::cin.get(ch)) 
			return curr_tok = END;
	} while (ch!='\n' && isspace(ch));
	switch (ch) {
		case ';':
		case '\n':
			std::cin >> std::ws;
			return curr_tok=PRINT;
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '=':
			return curr_tok=token_value(ch);
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		case '.':
			std::cin.putback(ch);
			std::cin >> number_value;
			return curr_tok=NUMBER;
		default:
			if (isalpha(ch)) {
			// NAME, NAME= или ошибка
				char* p = name_string;
				*p++ = ch;
				while (std::cin.get(ch) && isalnum(ch))
					*p++ = ch;
				std::cin.putback(ch);
				*p = 0;
				return curr_tok=NAME;
			}
			error("недопустимая лексема");
			return curr_tok=PRINT;
	}
}