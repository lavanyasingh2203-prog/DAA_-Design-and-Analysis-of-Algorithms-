#include <stdio.h>

int main() {
    int n;

    printf("Enter the order of square matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("enter elements of matrix B:\n");
    for (int i = 0; i< n; i++ ) {
        for (int j = 0; j < n; j++){
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

// strassen's algorithm for matrix multiplication
    int A11[n/2][n/2], A12[n/2][n/2], A21[n/2][n/2], A22[n/2][n/2];
    int B11[n/2][n/2], B12[n/2][n/2], B21[n/2][n/2], B22[n/2][n/2];
    int C11[n/2][n/2], C12[n/2][n/2], C21[n/2][n/2], C22[n/2][n/2];

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    int M1[n / 2][n / 2], M2[n / 2][n / 2], M3[n / 2][n / 2], M4[n / 2][n / 2];
    int M5[n / 2][n / 2], M6[n / 2][n / 2], M7[n / 2][n / 2];

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            M1[i][j] = (A11[i][j] + A22[i][j]) * (B11[i][j] + B22[i][j]);
            M2[i][j] = (A21[i][j] + A22[i][j]) * B11[i][j];
            M3[i][j] = A11[i][j] * (B12[i][j] - B22[i][j]);
            M4[i][j] = A22[i][j] * (B21[i][j] - B11[i][j]);
            M5[i][j] = (A11[i][j] + A12[i][j]) * B22[i][j];
            M6[i][j] = (A21[i][j] - A11[i][j]) * (B11[i][j] + B12[i][j]);
            M7[i][j] = (A12[i][j] - A22[i][j]) * (B21[i][j] + B22[i][j]);
        }       
    }   

    printf("Resultant Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        printf("%d\t", C[i][j]);
        }
     printf("\n");
}
}