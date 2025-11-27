#include <stdio.h>
#include <stdlib.h>
#include "incidence_matrix.h"

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

void incidence(int n, int m) {
    int (*inc_matrix)[m] = calloc(n, sizeof *inc_matrix);
    print_incidence_matrix(n, m, inc_matrix);
}
