#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//#define BUFFSIZE 1024;
int numCus;
int numPur;
ListRef custArray[1024];
const int BUFFSIZE = 1024;

void parseInput(char* buffer){
	char* input = strdup(buffer);	//dont want to mess up our buffer
	char* user = strtok(input, " ");	//customer id
	char* product = strtok(NULL, " ");	//book id
	int userInt = atoi(user);
	long productInt = atol(product);	
	if(custArray[userInt]==NULL){
		custArray[userInt] = newList();
	}
	//insertBeforeFirst(custArray[userInt], productInt);	//select customer
	insertionSort(custArray[userInt], productInt);	//sort in order
	free(input);
	
}
void readInput(){
	char buffer[BUFFSIZE];
	int count = 0;
	while(fgets(buffer, BUFFSIZE, stdin)!=NULL){
		if(count>1){		//throw away first 2 linese
			parseInput(buffer);
			}
		count++;
		}
	printf("Customer #     Books Purchased\n");
	for(int i=1; i<count-2; i++){
			if(custArray[i]!=NULL){
				printf("%d               ", i);
				printList(stdout, custArray[i]);
				makeEmpty(custArray[i]);	
				freeList(custArray[i]);
			}
		}
}
void testList(){		//for debugging purposes only
	ListRef L = newList();
	insertBeforeFirst(L, 3);
	insertBeforeFirst(L, 2);
	insertBeforeFirst(L, 1);
	insertAfterLast(L, 4);
	insertAfterLast(L, 5);
	insertAfterLast(L, 6);
	printList(stdout, L);

}
void initArray(){
	for(int i=0; i<1024; i++){
		custArray[i] = NULL;
	}
}
	
int main(){
	initArray();
	readInput();
	//testList();
return EXIT_SUCCESS;
}
