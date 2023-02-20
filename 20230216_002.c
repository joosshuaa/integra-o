#include <stdio.h>
#include <stdlib.h>

void interseccao(int A[], int B[], int C[]) {
    int tamanhoC = 0;

    for (int i = 1; i <= A[0]; i++) {
        for (int j = 1; j <= B[0]; j++) {
            if (A[i] == B[j]) {
                C[++tamanhoC] = A[i];
            }
        }
    }

    C[0] = tamanhoC;
}

int main() {
    int A[] = {4, 1, 2, 4, 9};
    int B[] = {5, 2, 4, 7, 8, 9};
    int C[100];

    interseccao(A, B, C);

    printf("Interseccao: ");
    for (int i = 1; i <= C[0]; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
