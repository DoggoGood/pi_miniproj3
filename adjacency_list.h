#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

struct vector {
    int *neighbors;
    int size;
    int capacity;
};

void vector_init(struct vector *vec);
void vector_push_back(struct vector *vec, int value);
void vector_free(struct vector *vec);
void create_adjacency_list(int n, int adj_matrix[n][n],
                           struct vector adj_list[n]);
void print_adjacency_list(int n, struct vector adj_list[n]);
void print_graph_edges_from_adj_list(int n, struct vector adj_list[n]);
void adjacency_list(int n, int m);

#endif
