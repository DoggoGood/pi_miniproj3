#ifndef INCIDENCE_MATRIX_H
#define INCIDENCE_MATRIX_H

void print_incidence_matrix(int n, int m, int inc_matrix[n][m]);
void create_random_incidence_matrix(int n, int m, int inc_matrix[n][m],
                                    int adj_matrix[n][n]);
void print_graph_edges_incidence_matrix(int n, int m, int inc_matrix[n][m]);
void incidence(int n, int m);

#endif
