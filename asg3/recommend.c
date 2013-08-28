//smorad@ucsc.edu
#include "bookCountList.h"
#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*Inserts copurchases into hash*/
void addToHash(HashRef h, long bookId, ListRef * customers, int custNum, BookRef list){
	moveFirst(customers[custNum]);			//add cust previous books to hash of current book
	while(!offEnd(customers[custNum])){
			long current = getCurrent(customers[custNum]);
			if(getId(list)!= current){ //don't add itself to book list
				insertionSort(getBookList(list), current);
			}
			if(atLast(customers[custNum])) break;
				moveNext(customers[custNum]);
		
	}
}

/*Gets copurchases then adds to hash*/
void addCopurchase(HashRef h, long bookId, ListRef * customers, int custNum){
	BookRef list = getElement(h, bookId);
	if(list==NULL)
		list = insert(h, bookId, NULL);
	addToHash(h, bookId, customers, custNum, list);//add symmetrically, need for loop to add
	moveFirst(customers[custNum]);
	while(!offEnd(customers[custNum])){
		long id = getCurrent(customers[custNum]);
		BookRef l = getElement(h, id);
		if(l==NULL) 
			l = insert(h, id, NULL); 
		addToHash(h, id, customers, custNum, l);
		if(atLast(customers[custNum])) break;
			moveNext(customers[custNum]);
	}

}
/*Check if customer already purchased certain book*/
int customerCompare(long id, ListRef *customers, int custNum){
	ListRef l = customers[custNum];
	moveFirst(l);
	while(!offEnd(l)){
		if(getCurrent(l) == id)
			return true;
		if(atLast(l)) break;
		moveNext(l);	
	}
	return false;
}
/*Gets best recommendation then prints it*/
void printRecommendation(HashRef h, long bookId, ListRef* customers, int custNum){
	moveFirst(customers[custNum]);
	int max=0;
	long maxId=0;
	if(getElement(h,bookId)==NULL){	
		printf("No recommendations for book: %lu\n", bookId);
		return;
	}
	ListRef l = getBookList(getElement(h,bookId));
	moveFirst(l);
	while(!offEnd(l)){
		if(getCount(l) >=max && !customerCompare(getCurrent(l), customers, custNum)){
			max = getCount(l);
			maxId=getCurrent(l);
		}
		if(atLast(l)) break;
		moveNext(l);
		}
	if(maxId!=0)
		printf("Recommendation for book %lu is : %lu\n",bookId,maxId);
	else	
		printf("No recommendations for book: %lu\n", bookId);
}

void debugArray(ListRef* customers, int numCustomers){
	for(int i=0; i<numCustomers; i++){
		printList(customers[i]);
	}
}
/*Main function that reads in every transaction*/
void readTransactions(FILE* f, int numCustomers, int numTransactions){
	HashRef h = createHashSet();
	int custNum, wantPrint;
	int count =0;
	long bookId;
	ListRef customers[numCustomers];
	for(int i=0; i<numCustomers+1; i++)
		customers[i] = newList();
	while(count < numTransactions){
		++count;
		fscanf(f, "%d", &custNum);
		fscanf(f, "%lu", &bookId);
		fscanf(f, "%d", &wantPrint);
	if(hasBook(customers[custNum],bookId)){		//customer already bought book
	//	checkPurchased(customers, custNum, bookId);
		insertionSort(customers[custNum], bookId);
	}
	else{
		addCopurchase(h, bookId, customers, custNum);
		insertionSort(customers[custNum], bookId);
		}
		
	if(wantPrint){
		printRecommendation(h, bookId, customers, custNum);
	}
	
	}
	//debugHash(h);//uncomment me to see the hash status
	destroy(h);
	for(int i=0; i<numCustomers+1; i++){
		makeEmpty(customers[i]);
		freeList(customers[i]);
	}
}

/*Parses initial input*/
void readInput(FILE *f){
	int numCustomers;
	fscanf(f,"%d", &numCustomers);
	int numTransactions;
	fscanf(f,"%d", &numTransactions);
	int throwAway;
	fscanf(f, "%d", &throwAway);
	readTransactions(f, numCustomers, numTransactions);
}


int main(int argc, char** args){
	FILE *f;
	f = fopen(args[1], "r");
	if(f==NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}
	readInput(f);
	fclose(f);
	return EXIT_SUCCESS;
}
