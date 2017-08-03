#include "AST.h"
#include <strstream>
#include "error.h"

static token_value curr_tok;
static double number_value;

node * expr(std::istrstream& in);

token_value get_token(std::istrstream& in) {
	char ch;
	do { // пропускает обобщенные пробелы за исключением '\n'
		if(!in.get(ch)) 
			return curr_tok = END;
	} while (ch!='\n' && isspace(ch));
	switch (ch) {
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
			in.putback(ch);
			in >> number_value;
			return curr_tok=NUMBER;
		default:
			return curr_tok=END;
	}
}

node * prim(std::istrstream& in) {
	node *curr;
	switch (curr_tok) {
		case NUMBER:
			curr = new node;
			curr->left = curr->right = NULL;
			curr->type = curr_tok;
			curr->number_value = number_value;
			get_token(in);
			return curr;
		case MINUS:
			get_token(in);
			curr = prim(in);
			curr->number_value = -curr->number_value;
			return curr;
		case LP:
			get_token(in);
			curr = expr(in);
			if (curr_tok != RP)
				error("требуется )");
				return NULL;
			get_token(in);
			return curr;
		case END:
			return NULL;
		default:
			error("требуется первичное");
			return NULL;
	}
}

node * term(std::istrstream& in) {
	node *left = prim(in);
	node *curr = new node;
	curr->type = curr_tok;
	curr->left = left;;
   	switch(curr_tok) {
		case MUL:
			get_token(in);
			curr->right = prim(in);
			curr->number_value = left->number_value * curr->right->number_value;
			return curr;
		case DIV:
			get_token(in);
			curr->right = prim(in);
			if (curr->right->number_value == 0) {
				error("деление на 0");
			}
			curr->number_value = left->number_value / curr->right->number_value;
			return curr;
		default:
			delete curr;
			return left;
	}
}

node * expr(std::istrstream& in) {
	node *left = term(in);
	node *curr = new node;
	curr->left = left;
	curr->type = curr_tok;
   	switch(curr_tok) {
		case PLUS:
			get_token(in);
			curr->right = term(in);
			curr->number_value = left->number_value + curr->right->number_value;
			return curr;
		case MINUS:
			get_token(in);
			curr->right = term(in);
			curr->number_value = left->number_value - curr->right->number_value;
		default:
			delete curr;
			return left;
	}
}

node * build_AST(std::istrstream& in) {
	get_token(in);
	return expr(in);
}