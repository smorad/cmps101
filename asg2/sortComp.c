#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"
#include "heapSort.h"
#include "insertionSort.h"
int const HEAP_SIZE = 100000;
heap h;
clock_t startTime, duration;
void readFile(FILE *fp){
	int buff;
	int num = 0;
	int arr[HEAP_SIZE];
	while(fscanf(fp, "%d", &buff)!=-1){
		arr[num++] = buff;
	}	
	startTime = clock(); 
	insertionSort(arr, num);
	duration = clock()-startTime;
	printf("Insertion sort took %f seconds.\n", ((float)duration/CLOCKS_PER_SEC));
}


void readFileHeap(FILE *fp){
	int buff;
	int num = 0;
	int arr[HEAP_SIZE];
	while(fscanf(fp,"%d", &buff)!=-1){
		arr[num++] = buff;
	}
	startTime = clock();
	heapSort(arr, num);
	duration = clock()-startTime;
	printf("Heapsort took %f seconds.\n", ((float)duration/CLOCKS_PER_SEC));
}

void openFile(char* file){
	FILE *fp = fopen(file, "r");
	if(fp==NULL){
		printf("Invalid filename\n");
		exit(1);
	}
	readFile(fp);
	readFileHeap(fp);
	fclose(fp);
	
}

int main(int argv,char** args){
	h = newHeap(HEAP_SIZE);
	openFile(args[1]);
	delete(h);
}
