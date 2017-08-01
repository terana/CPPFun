#include "bit_array.h"
#include <stdexcept>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

extern "C" int gen_rand (int out, long n);

#define N 10000

void sort(std::ifstream& in, std::ofstream& out, long n) {
	bit_array A(n);
	for(long i = 0; i < n; i++) {
		A.clr(i);
	}
	long a;
	while(in >> a) {
		std::cout << a;
		A.set(a);
	}
	for(long i = 0; i < n; i++) {
		if(A.test(i)) {
			out << i << "\n";
		}
	}
}

int main() {
	int fd = open("numbers.txt", O_WRONLY | O_CREAT);
	if (fd < 0) {
		perror("Can't open file");
		exit(1);
	}
	int ret = gen_rand (fd, N);
	if (ret < 0) {
		perror("Can't open file");
		exit(1);
	}
	close(fd);

	std::ifstream in("numbers.txt");
	std::ofstream out("sorted.txt");

	sort(in, out, N);
	in.close();
	out.close();

}