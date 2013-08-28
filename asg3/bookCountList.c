//smorad@ucsc.edu
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct ListHdr *ListRef;
typedef struct Node *NodeRef;
struct ListHdr{
NodeRef first;
NodeRef last;
NodeRef current;
};

struct Node{
long book;
unsigned count;
NodeRef next;
NodeRef prev;
};

// Constructors
 /*** Constructors-Destructors ***/
 ListRef newList(){
	ListRef list = malloc(sizeof (struct ListHdr));
	list->first = list ->last = list->current = NULL;
	return list;
}

unsigned getCount(ListRef L){
	assert(L!=NULL);
	return L->current->count;
}
 void freeList(ListRef* pL){
	free(pL);
}
 /*** Access functions ***/
 int isEmpty(ListRef L){
	//assert(L!=NULL);
 	if((L->first == NULL) || L->last == NULL) return true;
	else return false;
}
 int offEnd(ListRef L){
	if(L->current == NULL) return true;
	else return false;
}
int atFirst(ListRef L){
	if(!offEnd(L)&&L->current == L->first) return true;
	else return false;
}
 int atLast(ListRef L){
	if(!offEnd(L)&&L->current == L->last) return true;
	else return false;
}
 long getFirst(ListRef L){
	//assert (L->first!=NULL);
	return L->first->book;
}
 long getLast(ListRef L){
	//assert (L->last!=NULL);
	return L->last->book;
}
 long getCurrent(ListRef L){
	//assert(L->current!=NULL);
	return L->current->book;
}
 int getLength(ListRef L){
	NodeRef iter = L->first;
	int count = 0;
	while(iter!=NULL){
		count++;
		iter = iter->next;
	}
	return count;
} 
 int equals (ListRef A, ListRef B) {
	NodeRef iterA = A->first;
	NodeRef iterB = B->first;
	while(iterA !=NULL && iterB!=NULL){
	if(iterA->book != iterB->book) return false;
	iterA = iterA->next;
	iterB = iterB->next;
	}
return true;
}
// /*** Manipulation procedures ***/
 void makeEmpty(ListRef L){
	while(L->first!=NULL){
		NodeRef tmp = L->first;
		L->first = L->first->next;
		free(tmp);
	}
}
 void moveFirst(ListRef L){
	//assert(!isEmpty(L));
	if(L->first !=NULL)
		L->current = L->first;
}
 void moveLast(ListRef L){
	//assert(!isEmpty(L));
	if(L->last!=NULL)
		L->current = L->last;
}
 void movePrev(ListRef L){
	//assert(!offEnd(L));
	if(L->current->prev !=NULL)
		L->current = L->current->prev;
} 
 void moveNext(ListRef L){
	//assert(!offEnd(L));
	if(L->current->next!=NULL)
		L->current = L->current->next;
}

void insertAfterLast(ListRef L, long data);
 ListRef copyList(ListRef L){
	ListRef newList = malloc(sizeof(struct ListHdr));
	for(NodeRef iter = L-> first; iter !=NULL; iter=iter->next){
		insertAfterLast(newList, iter->book);
	}
	return newList;
}

 NodeRef createNode(long book){
	NodeRef node = malloc(sizeof(struct Node));
	node -> next = NULL;
	node -> prev = NULL;
	node -> book = book;
	node ->count = 1;
	return node;
}
int hasBook(ListRef L, long data){
	NodeRef iter = L->first;
	while(iter!=NULL){
		if(iter->book==data) return 1;
		iter=iter->next;
	}
	return 0;
}
 void insertBeforeFirst(ListRef L, long data){
	NodeRef node = createNode(data);
	if(isEmpty(L)) L->first= L->last =L->current= node;
	else {
		node -> next = L->first;
		L->first->prev = node;
		L->first = node;
	}	
	//printf("Is empty: %d", isEmpty(L));
}
 void insertAfterLast(ListRef L, long data){
	NodeRef node = createNode(data);
	if(isEmpty(L)) L->first = L->last =L->current= node;
	//else if(L->last == NULL) L->last = L->first = L->current = node;
	else{
		node->prev = L->last;
		L->last->next = node;
		L->last = node;
	}
} 
 void insertBeforeCurrent(ListRef L, long data){
	NodeRef node = createNode(data);
	if(isEmpty(L)) L->first = L->last =L->current = node;
	else if(L ->current ->prev == NULL){
		L->first->prev = node;
		node -> next = L->first;
		L -> first = node;
	}
	else{
		NodeRef a = L->current->prev;
		NodeRef b = node;
		NodeRef c = L->current;
		b->next = a->next;
		b->prev = a;
		a->next = b;
		c->prev = b;
	}
	
} 
 void insertAfterCurrent(ListRef L, long data){
	NodeRef node = createNode(data);
	if(isEmpty(L)) L->first= L->last = L->current =node;
	else if(L->current->next == NULL){
		L->last->next = node;
		node-> prev = L->last;
		L->last = node;
	}
	else{
		NodeRef a = L->current;
		NodeRef b = node;
		NodeRef c = L->current->next;
		b->next = a->next;
		b->prev = a;
		a->next = b;
		c->prev = b;
	}
}

 void deleteFirst(ListRef L){
	//assert(!isEmpty(L));
	NodeRef tmp = L->first;
	L->first = L-> first ->next;
	L->first->prev = NULL;
	if(L->current == tmp)
		L->current = L->first;
	free(tmp); 
}
 void deleteLast(ListRef L){
	//assert(!isEmpty(L));
	NodeRef tmp = L->last;
	L->last = L-> last ->prev;
	L->last->next = NULL;
	if(L->current == tmp)
		L->current = L->last; 
	free(tmp); 
}
 void deleteCurrent(ListRef L){
	if(L->current == L->first) deleteFirst(L);
	else if(L->current == L-> last) deleteLast(L);
	else{						//using a, b, and c makes it conceptually easier
		NodeRef a = L->current->prev;
		NodeRef b = L->current;
		NodeRef c = L->current->next;
		if(a!=NULL)
			a->next = b->next;	
		c->prev = b->prev;
		L->current=c;		
		free(b);
	}
	
}
 /*** Other operations ***/
 void printList(ListRef L){
	//assert(!isEmpty(L));
	NodeRef node = L->first;
	while(node != NULL){
		printf("(%lu, %u)  ", node->book, node->count);
		node = node->next;
	}
	printf("\n");
}

bool isCurrentNull(ListRef L){return L->current==NULL;}


void insertionSort(ListRef L, long data){
	NodeRef iter = L->first;
	while(iter!=NULL){
		if(iter->book == data){
			++iter->count;
			return;	
		}
		if(data<iter->count){
			insertBeforeCurrent(L, data);
			return;
		}
		iter=iter->next;
	}
	insertAfterLast(L, data);
}

/*void sort(ListRef* L){
	NodeRef iter = L->first;
	ListRef new = newList();
	while(iter!=NULL){
		insertionSort(new, iter->book);
		iter=iter->next;
	}
	*L = new;
	
}*/

