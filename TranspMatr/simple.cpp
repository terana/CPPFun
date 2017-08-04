#include <fstream>

#define SIZE 700

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	std::ifstream in("matrix.txt");
	std::ofstream out("simple.txt");
	int matrix [SIZE] [SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			in >> matrix[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			swap(&(matrix[i][j]), &(matrix[j][i]));
		}
	}	

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			out << matrix[i][j]<< ' ';
		}
		out << '\n';
	}
}