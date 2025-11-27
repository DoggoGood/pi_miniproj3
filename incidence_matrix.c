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

void incidence(int n, int m) {
    int (*inc_matrix)[m] = calloc(n, sizeof *inc_matrix);
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    create_random_adj_matrix(n, m, adj_matrix);
    create_random_incidence_matrix(n, m, inc_matrix, adj_matrix);
    print_adj_matrix(n, adj_matrix);
    print_graph_edges_adj_matrix(n, adj_matrix);
    print_incidence_matrix(n, m, inc_matrix);
}
