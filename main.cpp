#include <iostream>
#include "graph.h"

using namespace std;

int main() {
  graph G;

  create_graph(G);

  print_graph(G); // Graph kosong

  insert_first_node(17, G);
  insert_first_node(18, G);
  insert_first_node(19, G);
  insert_first_node(20, G);

  print_graph(G); // Node 20: null; Node 19: null; Node 18: null; Node 17: null
  connect(17, 18, G);
  print_graph(G); // Node 20: null; Node 19: null; Node 18: 17; Node 17: 18
  connect(17, 19, G);
  connect(18, 19, G);
  connect(18, 20, G);
  print_graph(G); // Node 20: 18; Node 19: 17, 18; Node 18: 17, 19, 20; Node 17: 18, 19

  disconnect(18, 20, G);
  print_graph(G); // Node 20: null; Node 19: 17,18; Node 18: 17, 19; Node 17: 18, 19

  disconnect(18, 19, G);
  print_graph(G); // Node 20: null; Node 19: 17; Node 18: 17; Node 17: 18, 19
  disconnect(18, 17, G);
  print_graph(G); // Node 20: null; Node 19: 17; Node 18: null; Node 17: 19
  disconnect(19, 17, G);
  print_graph(G); // Node 20: null; Node 19: null; Node 18: null; Node 17: null

  return 0;
}
