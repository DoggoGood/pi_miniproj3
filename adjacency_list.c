#include "adjacency_list.h"
#include "adjacency_matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Inicjalizuje wektor z początkową pojemnością 4.
 * vec - wskaźnik do wektora do inicjalizacji
 */
void vector_init(struct vector *vec) {
    vec->size = 0;
    vec->capacity = 4;
    vec->neighbors = malloc(vec->capacity * sizeof(int));
}

/**
 * Dodaje element na koniec wektora, zwiększając pojemność jeśli potrzeba.
 * vec - wskaźnik do wektora
 * value - wartość do dodania
 */
void vector_push_back(struct vector *vec, int value) {
    // zwiększanie pojemności, jeśli potrzeba
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->neighbors = realloc(vec->neighbors, vec->capacity * sizeof(int));
    }
    vec->neighbors[vec->size++] = value;
}

/**
 * Zwalnia pamięć zaalokowaną dla wektora.
 * vec - wskaźnik do wektora
 */
void vector_free(struct vector *vec) { free(vec->neighbors); }

/**
 * Tworzy listę sąsiedztwa na podstawie macierzy sąsiedztwa.
 * n - liczba wierzchołków
 * adj_matrix - macierz sąsiedztwa [n][n]
 * adj_list - tablica list sąsiedztwa do wypełnienia
 */
void create_adjacency_list(int n, int adj_matrix[n][n],
                           struct vector adj_list[n]) {
    for (int i = 0; i < n; i++) {
        vector_init(&adj_list[i]);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < adj_matrix[i][j]; k++) {
                vector_push_back(&adj_list[i], j);
            }
        }
    }
}

/**
 * Wypisuje listę sąsiedztwa w formacie: wierzchołek: sąsiedzi.
 * n - liczba wierzchołków
 * adj_list - tablica list sąsiedztwa
 */
void print_adjacency_list(int n, struct vector adj_list[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < adj_list[i].size; j++) {
            printf("%d ", adj_list[i].neighbors[j]);
        }
        printf("\n");
    }
}

/**
 * Wypisuje krawędzie grafu w formacie: u -> v lub u -> v, multikrawędź * x.
 * n - liczba wierzchołków
 * adj_list - tablica list sąsiedztwa
 */
void print_graph_edges_from_adj_list(int n, struct vector adj_list[n]) {
    printf("Krawędzie grafu:\n");
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < adj_list[i].size) {
            int target = adj_list[i].neighbors[j];
            int count = 1;
            j++;
            // zliczanie multikrawędzi
            while (j < adj_list[i].size && adj_list[i].neighbors[j] == target) {
                count++;
                j++;
            }
            if (count == 1) {
                printf("%d -> %d\n", i, target);
            } else {
                printf("%d -> %d, multikrawędź * %d\n", i, target, count);
            }
        }
    }
}

/**
 * Główna funkcja do reprezentacji grafu za pomocą listy sąsiedztwa.
 * Generuje losowy graf, wypisuje listę sąsiedztwa, krawędzie i stopnie
 * wierzchołków. n - liczba wierzchołków m - liczba krawędzi
 */
void adjacency_list(int n, int m) {
    printf("Lista sąsiedztwa:\n");
    struct vector *adj_list = calloc(n, sizeof(struct vector));
    int (*adj_matrix)[n] = calloc(n, sizeof *adj_matrix);
    create_random_adj_matrix(n, m, adj_matrix);
    create_adjacency_list(n, adj_matrix, adj_list);
    print_adjacency_list(n, adj_list);
    print_graph_edges_from_adj_list(n, adj_list);
    // liczenie stopni wierzchołków
    int *in_deg = calloc(n, sizeof(int));
    int *out_deg = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        out_deg[i] = adj_list[i].size;
        for (int j = 0; j < adj_list[i].size; j++) {
            int neighbor = adj_list[i].neighbors[j];
            in_deg[neighbor]++;
        }
    }
    printf("Stopnie wierzchołków:\n");
    for (int i = 0; i < n; i++) {
        printf("Wierzchołek %d: stopień = %d, stopień wejściowy = %d, stopień "
               "wyjściowy = %d\n",
               i, in_deg[i] + out_deg[i], in_deg[i], out_deg[i]);
    }
    for (int i = 0; i < n; i++) {
        vector_free(&adj_list[i]);
    }
    free(adj_matrix);
    free(in_deg);
    free(out_deg);
    free(adj_list);
}
