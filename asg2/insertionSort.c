#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int keys[], int numKeys){
	int insert = 0;
	int index = 0;
	for(int i = 1; i<numKeys; i++){
		insert = keys[i];
		index = i;
		while(index>0 && insert<keys[index-1]){
			keys[index] = keys[index-1];
			--index;
		}
		keys[index]=insert;
	}

}
