#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include "grafo.h"

int main(int argc, char const *argv[]){
	FILE *input;
	grafo compras, recom;
	input = fopen("compras.dot", "r");
	compras = le_grafo(input, "compras");
	escreve_grafo(stdout, compras);
	recom = recomendacoes(compras);
	escreve_grafo("recomendacoes.dot", recom);
	return 0;
}
