#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"
#include "heap.h"
//typedef struct HeapHdr *heap;
int main(){
	heap h = newHeap(10);
	for(int i=0; i<10; i++){
		insert(h, i);
	//	printf("%d\n", maxValue(h));
	}
	debugHeap(h);
	printf("Done inserting\n");

	for(int i=0; i<10; i++){
		printf("%d\n", maxValue(h));
		deleteMax(h);
	//	debugHeap(h);
	}
	printf("manual insertion\n");
	insert(h, 2);
	insert(h, 4);
	insert(h, 6);
	insert(h, 6);
	insert(h, 4);
	insert(h, 2);
	//debugHeap(h);
	
	printf("%d\n", maxValue(h));
	deleteMax(h);

	
	printf("%d\n", maxValue(h));
	deleteMax(h);

	
	printf("%d\n", maxValue(h));
	deleteMax(h);
		
	printf("%d\n", maxValue(h));
	deleteMax(h);
	printf("%d\n", maxValue(h));
	deleteMax(h);
	printf("%d\n", maxValue(h));
	deleteMax(h);
}

