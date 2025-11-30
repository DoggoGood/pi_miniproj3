#include "adjacency_list.h"
#include "adjacency_matrix.h"
#include "incidence_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n, m;
    char *method;
    printf("Podaj liczbę wierzchołków, liczbę krawędzi i metodę reprezentacji "
           "grafu (ms - macierz sąsiedztwa, mi - macierz incydencji, ls - "
           "lista sąsiedztwa), np. 4 3 ms:\n");
    scanf("%d %d %ms", &n, &m, &method);
    // Sprawdzanie czy graf jest spójny na wejściu
    if (m < n - 1) {
        fprintf(stderr, "Za mało krawędzi, aby graf był spójny\n");
        free(method);
        return 1;
    }
    if (strcmp(method, "ms") == 0)
        adjacency_matrix(n, m);
    else if (strcmp(method, "mi") == 0)
        incidence(n, m);
    else if (strcmp(method, "ls") == 0)
        adjacency_list(n, m);
    else {
        printf("Zła metoda\n");
        free(method);
        return 1;
    }
    free(method);
    return 0;
}
