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
  int h = 0;
  if(pq->size == 0) return NULL;
  /*if(pq->heapArray->data == NULL) return NULL;
  if(pq->heapArray[h].priority > pq->heapArray[h + 1].priority){
    pq->heapArray->data = NULL;*/
  return pq->heapArray[h].data;
  return NULL;
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    pq->heapArray = (heapElem *) realloc(pq->heapArray, pq->capac * 2 *sizeof(heapElem) + 1);
  }
  //int h = 0; 
  pq->heapArray[pq->size].priority = priority;
  pq->heapArray[pq->size].data = data;

  /*while(){
    
  }*/
  
  
}


void heap_pop(Heap* pq){
  int h = 0;
  int aux;
  //Heap * aux = (Heap*) malloc(sizeof(Heap));
  while(pq->heapArray[pq->size].data != NULL){
    aux = pq->heapArray[pq->size].priority;
    pq->heapArray[h].priority = aux;
    pq->heapArray[pq->size].priority = 0;
    pq->size--;
    break;
  }
  //return NULL;
}

Heap* createHeap(){
  Heap* M;
  M = (Heap *) malloc(sizeof(Heap));
  M->heapArray = (heapElem *) malloc(sizeof(heapElem) * 3);
  M->size = 0;
  M->capac = 3;
   return M;
}
