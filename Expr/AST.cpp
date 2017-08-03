#include <string.h>
#include <iostream>
#include <strstream>
#include "AST.h"
#include "AST_builder.h"

AST::AST(const char *exp) {
	int len = strlen(exp) + 1;
	expr_ = new char[len];
	strcpy(expr_, exp);
	std::istrstream in(expr_, len);
	root_ = build_AST(in);
}

void delete_node(node* n) {
	if (n->left)
		delete_node(n->left);
	if (n->right)
		delete_node(n->right);
	delete n;
}

AST::~AST() {
	delete_node(root_);
	delete expr_;
}

void draw_node(node *n) {
	switch (n->type) {
		case NUMBER:
			std::cout << n->number_value << ' ';
			break;
		case PLUS:
		case MINUS:
		case DIV:
		case MUL:
			std::cout << (char) n->type << ' ';
			std::cout << '\n';
			break;
		default:
			std::cout << '?';
	}
	if (n->left) {
		draw_node(n->left);
	}
	std::cout << '\t';
	if (n->right) {
		draw_node(n->right);
	}
}

void AST::draw() {
	draw_node(root_);
	std::cout << '\n';
}

double AST::evaluate() {
	return root_->number_value;
}