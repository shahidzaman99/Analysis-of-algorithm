#include <iostream>
#define N 3 // Define the matrix size

using namespace std;

void matrixMultiplication(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Fix: Add '*' for multiplication
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function to test matrix multiplication
int main() {
    int A[N][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int B[N][N] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int C[N][N];

    matrixMultiplication(A, B, C, N);

    cout << "Resultant Matrix: " << endl;
    printMatrix(C, N);

    return 0;
}

