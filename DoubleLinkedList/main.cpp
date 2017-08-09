#include "dlist.h"
#include <iostream>

class name : public dlink {

};

int main() {
	const int num = 42;
    Dlist<int> dlist;
    dlist.insert(num);
    
     int *o;
     Dlist_iter<int> it(dlist);
     o = it();
     std::cout << *o << '\n';
     o = it();
     std::cout << (o ? *o : '0') << '\n';


     name n;
     Idlist<name> lst1;
     Dlist<name> lst2;
     lst1.insert(&n);
     lst2.insert(n);
     // ...
     Idlist_iter<name> iter1(lst1);
     const name* p;
     while (p=iter1()) {
		Dlist_iter<name> iter2(lst2);
		const name* q;
		while (q=iter2()) {
			if (p == q) 
				std::cout << "найден"  << '\n';
		}
	}
}
