#include "incidence_matrix.h"
#include "adjacency_matrix.h"
#include <stdio.h>
#include <stdlib.h>

void print_incidence_matrix(int n, int m, int inc_matrix[n][m]) {
    printf("Macierz incydencji:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (inc_matrix[i][j] == 0)
                printf(" 0 ");
            else if (inc_matrix[i][j] > 0) {
                printf("+%d ", inc_matrix[i][j]);

            } else {
                printf("%d ", inc_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void create_random_incidence_matrix(int n, int m, int inc_matrix[n][m],
                                    int adj_matrix[n][n]) {
    int edge_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] > 0) {
                for (int k = 0; k < adj_matrix[i][j]; k++) {
                    inc_matrix[i][edge_count] = 1;  // start
                    inc_matrix[j][edge_count] = -1; // koniec
                    edge_count++;
                }
            }
        }
    }
}

void print_graph_edges_incidence_matrix(int n, int m, int inc_matrix[n][m]) {
    printf("Krawędzie grafu:\n");
    int (*from_to)[m] = calloc(n, sizeof *from_to);
    for (int edge = 0; edge < m; edge++) {
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (inc_matrix[i][edge] == 1) {
                start = i;
            } else if (inc_matrix[i][edge] == -1) {
                end = i;
            }
        }
        if (start != -1 && end != -1) {
            from_to[start][end]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (from_to[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            } else if (from_to[i][j] > 1) {
                printf("%d -> %d, multikrawędź * %d\n", i, j, from_to[i][j]);
            }
        }
    }
    free(from_to);
}

void incidence(int n, int m) {
    int (*inc_matrix)[m] = calloc(n, sizeof *inc_matrix);
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    create_random_adj_matrix(n, m, adj_matrix);
    create_random_incidence_matrix(n, m, inc_matrix, adj_matrix);
    print_incidence_matrix(n, m, inc_matrix);
    print_graph_edges_incidence_matrix(n, m, inc_matrix);
    int *in_deg = calloc(n, sizeof *in_deg);
    int *out_deg = calloc(n, sizeof *out_deg);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (inc_matrix[i][j] == 1) {
                out_deg[i]++;
            } else if (inc_matrix[i][j] == -1) {
                in_deg[i]++;
            }
        }
    }
    printf("Stopnie wierzchołków:\n");
    for (int i = 0; i < n; i++) {
        printf("Wierzchołek %d: stopień = %d, stopień wejściowy = %d, stopień "
               "wyjściowy = %d\n",
               i, in_deg[i] + out_deg[i], in_deg[i], out_deg[i]);
    }
    free(inc_matrix);
    free(adj_matrix);
    free(in_deg);
    free(out_deg);
}
