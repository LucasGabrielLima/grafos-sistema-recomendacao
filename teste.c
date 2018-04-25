#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include "grafo.h"

int main(int argc, char const *argv[]){
	FILE *input;
	grafo graph;
	input = fopen("compras.dot", "r");
	graph = le_grafo(input, "compras");

	escreve_grafo(stdout, graph);
	return 0;
}