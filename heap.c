#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* M;
  heapElem* A = (heapElem *) malloc(sizeof(heapElem));
  M = (Heap *) malloc(sizeof(Heap));
  M->size = 0;
  M->capac = 3;
  A->data = NULL;
  A->priority = 0;
   return M;
}
