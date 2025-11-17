#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TODO add error handling for malloc and scanf

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

// TODO: add multiline edges handling

void adjacency_matrix(int n, int m) {
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    // TODO vertices can be unconnected, add better randomization
    for (int i = 0; i < m; i++) {
        adj_matrix[rand() % n][rand() % n] = 1;
    }
    print_graph_edges_adj_matrix(n, adj_matrix);
    print_adj_matrix(n, adj_matrix);
    int *in_deg = calloc(n, sizeof *in_deg);
    int *out_deg = calloc(n, sizeof *out_deg);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in_deg[i] += adj_matrix[j][i];
            out_deg[i] += adj_matrix[i][j];
        }
    }
    printf("Stopnie wierzchołków:\n");
    for (int i = 0; i < n; i++) {
        printf("Wierzchołek %d: stopień = %d, stopień wejściowy = %d, stopień "
               "wyjściowy = %d\n",
               i, in_deg[i] + out_deg[i], in_deg[i], out_deg[i]);
    }
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
