#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
  int h = 0;
  if(pq->size == pq->capac){
    pq->heapArray = (heapElem *) realloc(pq->heapArray, pq->capac * 2 *sizeof(heapElem) + 1);
    pq->capac = (pq->capac * 2) + 1;
  }

  pq->heapArray[pq->size].priority = priority;
  pq->heapArray[pq->size].data = data;
  pq->size++;

  heapElem aux = pq->heapArray[(pq->size) - 1];
  h = (pq->size) - 1;

  //el padre siempre siempre es (h - 1)/2  (no olvidar!!) 
  while(h != 0 && pq->heapArray[h].priority > pq->heapArray[(h - 1)/2].priority){
    aux = pq->heapArray[h];
    pq->heapArray[h] = pq->heapArray[(h - 1)/2];
    pq->heapArray[(h - 1)/2] = aux;
    h = (h - 1)/2;
    //break;
  }
}

void heap_pop(Heap* pq){
  int h = 0;
  heapElem aux =  pq->heapArray[h];
  pq->heapArray[h].priority = 0; 
  pq->heapArray[h] = pq->heapArray[(pq->size) - 1];
  //pq->heapArray[(pq->size) - 1] = aux;
  
  while(h < pq->size- 1){    
    //ver cuál hijo es mayor 
    int mayor;
    if(pq->heapArray[(2*h) +1].priority > pq->heapArray[(2*h) + 2].priority){
      mayor = (2*h) + 1; //izquierdo
    }
    else{
      mayor = (2*h) + 2; //derecho
    }

    if(mayor != h){
      aux = pq->heapArray[h];
      pq->heapArray[h] = pq->heapArray[mayor];
      pq->heapArray[mayor] = aux;
      h = mayor;
    }
    else{
      break;
    }
    
    /*if((2*h) + 2 < pq->size - 1 && pq->heapArray[h].priority < mayor.priority){
      aux = mayor;
      mayor = pq->heapArray[h];
      pq->heapArray[h] = aux;
      h = (2*h) + 2;
      //break;
    }*/
    
    if(pq->heapArray[(2*h + 1)].priority > pq->size -1 && pq->heapArray[(2*h + 2)].priority > pq->size - 1) 
      break;
  }
  pq->size--;
}

Heap* createHeap(){
  Heap* M;
  M = (Heap *) malloc(sizeof(Heap));
  M->heapArray = (heapElem *) malloc(sizeof(heapElem) * 3);
  M->size = 0;
  M->capac = 3;
   return M;
}
