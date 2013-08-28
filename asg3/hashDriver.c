//smorad@ucsc.edu
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include "bookCountList.h"
#include <time.h>
int main(){
	srand(time(NULL));
	int A, B, C,D,E,F,G,J,K,L,M,N,O,P;
	A=rand();
	B=rand();
	C=rand();
	D=rand();
	E=rand();
	F=rand();
	G=rand();
	J=rand();
	K=rand();
	L=rand();
	M=rand();
	N=rand();
	O=rand();
	P=rand();
	printf("A is: %d\n", A);
	printf("B is: %d\n", B);
	printf("C is: %d\n", C);
	printf("D is: %d\n", D);
	printf("E is: %d\n", E);
	printf("F is: %d\n", F);
	printf("G is: %d\n", G);
	printf("J is: %d\n", J);
	printf("K is: %d\n", K);
	printf("L is: %d\n", L);
	printf("M is: %d\n", M);
	printf("N is: %d\n", N);
	printf("O is: %d\n", O);
	printf("P is: %d\n", P);
	BookRef a = newBook(A);
	BookRef b = newBook(B);
	BookRef c = newBook(C);
	BookRef d = newBook(D);
	BookRef e = newBook(E);
	BookRef f = newBook(F);
	BookRef g = newBook(G);
	BookRef j = newBook(J);
	BookRef k = newBook(K);
	BookRef l = newBook(L);
	BookRef m = newBook(M);
	BookRef n = newBook(N);
	BookRef o = newBook(O);
	BookRef p = newBook(P);
	insertionSort(getBookList(a), 1);
	insertionSort(getBookList(b), 2);
	insertionSort(getBookList(c), 3);
	insertionSort(getBookList(d), 4);
	insertionSort(getBookList(e), 5);
	insertionSort(getBookList(f), 6);
	insertionSort(getBookList(g), 7);
	insertionSort(getBookList(j), 8);
	insertionSort(getBookList(k), 9);
	insertionSort(getBookList(l), 10);
	insertionSort(getBookList(m), 11);
	insertionSort(getBookList(n), 12);
	insertionSort(getBookList(o), 13);
	insertionSort(getBookList(p), 14);
	HashRef h = createHashSet();

	insert(h,A,a);
	insert(h,B,b);
	insert(h,C,c);
	insert(h,D,d);
	insert(h,E,e);
	insert(h,F,f);
	insert(h,G,g);
	insert(h,J,j);
	insert(h,K,k);
	insert(h,L,l);
	insert(h,M,m);
	insert(h,N,n);
	insert(h,O,o);
	insert(h,P,p);

	debugHash(h);		
	printf("get A: %lu\n", getId(getElement(h,A)));
	printf("get B: %lu\n", getId(getElement(h,B)));
	printf("get C: %lu\n", getId(getElement(h,C)));
	printf("get D: %lu\n", getId(getElement(h,D)));
	printf("get E: %lu\n", getId(getElement(h,E)));
	printf("get F: %lu\n", getId(getElement(h,F)));
	printf("get G: %lu\n", getId(getElement(h,G)));
	printf("get J: %lu\n", getId(getElement(h,J)));
	printf("get K: %lu\n", getId(getElement(h,K)));
	printf("get L: %lu\n", getId(getElement(h,L)));
	printf("get M: %lu\n", getId(getElement(h,M)));
	printf("get N: %lu\n", getId(getElement(h,N)));
	printf("get O: %lu\n", getId(getElement(h,O)));
	printf("get P: %lu\n", getId(getElement(h,P)));
	destroy(h);
}

