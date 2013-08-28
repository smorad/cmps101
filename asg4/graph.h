#ifndef __GRAPH__H
#define __GRAPH__H
#include "list.h"
typedef struct graph *GraphRef;
/*pre: n!=0 post: new graph with n nodes*/
GraphRef newGraph(int n);

/*pre: from and to are nodes in g post: edge (from, to)*/
void addEdge(GraphRef g, int from, int to);

/*pre: g!=NULL post: dist and path updated*/
void doBFS(GraphRef g, int source);

/*pre: doBFS called*/
int getDistance(GraphRef g, int destination);

/*pre: doBFS called*/
ListRef getPathTo(GraphRef g, int destination);

/*pre: g!=NULL*/
void freeGraph(GraphRef g);

/*for debugging*/
void printGraph(GraphRef g);
#endif
