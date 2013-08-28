#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"
void heapSort(int keys[], int numKeys){
	heap h = newHeap(numKeys);	
	for(int iter = 0; iter<numKeys; iter++){
		insert(h, keys[iter]);
	}
	int tmp[numKeys];
	for(int i=0; i<numKeys; i++){
		tmp[i] = maxValue(h);
		deleteMax(h);
	}
	for(int i=0; i<numKeys; i++){
		keys[numKeys-i-1]=tmp[i];
	}
	delete(h);
	

}
