//smorad@ucsc.edu
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
ListRef L; 
void extraTests(){
	L=newList();
	printf("is empty: %d\n", isEmpty(L));
	printf("off end: %d\n", offEnd(L));
	printf("at first is: %d\n", atFirst(L));
	printf("at last is: %d\n", atLast(L));

	insertBeforeFirst(L, 0);
	printList( L);

	insertAfterLast(L,1);
	printList( L);

	insertAfterCurrent(L,5);
	printList( L);

	insertBeforeCurrent(L,10);
	printList( L);
	
	moveLast(L);
	printList( L);

	moveFirst(L);
	printList( L);

	moveNext(L);
	printList( L);
	
	movePrev(L);
	printList( L);
	

	moveNext(L);
	deleteFirst(L);
	printList( L);
	
	deleteLast(L);
	printList( L);
	
	deleteCurrent(L);
	printList( L);

	printf("inserting 50 before current\n");	
	insertBeforeCurrent(L, 50);
	printf("get first: %d\n", getFirst(L));
	printf("get last: %d\n", getLast(L));
	printf("get current: %d\n", getCurrent(L));
	printf("length: %d\n", getLength(L));
	makeEmpty(L);
	freeList(L);
	 
}	

int main(){
	extraTests();
	ListRef l=newList();
	insertionSort(l, 5);
	insertionSort(l, 4);
	insertionSort(l, 3);
	insertionSort(l, 5);
	printList(l);
	insertionSort(l, 3);
	insertionSort(l, 3);
	printList(l);
	makeEmpty(l);
	freeList(l);
}
