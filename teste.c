#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include "grafo.h"

int main(int argc, char const *argv[]){
	FILE *input, *output;
	grafo compras, recomend;
	input = fopen("compras.dot", "r");
	output = fopen("recomendacoes.dot", "w");
	compras = le_grafo(input);
	escreve_grafo(stdout, compras);
	recomend = recomendacoes(compras);
	escreve_grafo(output, recomend);
	return 0;
}
