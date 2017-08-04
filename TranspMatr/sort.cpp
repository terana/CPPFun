#include <fstream>
#include <iostream>
#include <stdlib.h>

#define SIZE 700

int comp(const void *a, const void *b) {
	const int *A = (const int *)a;
	const int *B = (const int *)b;
	return A[2] - B[2] == 0 ? A[1] - B[1] : A[2] - B[2];
}

int main() {
	std::ifstream in("matrix.txt");
	std::ofstream out("sort.txt");
	int matrix [SIZE*SIZE] [3];
	for (int i = 0; i < SIZE*SIZE; i++) {
		in >> matrix[i][0];
		matrix[i] [1]= i / SIZE;
		matrix[i] [2]= i % SIZE;
	}

	qsort(matrix, SIZE*SIZE, 3 * sizeof(int), comp);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			out << matrix[i * SIZE + j][0] << ' ';
		}
		out << '\n';
	}
}