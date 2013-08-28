#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
ListRef L; 

void testInsert(){
	insertAfterCurrent(L,5);
	printList(stdout, L);
	printf("%lu\n", getCurrent(L));
	insertAfterCurrent(L,4);
	printf("%lu\n", getCurrent(L));
	printList(stdout, L);
	insertAfterCurrent(L,3);
	printf("%lu\n", getCurrent(L));
	printList(stdout, L);
	insertAfterCurrent(L,2);
	printf("%lu\n", getCurrent(L));
	printList(stdout, L);
	insertAfterCurrent(L,1);
	printf("%lu\n", getCurrent(L));
	printList(stdout, L);
	insertAfterCurrent(L,0);
	printf("%lu\n", getCurrent(L));
	printList(stdout, L);
	insertAfterLast(L,100);
	insertBeforeFirst(L,1000);
	moveFirst(L);
	printf("current: %lu\n", getCurrent(L));
	moveNext(L);
	moveNext(L);
	moveNext(L);
	moveNext(L);
	moveNext(L);
	moveNext(L);
	moveNext(L);
	printf("current: %lu\n", getCurrent(L));
	movePrev(L);
	movePrev(L);
	movePrev(L);
	movePrev(L);
	movePrev(L);
	movePrev(L);
	movePrev(L);

	printf("current: %lu\n", getCurrent(L));	//error










}

void debug(){
	printf("is empty: %d\n", isEmpty(L));
	printf("off end: %d\n", offEnd(L));
	printf("at first is: %d\n", atFirst(L));
	printf("at last is: %d\n", atLast(L));

	insertBeforeFirst(L, 2);
	printList(stdout, L);

	insertBeforeFirst(L, 0);
	printList(stdout, L);

	insertAfterLast(L,4);
	printList(stdout, L);

	insertAfterCurrent(L,3);	
	printList(stdout, L);

	insertBeforeCurrent(L,1);
	printList(stdout, L);
	
	printf("traversions\n");
	moveLast(L);
	printf("current: %lu\n", getCurrent(L));

	moveFirst(L);
	printf("current: %lu\n", getCurrent(L));

	moveNext(L);
	printf("current: %lu\n", getCurrent(L));
	
	movePrev(L);
	printf("current: %lu\n", getCurrent(L));	//error
	
	ListRef newList = copyList(L);
	printList(stdout, newList);

	printf("deletions\n");
	deleteFirst(L);
	printList(stdout, L);
	
	deleteLast(L);					//error
	printList(stdout, L);
	
	printf("current: %lu\n", getCurrent(L));
	deleteCurrent(L);				//error
	printList(stdout, L);

	
	//insertBeforeCurrent(L, 50);			//makes it hard to read
	printf("get first: %lu\n", getFirst(L));
	printf("get last: %lu\n", getLast(L));
	//moveNext(L);
	printf("get current: %lu\n", getCurrent(L));
	printf("length: %d\n", getLength(L));
	printf("equals: %d\n", equals(L, newList));
	 
}
int main(){
	L=newList();
	//testInsert();
	debug();
}	
