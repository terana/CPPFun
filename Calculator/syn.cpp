#include "error.h"
#include "lex.h"
#include "table.h"
#include "syn.h"

double prim() {
	double e;
	switch (curr_tok) {
		case NUMBER:
			get_token();
			return number_value;
		case NAME:
			if (get_token() == ASSIGN) {
				name* n = var_names.insert(name_string);
				get_token();
				n->value = expr();
				return n->value;
			}
			return var_names.look(name_string)->value;
		case MINUS:
			get_token();
			return -prim();
		case LP:
			get_token();
			e = expr();
			if (curr_tok != RP) 
				return error("требуется )");
			get_token();
			return e;
		case END:
			return 1;
		default:
			return error("требуется первичное");
	}
}

double term() {
	double d;
	double left = prim();
	for(;;)
    	switch(curr_tok)    {
			case MUL:
				get_token();
				left *= prim();
				break;
			case DIV:
				get_token();
				d = prim();
				if (d == 0) 
					return error("деление на 0");
				left /= d;
				break;
			default:
				return left;
		}
}

double expr() {
	double left = term();
  	for(;;)
    	switch(curr_tok) {
			case PLUS:
				get_token();
				left += term();
				break;
			case MINUS:
				get_token();
				left -= term();
				break;
			default:
				return left;
		}
}