#include <stdlib.h>
#include <stdio.h>

long randlong(long l, long u) {
	return random() % (u - l + 1) + l;
}

void swap (long *a, long *b) {
	long *c = b;
	*b = *a;
	*a = *c;
}

int gen_rand (int out, long n) {
	long *arr = (long *) malloc(n * sizeof(long));
	if (arr == NULL)
	  	return -1;
	 for (long i = 0; i < n; i++) {
	 	arr[i] = i;
	 }
	 int ret;
	 for(long i = 0; i < n; i++) {
	 	swap(arr + i, arr + randlong(i, n - 1));
	 	ret = dprintf(out, "%ld\n", arr[i]);
	 	if (ret < 0) {
	 		free(arr);
	 		return ret;
	 	}
	 }

	 free(arr);
	 return 0;
}