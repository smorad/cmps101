#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "list.h"
typedef struct graph{
	ListRef* vertices;
	int* color;
	int* parent;
	int* distance;
	int numVertices;
	int numEdges;

} *GraphRef;

GraphRef newGraph(int n){
	GraphRef g = malloc(sizeof(struct graph));
	g->numVertices = g->numEdges = 0;
	g->vertices = calloc(n, sizeof(ListRef));
	g->distance = calloc(n, sizeof(int));
	g->parent = calloc(n, sizeof(ListRef));
	g->color = calloc(n, sizeof(int));
	for(int i=0; i<n; i++){
		g->vertices[i] = newList();
		g->color[i] = 0;
		++g->numVertices;
		g->distance[i] = INT_MAX;
		g->parent[i] = -1;
	}
	return g;
}

void addEdge(GraphRef g, int from, int to){
	insertAfterLast(g->vertices[from],  to);
	++g->numEdges;
}

void makeWhite(GraphRef g){
	for(int i=0; i<g->numVertices; i++){
		g->color[i] = 0;
	}
}

void resetDist(GraphRef g){	
	for(int i=0; i<g->numVertices; i++){
		g->distance[i] = INT_MAX;
	}
}

void resetParent(GraphRef g){
	for(int i=0; i<g->numVertices; i++){
		g->parent[i]=-1;
	}
}

void initGraph(GraphRef g){
makeWhite(g);
resetDist(g);
resetParent(g);
}

void doBFS(GraphRef g, int source){
	ListRef list = newList();
	initGraph(g);
	insertAfterLast(list, source);
	g->color[source]= 1;
	g->distance[source]=0;
	while(!isEmpty(list)){
		int current = getFirst(list);
		if(current > g->numVertices){
			deleteFirst(list);
			 break;
		}
		ListRef edgeList = g->vertices[current];
		moveFirst(edgeList);
		while(!offEnd(edgeList)){
			int edge = getCurrent(edgeList);
			if(g->color[edge]==0){
				g->distance[edge] = g->distance[current]+1;
				g->color[edge] = 1;
				g->parent[edge] = current;
				insertAfterLast(list, edge);
			}
			moveNext(edgeList);
		}
		deleteFirst(list);
		g->color[current] = 2;
	}
	makeEmpty(list);
	freeList(list);
}
	

int getDistance(GraphRef g, int dest){
	return g->distance[dest];
}

ListRef getPathTo(GraphRef g, int dest){
	int path = dest;
	ListRef list = newList();
	printf("Path to %d: ", dest);
	while(path!=-1){
		insertBeforeFirst(list,path);
		path = g->parent[path];
	}
	return list;
}


void freeGraph(GraphRef g){
	for(int i=0; i<g->numVertices; i++){
		makeEmpty(g->vertices[i]);
		freeList(g->vertices[i]);
	}
	free(g->vertices);
	free(g->color);
	free(g->distance);
	free(g->parent);
	free(g);
}

void printGraph(GraphRef g){
	for(int i=0; i<g->numVertices; i++){
		printf("Node %d:\n",  i);
		if(i!=0){
			printf("Parent ");
			printList(g->parent[i]);
		}
		printf("\tColor %d, Dist %d", g->color[i], g->distance[i]); 
		printf("\tEdges:");
		ListRef index = g->vertices[i];
		moveFirst(index);
		while(!offEnd(index)){
			printf("%d, ",getCurrent(index));	
		moveNext(index);
		}
		 
	}
} 
