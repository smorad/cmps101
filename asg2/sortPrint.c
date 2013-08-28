#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapSort.h"
#include "insertionSort.h"
int const HEAP_SIZE = 100000;
//typedef struct HeapHdr *heap;

void printSort(int* arr, int* arr2, int count){
	for(int i=0;i<count;i++){
		printf("InsSort:\t %d \t", arr[i]);
		printf("HeapSort: \t %d\n",arr2[i]);
		//deleteMax(h);
	}
}
void readFile(FILE *fp){
	int buff;
	int num = 0;
	int arr[HEAP_SIZE];
	int arr2[HEAP_SIZE];
	while(fscanf(fp,"%d", &buff)!=-1){
		arr[num] = buff;
		arr2[num]=buff;
		++num;
	}
	insertionSort(arr, num);
	heapSort(arr2, num);
	printSort(arr, arr2, num);
}

void openFile(char* file){
	FILE *fp = fopen(file, "r");
	if(fp==NULL){
		printf("Invalid filename\n");
		exit(1);
	}
	readFile(fp);
	fclose(fp);
	
}

int main(int argv, char** args){
	openFile(args[1]);
}
