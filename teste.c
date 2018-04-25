#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include "grafo.h"

int main(int argc, char const *argv[]){
	FILE *input;
	grafo graph;
	input = fopen("recomendacoes.dot", "r");
	graph = le_grafo(input, "compras");

	agwrite(graph->g, stdout);
	return 0;
}