#include "table.h"
#include "error.h"
#include "string.h"

table::table(int sz) {
	if (sz < 0)
		error("размер таблицы отрицателен");
	tbl = new name*[size = sz];
	for ( int i = 0; i<sz; i++) 
		tbl[i] = 0;
  }

table::~table() {
	for (int i = 0; i<size; i++) {
		name* nx;
		for (name* n = tbl[i]; n; n = nx) {
			nx = n->next;
			delete n->string;
			delete n;
		}
	}
	delete tbl;
}

name* table::look(const char* p, int ins) {
	int ii = 0;
	const char* pp = p;
	while (*pp) 
		ii = ii<<1 ^ *pp++;
	if (ii < 0) ii = -ii;
		ii %= size;
	for (name *n = tbl[ii]; n; n = n->next)
		if (strcmp(p, n->string) == 0) 
			return n;
	name* nn = new name;
	nn->string = new char[strlen(p)+1];
	strcpy(nn->string,p);
	nn->value = 1;
	nn->next = tbl[ii];
	tbl[ii] = nn;
	return nn;
}