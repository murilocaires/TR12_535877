#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Função que cria a heap e aloca o espaço necessário para ela e para o vetor de seus elementos
HEAP* HEAP_create(int n, COMP* compara) {
  HEAP* heap = malloc(sizeof(HEAP));
  heap->N = n;
  heap->P = 0;
  heap->elems = malloc(n * sizeof(void*));
  heap->comparador = compara;
  return heap;
}

//Função que adicina um elemento na heap e fazer a sua ordenação
void HEAP_add(HEAP* heap, void* elem) {
  // Verifica se a quantidade de elementos do array é igual ao a capacidade máxima
  if (heap->P == heap->N) {  
    printf("Heap cheio!\n");
    return;
  }
 
  if (heap->P == 0) {
    heap->elems[0] = elem;
    heap->P++;
    return;
  }
 
  int parent = heap->P;
  heap->elems[parent] = elem;
  // Organiza a heap
  while (heap->comparador(heap->elems[parent], heap->elems[(parent - 1) / 2]) == 1) { 
    void* aux = heap->elems[parent];
    heap->elems[parent] = heap->elems[(parent - 1) / 2];
    heap->elems[(parent - 1) / 2] = aux;

    parent = (parent - 1) / 2;
  }

  heap->P++;  
}

//Função que remove o elemento da heap e faz a sua reordenação
void* HEAP_remove(HEAP* heap) {
  if (heap->P == 0) {
    printf("Heap vazio!\n");
    return NULL;
  }

  void* minimum = heap->elems[0]; // Guarda o valor minimo
  heap->elems[0] = heap->elems[heap->P - 1]; // Atribui ao primeiro elemento do array da heap o valor do último
  
  heap->P--;

  int parent = 0;
  int child = 1;

//Reordena a heap
  while (child < heap->P) {
    if (child + 1 < heap->P) {
      if (heap->comparador(heap->elems[child], heap->elems[child + 1]) == -1) {
        child++;
      }
    }

    if (heap->comparador(heap->elems[parent], heap->elems[child]) == -1) {
      void* aux = heap->elems[parent];
      heap->elems[parent] = heap->elems[child];
      heap->elems[child] = aux;

      parent = child;
      child = 2 * parent + 1;
    } else {
      break;
    }
  }

  return minimum;
}