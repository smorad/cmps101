//smorad@ucsc.edu
#ifndef __HASH_H
#define __HASH_H
#include "bookCountList.h"
typedef struct HashSet *HashRef;
typedef struct book *BookRef;	//wrapper for ListRef
HashRef createHashSet();	//creates new hash table

BookRef newBook(); 	//only used in driver, creates a new hash slot element

ListRef getBookList();		//removes wrapper from book
/*pre: h!=NULL, l!=NULL post: h->set(hash(key))!=NULL*/
BookRef insert(HashRef h,long k, BookRef l);	//insert into hash table
/*pre: h!=NULL*/
BookRef getElement(HashRef h, long key);	//returns associated list wrapper, null if not found
/*pre h!=NULL, h(index) !=NULL*/
long getId(BookRef b);		//returns bookId
/*pre: h!=NULL*/
void debugHash(HashRef h);			//prints content of hash table
/*pre: h!=NULL*/
int hashIsEmpty(HashRef h, long key);		//returns true if slot at h(key) is empty
/*post: hashtable removed from memory*/
void destroy(HashRef h);
#endif
