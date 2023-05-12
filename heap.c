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
    pq->capac = (pq->capac * 2) + 1;
  }

  pq->heapArray[pq->size].priority = priority;
  pq->heapArray[pq->size].data = data;
  pq->size++;

  /*while(){
    
  }*/
  
  
}


void heap_pop(Heap* pq){
 int h = 0;
  while(pq->heapArray[pq->size].priority != 0){
    int aux = pq->heapArray[pq->size].priority;
    pq->heapArray[0].priority = aux;
    pq->heapArray[pq->size].data = NULL;
    pq->size--;
    break;
  }
   
  /*int aux = 0;
    while(pq->heapArray[h].priority < pq->heapArray[2*h + 1].priority){  
      aux = pq->heapArray[h].priority;
      pq->heapArray[h].priority = pq->heapArray[2*h + 1].priority;
      pq->heapArray[2*h + 1].priority = aux;
      break;
    }

    while(pq->heapArray[h].priority < pq->heapArray[2*h + 2].priority){  
      aux = pq->heapArray[h].priority;
      pq->heapArray[h].priority = pq->heapArray[2*h + 2].priority;
      pq->heapArray[2*h + 1].priority = aux;
      break;
    }
    
  */
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
