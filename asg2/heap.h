#ifndef __HEAP_H
#define	__HEAP_H 
typedef struct HeapHdr *heap;

heap newHeap (int maxSize);

int isFull(heap h);

int isEmpty(heap h);

int maxValue(heap h);

void deleteMax(heap h);

void insert(heap h, int priority);

void debugHeap(heap h);

int getMin(int a, int b, int c);

void delete(heap h);
#endif
