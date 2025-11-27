#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "adjacency_matrix.h"
#include "incidence_matrix.h"
#include "adjacency_list.h"

// TODO: add error handling for malloc and scanf
// TODO: add adj Lista
// TODO: add incidence matrix
// FIX: add free() everywhere where malloc/calloc is used

int main() {
    srand(time(NULL));
    int n, m;
    char *method;
    scanf("%d %d %ms", &n, &m, &method);
    // Sprawdzanie czy graf jest spójny na wejściu
    if (m < n - 1) {
        fprintf(stderr, "Za mało krawędzi, aby graf był spójny\n");
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
        return 1;
    }
    return 0;
}
