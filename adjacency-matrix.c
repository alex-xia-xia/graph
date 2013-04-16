/*
 * =====================================================================================
 *
 *       Filename:  adjacency-matrix.c
 *
 *    Description:  Graph implementation using an Adjacency Matrix
 *
 *        Version:  1.0
 *        Created:  15/04/2013 14:27:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int node_count;
  int arc_count;
  int** arcs; // 0 represents the lack of adjacency
} Graph;

void empty_graph(Graph* g) {
  g->node_count = 0;
  g->arc_count = 0;
  g->arcs = NULL;
}

void init_graph(Graph* g, int n) {
  int i, j;
  
  g->node_count = n;

  g->arcs = (int**) malloc(n * sizeof(int*));
  for (i = 0 ; i < g->node_count ; i++)
    g->arcs[i] = (int*) malloc(n * sizeof(int));

  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++)
      g->arcs[i][j] = 0;
}

int insert_arc(Graph* g, int a1, int a2, int weight) {
  if (a1 >= 0 && a1 < g->node_count && a2 >= 0 && a2 < g->node_count && g->arcs[a1][a2] == 0) {
    g->arcs[a1][a2] = weight;
    g->arc_count++;
    return 0;
  }
  return -1;
}

int remove_arc(Graph* g, int a1, int a2) {
  int weight = -1;
  if (a1 >= 0 && a1 < g->node_count && a2 >= 0 && a2 < g->node_count && g->arcs[a1][a2] > 0) {
    weight = g->arcs[a1][a2];
    g->arcs[a1][a2] = 0;
    g->arc_count--;
  }
  return weight;
}

Graph* insert_node(Graph* g, int n) {
  return g;
}

Graph* remove_node(Graph* g, int n) {
  return g;
}

void print_graph(Graph* g) {
  int i, j;

  for (i = 0 ; i < g->node_count ; i++) {
    for (j = 0 ; j < g->node_count ; j++) {
      printf("[%2d]", g->arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  Graph* g = (Graph*) malloc(sizeof(Graph));

  empty_graph(g);
  init_graph(g, 6);

  insert_arc(g, 0, 1, 5);
  print_graph(g);
  insert_arc(g, 2, 3, 10);
  print_graph(g);

  remove_arc(g, 0, 1);
  print_graph(g);

  return 0;
}