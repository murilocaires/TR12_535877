#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

//Função de comparação
int comparar(void* x, void* y) {
	int intX = *((int*) x);
	int intY = *((int*) y);

	if (intX < intY) {
		return 1;
	} else if(intX == intY) {
		return 0;
	} 
	
	return -1;
}

int main() {
  int MAX_SIZE = 100;

  HEAP* heap = HEAP_create(MAX_SIZE, comparar);
  int numbers[] = { 97, 64, 78, 18, 71, 6, 92, 37, 48, 98, 14, 44, 54, 37, 91, 74, 39, 4, 100, 83, 41, 95, 73, 53, 67, 36, 15, 38, 15, 100, 24, 52, 29, 57, 32, 28, 76, 9, 94, 96, 75, 60, 77, 37, 43, 84, 44, 28, 40, 53, 37, 60, 10, 7, 95, 9, 98, 1, 24, 45, 84, 90, 36, 97, 20, 73, 36, 18, 71, 41, 77, 55, 77, 82, 27, 57, 46, 22, 14, 44, 15, 53, 23, 88, 89, 32, 39, 70, 65, 94, 18, 24, 72, 39, 30, 96, 43, 73, 42, 40 };

  double time_spent = 0.0;
  clock_t begin = clock();

  //adicionar elementos
	for (int i = 0; i < heap->N; i++) {
    HEAP_add(heap, &numbers[i]);
	}

  printf("\n");
  
  //print elements from heap  
  for (int i = 0; i < heap->N; i++) {
    printf("%d ", *((int*)heap->elems[i]));
  }

  printf("\n");

  for (int i = 0; i < heap->N; i++) {
    printf("Removido: %d\n", *((int*) HEAP_remove(heap)));
  }

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Time elpased is %f seconds", time_spent);

  return 0;
}