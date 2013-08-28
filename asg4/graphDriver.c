#include<stdlib.h>
#include<stdio.h>

#include "graph.h"
#include "list.h"

int main(){
	GraphRef g = newGraph(5);
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 2, 3);
	addEdge(g, 3, 4);
	addEdge(g, 4, 0);
	addEdge(g, 4, 1);

	doBFS(g, 0);
	printf("Distance to 4 is: %d", getDistance(g, 4));
	
	ListRef l = getPathTo(g,4);
	printList(l);
	freeGraph(g);

	
}
