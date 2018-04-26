#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "linkedlist.h"
#include <graphviz/cgraph.h>

//------------------------------------------------------------------------------
// (apontador para) estrutura de dados para representar um grafo
//
// o grafo pode ser direcionado ou não
//
// o grafo tem um nome, que é uma "string"

struct grafo {
  Agraph_t *g;
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

grafo le_grafo(FILE *input, char *name) {
  grafo graph;

  graph = malloc(sizeof (struct grafo));
  graph->g = agread(input, NULL);

  return graph;
}
//------------------------------------------------------------------------------
// escreve o grafo g em output usando o formato dot.
//
// devolve o grafo escrito,
//         ou
//         NULL, em caso de erro

grafo escreve_grafo(FILE *output, grafo graph) {
  graph = agwrite(graph->g, output);
  return graph;
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

grafo recomendacoes(grafo compras){
  grafo recomend;
  Agnode_t *n;
  char *type;

  for(n = agfstnode(compras->g); n; n = agnxtnode(compras->g, n)){
    type = agget(n, "tipo");
    if(!strcmp(type, "c")){
      printf("Tipo de %s é consumidor\n", agnameof(n));
    }
    else{
      printf("Tipo de %s é produto\n", agnameof(n));
    }
  }

  return recomend;
}

//------------------------------------------------------------------------------
