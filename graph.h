//
// Created by Ariq Heritsa on 07/06/22.
//

#ifndef STD_1305213031_MOD11_JURNAL_ARN_GRAPH_H
#define STD_1305213031_MOD11_JURNAL_ARN_GRAPH_H

#include <iostream>

using namespace std;

#define nil NULL
#define info(p) p->info
#define next_node(p) p->next
#define next_neighbor(p) p->next_neighbor
#define first_neighbor(p) p->first_neighbor
#define first(g) g.first

typedef int infotype_node;
typedef struct node *address_node;
typedef struct neighbor *address_neighbor;

struct node {
  infotype_node info;
  address_node next;
  address_neighbor first_neighbor;
};

struct neighbor {
  infotype_node info;
  address_neighbor next_neighbor;
};

typedef address_node graph;

void create_graph(graph &G);

address_node create_node(infotype_node new_info);

address_neighbor create_neighbor(infotype_node new_info);

void insert_last_neighbor(address_neighbor neighbor, address_node node);

void delete_first_neighbor(address_node node, address_neighbor &neighbor);

void delete_after_neighbor(address_neighbor prec, address_neighbor &p);

void insert_first_node(infotype_node new_info, graph &G);

address_node search_node(infotype_node keyword, graph G);

void connect(infotype_node node1, infotype_node node2, graph G);

address_neighbor search_neighbor(infotype_node keyword, address_node node);

void disconnect(infotype_node node1, infotype_node node2, graph G);

void print_graph(graph G);

#endif //STD_1305213031_MOD11_JURNAL_ARN_GRAPH_H
