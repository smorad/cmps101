#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "graph.h"
#include "list.h"

/*Global graph is better than passing pointers to g in every function*/
GraphRef g;

/*Reads input and creates vertices then adds edges*/
void constructGraph(FILE* f, int numVerts){
	for(int i=0; i<numVerts; i++){
		int vertex;
		char edgesBuffer[1024];
		fscanf(f, "%d", &vertex);
		fgets(edgesBuffer, 1024, f);
		char* edge = strtok(edgesBuffer, " \n");
		while(edge!=NULL){
			addEdge(g, vertex, atoi(edge));
			edge = strtok(NULL, " \n");
		}
		
	}
}

/*Read in paths to display, then prints paths*/
void findPath(FILE* f,int numQueries){
	int source, dest;
	for(int i=0; i<numQueries; i++){
		fscanf(f, "%d", &source);
		fscanf(f, "%d", &dest);
		doBFS(g, source);
		int dist = getDistance(g, dest);
		if(dist==INT_MAX)
			printf("No path from %d to %d.\n", source, dest);
		else{
			printf("To get from %d to %d requires %d edges. ", source, dest, dist);
			ListRef path = getPathTo(g, dest);
			printList(path);
			makeEmpty(path);
			freeList(path);
		}
	}

}

/*Constructs graph then finds path*/
void readInput(FILE* f){
	int numVerts, numQueries;
	fscanf(f, "%d", &numVerts);
	g = newGraph(numVerts);
	fscanf(f, "%d", &numQueries);
	constructGraph(f, numVerts);
	findPath(f, numQueries);
}

/*Entry point*/
int main(int argc, char** argv){
	FILE *f = fopen(argv[1], "r");
	if(f==NULL){
		printf("File not found.\n");
		exit(EXIT_FAILURE);
	}
	readInput(f);
	fclose(f);
	freeGraph(g);
	return EXIT_SUCCESS;
}
