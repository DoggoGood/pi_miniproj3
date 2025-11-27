#include "adjacency_matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Tworzy losową macierz sąsiedztwa dla grafu skierowanego.
 * Zapewnia spójność grafu przez pierwsze n-1 krawędzi.
 * n - liczba wierzchołków
 * m - liczba krawędzi do wygenerowania
 * adj_matrix - macierz sąsiedztwa [n][n] do wypełnienia
 */
void create_random_adj_matrix(int n, int m, int adj_matrix[n][n]) {
    // Generacja losowych krawędzi
    int edges_added = 0;
    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        // gdy edges_added < n-1 to zapewniamy spójność grafu
        if (edges_added < n - 1) {
            while (u == v || adj_matrix[u][v] == 1) {
                u = rand() % n;
                v = rand() % n;
            }
            adj_matrix[u][v] = 1;
            edges_added++;
        }
        // mamy pewność, że spójność jest zapewniona
        else {
            while (u == v) {
                u = rand() % n;
                v = rand() % n;
            }
            adj_matrix[u][v]++;
            edges_added++;
        }
    }
}

/**
 * Wypisuje macierz sąsiedztwa w formacie tabelarycznym.
 * n - liczba wierzchołków
 * adj_matrix - macierz sąsiedztwa [n][n]
 */
void print_adj_matrix(int n, int adj_matrix[n][n]) {
    printf("Macierz sąsiedztwa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Wypisuje krawędzie grafu w formacie: u -> v lub u -> v, multikrawędź * x.
 * n - liczba wierzchołków
 * adj_matrix - macierz sąsiedztwa [n][n]
 */
void print_graph_edges_adj_matrix(int n, int adj_matrix[n][n]) {
    printf("Krawędzie grafu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            } else if (adj_matrix[i][j] > 1) {
                printf("%d -> %d, multikrawędź * %d\n", i, j, adj_matrix[i][j]);
            }
        }
    }
}

/**
 * Główna funkcja do reprezentacji grafu za pomocą macierzy sąsiedztwa.
 * Generuje losowy graf, wypisuje krawędzie, macierz i stopnie wierzchołków.
 * n - liczba wierzchołków
 * m - liczba krawędzi
 */
void adjacency_matrix(int n, int m) {
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    create_random_adj_matrix(n, m, adj_matrix);
    print_graph_edges_adj_matrix(n, adj_matrix);

    print_adj_matrix(n, adj_matrix);
    // licezenie stopni wierzchołków
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
    free(adj_matrix);
    free(in_deg);
    free(out_deg);
}
