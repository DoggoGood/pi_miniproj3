#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CUSTOM_MAX 10

void print_adj_matrix(int n, int adj_matrix[n][n]) {
    printf("Macierz sąsiedztwa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_graph_edges_adj_matrix(int n, int adj_matrix[n][n]) {
    printf("Krawędzie grafu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

void adjacency_matrix(int n, int m) {
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    for (int i = 0; i < m; i++) {
        adj_matrix[rand() % n][rand() % n] = 1;
    }
    print_graph_edges_adj_matrix(n, adj_matrix);
    print_adj_matrix(n, adj_matrix);
}

void incidence(int n, int m) { printf("Macierz incydencji:\n"); }

void adjacency_list(int n, int m) { printf("Lista sąsiedztwa:\n"); }

int main() {
    srand(time(NULL));
    int n, m;
    char *method;
    scanf("%d %d %s", &n, &m, method);
    if (strcmp(method, "ms") == 0)
        adjacency_matrix(n, m);
    else if (strcmp(method, "mi") == 0)
        incidence(n, m);
    else if (strcmp(method, "ls") == 0)
        adjacency_list(n, m);
    else {
        printf("Zła metoda\n");
        return 1;
    }
    return 0;
}
