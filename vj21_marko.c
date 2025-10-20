#include <stdio.h>
#include <stdlib.h>

int* fibonacci(int n) {
	if (n <= 0) return NULL;

	int* niz = (int*)malloc(n * sizeof(int));
	if (niz == NULL) {
		printf("Greska pri alokaciji memorije!\n");
		return NULL;
	}

	niz[0] = 1;
	if (n > 1)
		niz[1] = 1;

	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main() {
	int n;

	printf("Unesite broj elemenata Fibonacci niza: ");
	scanf("%d", &n);

	int* niz = fibonacci(n);

	if (niz != NULL) {
		printf("Fibonacci niz:\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", niz[i]);
		}
		printf("\n");

		free(niz);
	}

	return 0;
}
