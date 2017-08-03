#include <iostream>

enum token_value {
	NUMBER, END,
	PLUS='+',	MINUS='-',	MUL='*',	DIV='/',
	LP='(',		RP= ')'
};

struct node {
	token_value type;
	double number_value;
	char *name;

	node *left;
	node *right;
};

class AST {
	char *expr_;
	node *root_;
public:
	AST(const char *expr);
	~AST();
	void print() {std::cout << "expr " << expr_ << '\n'; };
	void draw();
	double evaluate();
};