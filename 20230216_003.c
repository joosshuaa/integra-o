#include <stdio.h>
#include <stdlib.h>

void interseccao(int A[], int B[], int C[]) {
    int i = 1, j = 1, k = 1;
    while (i <= A[0] && j <= B[0]) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            C[k++] = A[i];
            i++;
            j++;
        }
    }
    C[0] = k - 1;
}

int main() {
    int n, i;
    scanf("%d", &n);

    // Lê o primeiro conjunto
    int A[102];
    scanf("%d", &A[0]);
    for (i = 1; i <= A[0]; i++) {
        scanf("%d", &A[i]);
    }

    // Lê o segundo conjunto e calcula a intersecção
    int B[102], inter[102];
    scanf("%d", &B[0]);
    for (i = 1; i <= B[0]; i++) {
        scanf("%d", &B[i]);
    }
    interseccao(A, B, inter);

    // Lê os demais conjuntos e atualiza a intersecção
    for (i = 3; i <= n; i++) {
        int C[102];
        scanf("%d", &C[0]);
        for (int j = 1; j <= C[0]; j++) {
            scanf("%d", &C[j]);
        }
        interseccao(inter, C, inter);
    }

    // Imprime o vetor intersecção
    printf("%d\n", inter[0]);
    for (i = 1; i <= inter[0]; i++) {
        printf("%d ", inter[i]);
    }
    printf("\n");

    return 0;
}
