#include <stdio.h>
#include <graphviz/cgraph.h>

int main() {

  Agraph_t *g;
  Agnode_t *n;
  //g = agopen("G", Agstrictundirected, NULL);
  g = agread(stdin, NULL);

  for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
    printf("%s",agnameof(n));
  }

  /*
  n = agnode(g,"node28",TRUE);

  Agnode_t *m;
  m = agnode(g,"node29",TRUE);

  Agedge_t *e;
  e = agedge(g,n,m,"e28",TRUE);*/

  //agwrite(g,stdout);

}
