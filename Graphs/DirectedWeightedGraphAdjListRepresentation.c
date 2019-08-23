#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Structure for storing Graph
struct Graph{
	
	int vertexNum;
	int** edges;

};


// Constructs a graph with V vertices and E edges
void createGraph( struct Graph* G, int V) {
	
	int i,j;
	G->vertexNum = V;
	
	// Creating V num of Integer Pointers(Array of Integer Pointers) and assign it G->edges
	G->edges = (int**) malloc(V * sizeof(int*));
	
	for( i=0; i<V; i++) {
		
		// Create Pointer to array of int of size V and assign it G->edges[i] Pointers
		G->edges[i] = (int*) malloc(V*sizeof(int));
		
		for( j=0; j<V; j++) {
			G->edges[i][j] = INT_MAX;
		}
		
		// Intialize Weight to Edge pointing to itself
		G->edges[i][i] = 0;
	}
}

// Adds the given edge to the graph
void addEdge( struct Graph* G, int src, int dst, int weight) {
	
	G->edges[src][dst] = weight;
}

// Prints graph in Adjcacency list format
void printGraph( struct Graph* G, int V) {
	
	printf("The Directed { Weighted } Graph Adjacency List Representation: ");
	int i,j;
	for( i=0; i<V; i++) {
		
		printf("\n%d",i);		
		for(  j=0; j<V; j++) {
			
			// INT_MAX and 0 is initialized weight value are filtered out	
			if(G->edges[i][j]  != INT_MAX &&  G->edges[i][j]  != 0 ) {
				printf(" -> ");
				// Edge Weight is printed inside {}
				printf("%d {%d}", j, G->edges[i][j]);
			} 
		}
		
	}
}




int main() {
	
	int V, E, gsrc,i;
	
	int src, dst, weight;
	
	struct Graph G;
	
	printf("Enter no. of vertices\n");
	scanf("%d",&V);
	
	printf("Enter no. of Edges\n");
	scanf("%d",&E);
	
	createGraph(&G, V);
	
	for( i=0; i<E; i++ ) {
		
		printf("\n Enter Edge %d \n Enter Source: ",i+1);
		scanf("%d",&src);
		
		printf("\Enter destination: ");
		scanf("%d", &dst);
		
		printf("\nEnter Weight: ");
		scanf("%d", &weight);
		
		addEdge(&G, src, dst, weight);
	}
	

	printGraph(&G, V);
	
	return 0;
	
}
