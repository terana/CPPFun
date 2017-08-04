#include <fstream>
#include <stdlib.h>

#define SIZE 700

int main() {
	std::ofstream out("matrix.txt");
	for (int i = 0; i < SIZE*SIZE; i++) {
		out << random() % 100000 << ' ';
	}
	out.close();
}