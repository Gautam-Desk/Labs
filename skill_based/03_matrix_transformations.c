/**
 * Skill-Based C Programming — Matrix Transformations & Dynamic 2D Arrays
 * Topics:
 *   - Contiguous & Pointer-to-Pointer 2D Matrix Allocation
 *   - Matrix Transpose in O(R * C)
 *   - In-Place 90-Degree Clockwise Matrix Rotation (Transpose + Row Reverse)
 *   - Determinant Calculation for 2x2 and 3x3 Matrices
 *   - Memory Leak Prevention via Safe Deallocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **create_matrix(int rows, int cols) {
    int **mat = (int **)malloc(sizeof(int *) * rows);
    if (!mat) {
        fprintf(stderr, "Allocation failure\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(sizeof(int) * cols);
        if (!mat[i]) {
            fprintf(stderr, "Allocation failure\n");
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

void free_matrix(int **mat, int rows) {
    if (!mat) return;
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

int **transpose_matrix(int **mat, int rows, int cols) {
    int **trans = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    return trans;
}

void rotate_matrix_90_clockwise(int **mat, int n) {
    /* Step 1: Transpose in-place for square matrix */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    /* Step 2: Reverse each row */
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int temp = mat[i][left];
            mat[i][left] = mat[i][right];
            mat[i][right] = temp;
            left++;
            right--;
        }
    }
}

int determinant_3x3(int mat[3][3]) {
    int a = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
    int b = mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
    int c = mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return a - b + c;
}

int main(void) {
    printf("========================================================\n");
    printf("   Skill-Based Lab: 2D Matrix Transformations\n");
    printf("========================================================\n\n");

    /* 1. Transpose test: 2x3 matrix -> 3x2 matrix */
    int rows = 2, cols = 3;
    int **mat = create_matrix(rows, cols);
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;

    int **trans = transpose_matrix(mat, rows, cols);
    assert(trans[0][0] == 1 && trans[0][1] == 4);
    assert(trans[1][0] == 2 && trans[1][1] == 5);
    assert(trans[2][0] == 3 && trans[2][1] == 6);
    printf("2x3 Transpose to 3x2 verified [PASS]\n");

    free_matrix(mat, rows);
    free_matrix(trans, cols);

    /* 2. Rotate 3x3 square matrix 90 deg clockwise:
     *  [ 1 2 3 ]      [ 7 4 1 ]
     *  [ 4 5 6 ]  ->  [ 8 5 2 ]
     *  [ 7 8 9 ]      [ 9 6 3 ]
     */
    int n = 3;
    int **sq = create_matrix(n, n);
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sq[i][j] = val++;
        }
    }

    rotate_matrix_90_clockwise(sq, n);
    printf("\nRotated 3x3 Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("  [ %d %d %d ]\n", sq[i][0], sq[i][1], sq[i][2]);
    }

    assert(sq[0][0] == 7 && sq[0][1] == 4 && sq[0][2] == 1);
    assert(sq[1][0] == 8 && sq[1][1] == 5 && sq[1][2] == 2);
    assert(sq[2][0] == 9 && sq[2][1] == 6 && sq[2][2] == 3);

    free_matrix(sq, n);

    /* 3. Determinant of 3x3 matrix:
     *  [ 6 1 1 ]
     *  [ 4 -2 5 ]
     *  [ 2 8 7 ]
     *  Det = 6*(-14-40) - 1*(28-10) + 1*(32 - (-4)) = 6*(-54) - 1*(18) + 36 = -324 - 18 + 36 = -306
     */
    int det_mat[3][3] = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    };
    int det = determinant_3x3(det_mat);
    printf("\nDeterminant of 3x3 Matrix: %d (Expected: -306)\n", det);
    assert(det == -306);

    printf("\n[PASS] All Matrix Transformation tests passed successfully!\n");
    return 0;
}
