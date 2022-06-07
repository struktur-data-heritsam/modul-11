//
// Created by Ariq Heritsa on 07/06/22.
//

#include "graph.h"

// 1305213031 - Ariq Heritsa Maalik
void create_graph(graph &G) {
  G = nil;
}

// 1305213031 - Ariq Heritsa Maalik
address_node create_node(infotype_node new_info) {
  address_node p = new node;

  info(p) = new_info;
  next_node(p) = nil;
  first_neighbor(p) = nil;

  return p;
}

// 1305213031 - Ariq Heritsa Maalik
address_neighbor create_neighbor(infotype_node new_info) {
  address_neighbor p = new neighbor;

  info(p) = new_info;
  next_neighbor(p) = nil;

  return p;
}

// 1305213031 - Ariq Heritsa Maalik
void insert_last_neighbor(address_neighbor neighbor, address_node node) {
  address_neighbor q;

  if (first_neighbor(node) == nil) {
    first_neighbor(node) = neighbor;
  } else {
    q = first_neighbor(node);

    while (next_neighbor(q) != nil) {
      q = next_neighbor(q);
    }

    next_neighbor(q) = neighbor;
  }
}

// 1305213031 - Ariq Heritsa Maalik
void delete_first_neighbor(address_node node, address_neighbor &neighbor) {
  neighbor = first_neighbor(node);
  first_neighbor(node) = next_neighbor(neighbor);
  next_neighbor(neighbor) = nil;
}

// 1305213031 - Ariq Heritsa Maalik
void delete_after_neighbor(address_neighbor prec, address_neighbor &p) {
  p = next_neighbor(prec);

  next_neighbor(prec) = next_neighbor(p);
  next_neighbor(p) = nil;
}

// 1305213031 - Ariq Heritsa Maalik
void insert_first_node(infotype_node new_info, graph &G) {
  address_node node = create_node(new_info);

  if (G == nil) {
    G = node;
  } else {
    next_node(node) = G;
    G = node;
  }
}

// 1305213031 - Ariq Heritsa Maalik
address_node search_node(infotype_node keyword, graph G) {
  address_node current = G;

  while (current != nil && info(current) != keyword) {
    current = next_node(current);
  }

  return current;
}

// 1305213031 - Ariq Heritsa Maalik
void connect(infotype_node node1, infotype_node node2, graph G) {
  address_node n1 = search_node(node1, G);
  address_node n2 = search_node(node2, G);

  if (n1 != nil && n2 != nil) {
    insert_last_neighbor(create_neighbor(node2), n1);
    insert_last_neighbor(create_neighbor(node1), n2);
  }
}

// 1305213031 - Ariq Heritsa Maalik
address_neighbor search_neighbor(infotype_node keyword, address_node node) {
  address_neighbor current = first_neighbor(node);

  while (current != nil && info(current) != keyword) {
    current = next_neighbor(current);
  }

  return current;
}

// 1305213031 - Ariq Heritsa Maalik
void disconnect(infotype_node node1, infotype_node node2, graph G) {
  address_neighbor temp1, temp2, prec1, prec2;

  address_node n1 = search_node(node1, G);
  address_node n2 = search_node(node2, G);

  // n1 or n2 is not exist
  if (n1 == nil || n2 == nil) {
    return;
  }

  address_neighbor neighbor2 = search_neighbor(info(n2), n1);
  address_neighbor neighbor1 = search_neighbor(info(n1), n2);

  // n1 or n2 is not connected
  if (neighbor1 == nil || neighbor2 == nil) {
    return;
  }

  // disconnect node2 from node1
  if (neighbor2 == first_neighbor(n1)) {
    delete_first_neighbor(n1, temp2);
  } else {
    prec2 = first_neighbor(n1);

    while (next_neighbor(prec2) != nil && next_neighbor(prec2) != neighbor2) {
      prec2 = next_neighbor(prec2);
    }

    delete_after_neighbor(prec2, temp2);
  }

  // disconnect node1 from node2
  if (neighbor1 == first_neighbor(n2)) {
    delete_first_neighbor(n2, temp1);
  } else {
    prec1 = first_neighbor(n2);

    while (next_neighbor(prec1) != nil && next_neighbor(prec1) != neighbor1) {
      prec1 = next_neighbor(prec1);
    }

    delete_after_neighbor(prec1, temp1);
  }
}

// 1305213031 - Ariq Heritsa Maalik
void print_graph(graph G) {
  if (G == nil) {
    cout << "Graph kosong" << endl;
  } else {
    address_node current = G;

    while (current != nil) {
      cout << "Node " << info(current) << " -> ";

      address_neighbor current_neighbor = first_neighbor(current);

      while (current_neighbor != nil) {
        cout << info(current_neighbor) << " -> ";
        current_neighbor = next_neighbor(current_neighbor);
      }

      cout << "NULL" << endl;

      current = next_node(current);
    }
  }

  cout << endl;
}
