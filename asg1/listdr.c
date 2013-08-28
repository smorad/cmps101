#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
ListRef L; 
int main(){
	L=newList();
	printf("is empty: %s\n", isEmpty(L));
	printf("off end: %s\n", offEnd(L));
	printf("at first is: %s\n", atFirst(L));
	printf("at last is: %s\n", atLast(L));

	insertBeforeFirst(L, 0);
	printList(stdout, L);

	insertAfterLast(L,1)
	printList(stdout, L);

	insertAfterCurrent(L,5)	
	printList(stdout, L);

	insertBeforeCurrent(L,10);
	printList(stdout, L);
	
	moveLast(L);
	printList(stdout, L);

	moveFirst(L);
	printList(stdout, L);

	moveNext(L);
	printList(stdout, L);
	
	movePrev(L);
	printList(stdout, L);
	
	ListRef newList = copyList(L);
	printList(stdout, newList);

	moveNext(L);
	deleteFirst(L);
	printList(stdout, L);
	
	deleteLast(L);
	printList(stdout, L);
	
	deleteCurrent(L);
	printList(stdout, L);

	
	insertBeforeCurrent(L, 50);
	printf("get first: %lu\n", getFirst(L));
	printf("get last: %lu\n", getLast(L));
	moveNext(L);
	printf("get current: %lu\n", getCurrent(L));
	printf("length: %d\n", getLength(L));
	printf("equals: %d", equals(L, newList));
	 
}	
