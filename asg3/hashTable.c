//smorad@ucsc.edu
#include <stdio.h>
#include <stdlib.h>
#include "bookCountList.h"
/*Book is wrapper for bookList*/
typedef struct book{
	long id;
	ListRef bookList;
} *BookRef;
typedef struct HashSet {
	int size;
	int weight;
	BookRef *set;
} *HashRef;

HashRef createHashSet(){
	HashRef h = malloc(sizeof(struct HashSet));
	h->set = calloc (2, sizeof (BookRef));
	h->size=2;
	h->weight=0;
	return h;	
}

BookRef newBook(long id){
	BookRef b = malloc(sizeof(struct book));
	b->bookList = newList();
	b->id = id;
	return b;	
}
ListRef getBookList(BookRef b){
	return b->bookList;
}
long getId(BookRef b){
	return b->id;
}
int hash(HashRef h, long k){
	return k%h->size;
}
void doubleSize(HashRef h){
	int newSize = 2*h->size-1;
	int oldSize = h->size;
	h->size = newSize;
	BookRef *b = calloc(newSize, sizeof(BookRef));
	for(int i=0; i<oldSize; i++){
		if(h->set[i]==NULL) continue;
		int index = hash(h, getId(h->set[i]));
		while(b[index]!=NULL){
			index++;
		}	
		b[index] = h->set[i];
		
	}
	free(h->set);
	h->set = b;
}
BookRef insert(HashRef h, long k, BookRef b){ 
	if(b==NULL) b = newBook(k);
	if(h->weight * 2 >= h->size)
		doubleSize(h);	
	int index = hash(h,k);
	while(true){
		if(h->set[index]==NULL) break;
		++index;
		index = index%(h->size);
	}
	h->set[index] = b;
	++h->weight;
	return b;
}

BookRef getElement(HashRef h, long k){
	int count=0;
	int index = hash(h,k);
	while(true){
		if(h->set[index]!=NULL && getId(h->set[index]) == k)
			return h->set[index];
		++index;
		++count;
		index = index%(h->size);
		if(count>2*h->size) break;
	}
	return NULL;
}



void debugHash(HashRef h){
	for(int i=0; i<h->size; i++)
		if(h->set[i]==NULL)
			printf("[%-22d] : nil\n", i);
		else{
			printf("[%-10d: %-10lu] : ",i,getId(h->set[i]));
			printList(h->set[i]->bookList);
	}
}

/*Returns if specified slot is empty*/
int hashIsEmpty(HashRef h, int key){
	int  i = h->set[hash(h,key)]==NULL;
	return i;
}

/*Frees hash and all associated data members from memory*/
void destroy(HashRef h){
	for(int i=0; i<h->size; i++){
		if(h->set[i]!=NULL){
			if(h->set[i]->bookList !=NULL){
				makeEmpty(h->set[i]->bookList);
				freeList(h->set[i]->bookList);
			}
		free(h->set[i]);
		}
	}
	free(h->set);
	free(h);
}
