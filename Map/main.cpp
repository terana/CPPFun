#include "map.h"
#include <iostream>
#include <string>

template<class K, class V>
	void readlines(Map<K,V>&key) {
	K word;
	while (std::cin >> word) {
		V val  = 0;
		if (std::cin >> val)
			key[word] +=val;
		else
			return;
	}
}

int main() {
	Map<std::string,int> tbl("nil",0);
	readlines(tbl);
	int total = 0;
	for (Mapiter<std::string,int> p(tbl); p; ++p) {
		int val = p.value();
		total +=val;
		std::cout << p.key() << '\t' << val << '\n';
	}
	std::cout << "--------------------\n";
	std::cout << "total\t" << total << '\n';
}
