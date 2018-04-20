#include <stdio.h>
#include <graphviz/cgraph.h>

int main() {

  Agraph_t *g;
  g = agopen("G", Agstrictundirected, NULL);

  Agnode_t *n;
  n = agnode(g,"node28",TRUE);

  Agnode_t *m;
  m = agnode(g,"node29",TRUE);

  Agedge_t *e;
  e = agedge(g,n,m,"e28",TRUE);

  agwrite(g,stdout);

}
