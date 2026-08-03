/*
 * Two Matrix Size and Sum Example in C
 *
 * Algorithm:
 * 1. Declare two 2D arrays with fixed dimensions.
 * 2. Set the number of rows and columns manually.
 * 3. Compute the total number of elements in each matrix.
 * 4. Print each matrix in normal 2D array form.
 * 5. Compute the sum of elements in each matrix.
 * 6. Print the dimension, total element count, and sum for both matrices.
 */

#include <stdio.h>

int main(void)
{
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int matrix2[3][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {9, 11, 13, 15}};

    int rows = 3;            /* Number of rows in both matrices */
    int cols = 4;            /* Number of columns in both matrices */
    int total = rows * cols; /* Total number of elements in each matrix */
    int sum1 = 0;            /* Sum of elements in matrix1 */
    int sum2 = 0;            /* Sum of elements in matrix2 */
    int sumMatrix[3][4];     /* Position-wise sum of matrix1 and matrix2 */
    int i, j;

    printf("Matrix 1 dimensions: %d x %d\n", rows, cols);
    printf("Matrix 2 dimensions: %d x %d\n", rows, cols);
    printf("Total number of elements in each matrix: %d\n", total);

    printf("\nMatrix 1 in array form:\n");
    for (i = 0; i < rows; i++)
    {
        printf("[");
        for (j = 0; j < cols; j++)
        {
            printf(" %d", matrix1[i][j]);
            sum1 += matrix1[i][j];
            if (j < cols - 1)
                printf(",");
        }
        printf(" ]\n");
    }

    printf("\nMatrix 2 in array form:\n");
    for (i = 0; i < rows; i++)
    {
        printf("[");
        for (j = 0; j < cols; j++)
        {
            printf(" %d", matrix2[i][j]);
            sum2 += matrix2[i][j];
            if (j < cols - 1)
                printf(",");
        }
        printf(" ]\n");
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nPosition-wise sum of matrix1 and matrix2:\n");
    for (i = 0; i < rows; i++)
    {
        printf("[");
        for (j = 0; j < cols; j++)
        {
            printf(" %d", sumMatrix[i][j]);
            if (j < cols - 1)
                printf(",");
        }
        printf(" ]\n");
    }

    int totalSum = sum1 + sum2;
    printf("\nSum of all elements in matrix1: %d\n", sum1);
    printf("Sum of all elements in matrix2: %d\n", sum2);
    printf("Total sum of all elements in both matrices: %d\n", totalSum);

    return 0;
}

/*
 * Explanation:
 *
 * - Two matrices `matrix1` and `matrix2` are declared, each with 3 rows and 4 columns.
 * - The dimensions are stored in `rows` and `cols`, and the total number of elements
 *   in each matrix is `total = rows * cols`.
 * - The program prints `matrix1` row by row in a normal matrix layout using brackets.
 * - It does the same for `matrix2`, showing the standard array form.
 * - Each element is added to the corresponding sum variable as it is printed.
 * - It also computes a position-wise sum matrix where each entry is the sum
 *   of the corresponding elements from matrix1 and matrix2.
 * - The program prints this position-wise sum matrix in array form.
 * - Finally, it prints the sum of all elements for matrix1, matrix2, and the
 *   combined total.
 *
 * This example demonstrates how to display two matrices in array form while
 * also calculating their sizes, individual sums, combined sum, and position-
 * wise element sums.
 */
