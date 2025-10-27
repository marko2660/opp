#include <iostream>
#include <cstddef> 
#include<stdio.h>

inline bool ascending(int a, int b) {
	return a > b; 
}

inline bool descending(int a, int b) {
	return a < b; 
}

void sortt(int arr[], std::size_t size, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < size - 1; ++i) {
		for (std::size_t j = i + 1; j < size; ++j) {
			if (cmp(arr[i], arr[j])) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void printArray(const int arr[], std::size_t size) {
	for (std::size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	int niz[] = { 5, 2, 9, 1, 7 };
	std::size_t velicina = sizeof(niz) / sizeof(niz[0]);

	std::cout << "Pocetni niz: ";
	printArray(niz, velicina);

	sortt(niz, velicina, ascending);
	std::cout << "Uzlazno sortirano: ";
	printArray(niz, velicina);

	sortt(niz, velicina, descending);
	std::cout << "Silazno sortirano: ";
	printArray(niz, velicina);

	return 0;
}
