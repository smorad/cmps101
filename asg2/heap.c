#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

typedef struct HeapHdr *heap;
struct HeapHdr{
	int maxSize;
	int currentSize;
	int last;
	int *arr;
};

heap newHeap (int maxSize){
	heap h = malloc(sizeof(struct HeapHdr));
	h->arr= calloc(maxSize+1, sizeof(int));
	h->maxSize = maxSize;
	h->currentSize=0;
	h->last = 0;
	return h;
}

int getLeft(int pos){
	return pos*2;
}
int getRight(int pos){
	return (pos)*2+1;	
}
int getParent(int pos){
	return pos/2;
}
int isFull(heap h){
	return h->last==h->maxSize;
}

int isEmpty(heap h){
	return h->last==0;
}


int maxValue(heap h){
	return h->arr[1];
}

void swap(heap h, int a, int b){
	int tmp = h->arr[a];
	h->arr[a] = h->arr[b];
	h->arr[b] = tmp;
}


void deleteMax(heap h){

	swap(h, 1, h->last--);
	h->arr[h->last+1] = -1;
	for(int parent = 1; parent<h->last;){
		int child = getLeft(parent);
		if(child>h->last) break;
		int rchild = getRight(parent);
		if(child<h->last && h->arr[rchild]>h->arr[child])	
			child = rchild;
		if(h->arr[child]>h->arr[parent]){
			swap(h, child, parent);
			parent = child;
		}
		else break;
	}

}



void insert(heap h, int priority){
	h->arr[++h->last] = priority;
	for(int child = h->last; child>1;){
		int parent = getParent(child);
		if(h->arr[child]<h->arr[parent]) break;
		swap(h, child, parent);
		child = getParent(child);
	}
}
void debugHeap(heap h){
	for(int i=1; i<h->maxSize+1; i++)
		printf("Slot: %d priority: %d\n", i, h->arr[i]); 
}

void delete(heap h){
	if(h->arr!=NULL && sizeof(h->arr)!=0)
		free(h->arr);
	free(h);
}
