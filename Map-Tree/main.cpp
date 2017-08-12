#include "RBTree.h"
#include <string>

int main() {
	RBTree<int, std::string> tree(0,"");
	tree.insert(11, "11");
	tree.insert(3, "3");
	tree.insert(7, "7");
	tree.insert(2, "2");
	tree.insert(6, "6");
	tree.dump();
	std::cout<< "---------\n";
	tree.remove(6);
	tree.remove(7);
	tree.dump();
}