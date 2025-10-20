#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;       
	int size;         
	int capacity;       
} Vector;
void vector_delete(Vector* v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
void vector_delete(Vector* v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
void vector_push_back(Vector* v, int value) {
	if (v->size >= v->capacity) {
		v->capacity *= 2;
		v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
		if (v->data == NULL) {
			printf("Realloc error!\n");
			exit(1);
		}
	}
	v->data[v->size++] = value;
}
void vector_pop_back(Vector* v) {
	if (v->size > 0) {
		v->size--;
	}
	else {
		printf("Vector is already empty!\n");
	}
}
int vector_front(Vector* v) {
	if (v->size > 0) {
		return v->data[0];
	}
	else {
		printf("Vector is empty!\n");
		return -1; 
	}
}
int vector_back(Vector* v) {
	if (v->size > 0) {
		return v->data[v->size - 1];
	}
	else {
		printf("Vector is empty!\n");
		return -1;
	}
}
int vector_size(Vector* v) {
	return v->size;
}
int main() {
	Vector v = vector_new(2);

	vector_push_back(&v, 10);
	vector_push_back(&v, 20);
	vector_push_back(&v, 30); 

	printf("Front: %d\n", vector_front(&v));
	printf("Back: %d\n", vector_back(&v));
	printf("Size: %d\n", vector_size(&v));

	vector_pop_back(&v);
	printf("After pop_back, size: %d\n", vector_size(&v));

	vector_delete(&v);
	return 0;
}

