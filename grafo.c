#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "lista.h"
#include "lista.c"
#include <graphviz/cgraph.h>

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um grafo
//
// o grafo pode ser direcionado ou não
//
// o grafo tem um nome, que é uma "string"

struct grafo {
  char *nome;
  int direcionado;
  int numero_vertices;
  struct lista* listaAdjacencia; //o grafo é representado por um vetor de listas
};

//------------------------------------------------------------------------------
// desaloca toda a memória usada em *g
//
// devolve 1 em caso de sucesso,
//         ou
//         0, caso contrário

int destroi_grafo(grafo g) {

  return 0;
}
//------------------------------------------------------------------------------
// lê um grafo no formato dot de input
//
// devolve o grafo lido,
//         ou
//         NULL, em caso de erro

grafo le_grafo(FILE *input) {
  Agraph_t *g;
  grafo graph;

  graph = malloc(sizeof(struct grafo));
  g = agread(input, NULL);
  graph->nome = (char*) malloc (sizeof(char)*strlen(agnameof(g))+1);
  strcpy(graph->nome, agnameof(g));
	strcat(graph->nome, "\0");
  graph->direcionado = agisdirected(g);
  graph->numero_vertices = agnnodes(g);

  //deve criar uma lista  para cada vértice no vetor de listas
  Agnode_t *n;
  Agedge_t *e;
  // Create an array of adjacency lists. Size of array will be numero_vertices
  graph->listaAdjacencia = (struct lista*) malloc(graph->numero_vertices * sizeof(struct lista));
  // Initialize each adjacency list as empty by making head as NULL
  int i;
  for (i = 0; i < graph->numero_vertices; ++i)
      graph->listaAdjacencia[i].primeiro = NULL;

  for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
    for (e = agfstout(g,n); e; e = agnxtout(g,e)) {
      //loop para percorrer cada aresta do grafo, tem que montar as listas com isso
    }
  }
  return 0;
}
//------------------------------------------------------------------------------
// escreve o grafo g em output usando o formato dot.
//
// devolve o grafo escrito,
//         ou
//         NULL, em caso de erro

grafo escreve_grafo(FILE *output, grafo g) {

  return g;
}
//------------------------------------------------------------------------------
// devolve o grafo de recomendações de g
//
// cada aresta {c,p} de H representa uma recomendação do produto p
// para o consumidor c, e tem um atributo "weight" que é um inteiro
// representando a intensidade da recomendação do produto p para o
// consumidor c.
//
// cada vértice de g tem um atributo "tipo" cujo valor é 'c' ou 'p',
// conforme o vértice seja consumidor ou produto, respectivamente

grafo recomendacoes(grafo g){

  return g;
}

//------------------------------------------------------------------------------
