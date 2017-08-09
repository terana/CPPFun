#include "dlist.h"

/* dlist implementation  */

void dlist_base::insert(dlink* a) {
	if (tail) {
		a->next = tail->next;
		a->prev = tail;
	}
	else
		tail = a;
	tail->next = a;
	a->next->prev = a;
}

void dlist_base::append(dlink* a) { // добавить в конец списка
	if (tail) {
		a->next = tail->next;
		a->prev = tail;
		tail = tail->next = a;
	} else
		tail = a->next = a;
	a->next->prev = a;
}


dlink* dlist_base::get() {// удалить и возвратить начало списка
	if (tail == 0)
		return 0;
	dlink* f = tail->next;
	if (f == tail)
		tail = 0; 
	else {
		tail->next = f->next;
		tail->next->prev = tail;
	}
    return f;
}

dlist_base_iter::dlist_base_iter(dlist_base& d) {
	cd = &d;
	ce = cd->tail;
}

dlink* dlist_base_iter::operator()() { // возвращает 0, когда итерация кончается
     dlink* ret = ce ? (ce=ce->next) : 0;
     if (ce == cd->tail) 
     	ce = 0;
     return ret;
}