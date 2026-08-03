/*
 * Sparse Matrix Example in C
 *
 * Algorithm:
 * 1. Declare a 2D matrix with mostly zero values.
 * 2. Count the number of non-zero elements in the matrix.
 * 3. Use the sparse matrix form (row, column, value) for each non-zero entry.
 * 4. Print the sparse matrix representation.
 *
 * Formula:
 *   - Total elements = rows * cols
 *   - Non-zero count = count of elements where matrix[i][j] != 0
 *   - Sparse matrix header = [rows, cols, nonzero_count]
 *   - Each non-zero element = [row_index, col_index, value]
 *   - Sparse storage size = 3 * (nonzero_count + 1)
 *   - Sparsity ratio = nonzero_count / (rows * cols)
 */

#include <stdio.h>

int main(void)
{
    int matrix[4][5] = {
        {0, 0, 3, 0, 0},
        {22, 0, 0, 0, 17},
        {0, 0, 0, 0, 0},
        {0, 15, 0, 0, 0}};

    int rows = 4;
    int cols = 5;
    int nonzero_count = 0;
    int i, j;

    /* Count non-zero elements in the matrix. */
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonzero_count++;
            }
        }
    }

    printf("Original matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal elements = %d * %d = %d\n", rows, cols, rows * cols);
    printf("Non-zero elements = %d\n", nonzero_count);

    printf("\nSparse matrix representation (row, col, value):\n");
    printf("Header: %d %d %d\n", rows, cols, nonzero_count);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}

/*
 * Explanation:
 *
 * - A sparse matrix is a matrix with many zero entries.
 * - It is stored using only non-zero entries to save space.
 * - In this program, `matrix` is a 4x5 matrix with a few non-zero values.
 * - We count the non-zero values to determine `nonzero_count`.
 * - The sparse representation uses a header row: [rows, cols, nonzero_count].
 * - Each following row stores one non-zero element as [row, col, value].
 * - This reduces storage from rows*cols values to 3*(nonzero_count+1) values.
 */
