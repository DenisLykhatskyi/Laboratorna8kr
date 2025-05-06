#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define M 3
#define N 4

int main() {
    int A[M][N];
    int X[M][N];
    int i, j;
    int max_element;

    srand(time(NULL));

    printf("Матриця A (%dx%d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 100 + 1;
            printf("%5d ", A[i][j]);
        }
        printf("\n");
    }

    max_element = A[0][0];
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] > max_element) {
                max_element = A[i][j];
            }
        }
    }

    printf("\nМаксимальний елемент матриці A: %d\n", max_element);

    if (max_element == 0) {
        printf("\nПомилка: Максимальний елемент дорівнює 0. Ділення на нуль неможливе.\n");
        printf("Матриця X буде заповнена нулями.\n");
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                X[i][j] = 0;
            }
        }
        // Друк X, якщо вона заповнена нулями через max_element = 0
        printf("\nМатриця X (%dx%d):\n", M, N);
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                printf("%5d ", X[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("\nМатриця X (%dx%d):\n", M, N);
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                X[i][j] = (int)floor((double)A[i][j] / max_element);
                printf("%5d ", X[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}