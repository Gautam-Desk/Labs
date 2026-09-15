/**
 * Unit 1 — Sparse Matrix (Triplet Representation)
 * Represents a sparse matrix compactly using a 3-column table:
 * Row 0: [Total Rows, Total Columns, Total Non-Zeroes]
 * Subsequent rows: [Row Index, Col Index, Value]
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int row;
    int col;
    int val;
} Element;

typedef struct {
    int rows;
    int cols;
    int num_elements;
    Element *data;
} SparseMatrix;

/**
 * Creates a SparseMatrix from a dense 2D matrix
 */
SparseMatrix create_sparse_from_dense(int rows, int cols, const int dense[rows][cols]) {
    SparseMatrix sm;
    sm.rows = rows;
    sm.cols = cols;
    sm.num_elements = 0;

    /* Count non-zero elements */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dense[i][j] != 0) {
                sm.num_elements++;
            }
        }
    }

    /* Allocate memory for non-zero triplets */
    sm.data = (Element *)malloc((sm.num_elements) * sizeof(Element));
    if (sm.data == NULL && sm.num_elements > 0) {
        fprintf(stderr, "Memory allocation error in create_sparse_from_dense\n");
        exit(EXIT_FAILURE);
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dense[i][j] != 0) {
                sm.data[k].row = i;
                sm.data[k].col = j;
                sm.data[k].val = dense[i][j];
                k++;
            }
        }
    }

    return sm;
}

/**
 * Prints the Triplet representation
 */
void print_sparse(const SparseMatrix *sm) {
    printf("  Sparse Triplet Table:\n");
    printf("  +-----+-----+-------+\n");
    printf("  | Row | Col | Value |\n");
    printf("  +-----+-----+-------+\n");
    printf("  | %3d | %3d | %5d |  <-- Metadata (Rows, Cols, Non-zeroes)\n",
           sm->rows, sm->cols, sm->num_elements);
    printf("  +-----+-----+-------+\n");
    for (int i = 0; i < sm->num_elements; i++) {
        printf("  | %3d | %3d | %5d |\n",
               sm->data[i].row, sm->data[i].col, sm->data[i].val);
    }
    printf("  +-----+-----+-------+\n");
}

/**
 * Computes the Transpose of a Sparse Matrix in Triplet Form
 */
SparseMatrix transpose_sparse(const SparseMatrix *sm) {
    SparseMatrix transposed;
    transposed.rows = sm->cols;
    transposed.cols = sm->rows;
    transposed.num_elements = sm->num_elements;
    transposed.data = (Element *)malloc(transposed.num_elements * sizeof(Element));

    if (transposed.data == NULL && transposed.num_elements > 0) {
        fprintf(stderr, "Memory allocation failed for transpose\n");
        exit(EXIT_FAILURE);
    }

    int k = 0;
    /* Collect elements sorted by original column (which becomes new row) */
    for (int c = 0; c < sm->cols; c++) {
        for (int i = 0; i < sm->num_elements; i++) {
            if (sm->data[i].col == c) {
                transposed.data[k].row = sm->data[i].col;
                transposed.data[k].col = sm->data[i].row;
                transposed.data[k].val = sm->data[i].val;
                k++;
            }
        }
    }

    return transposed;
}

/**
 * Free dynamically allocated memory
 */
void free_sparse(SparseMatrix *sm) {
    if (sm->data != NULL) {
        free(sm->data);
        sm->data = NULL;
    }
    sm->num_elements = 0;
}

int main(void) {
    printf("=== UNIT 1: Sparse Matrix (Triplet Representation) Tests ===\n\n");

    int dense[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 0, 5, 0}
    };

    printf("Original 4x5 Dense Matrix (only 4 non-zero elements):\n");
    for (int i = 0; i < 4; i++) {
        printf("  ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", dense[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    SparseMatrix sm = create_sparse_from_dense(4, 5, dense);
    assert(sm.num_elements == 4);
    print_sparse(&sm);

    /* Verify triplet contents */
    assert(sm.data[0].row == 0 && sm.data[0].col == 2 && sm.data[0].val == 3);
    assert(sm.data[1].row == 0 && sm.data[1].col == 4 && sm.data[1].val == 4);
    assert(sm.data[2].row == 2 && sm.data[2].col == 1 && sm.data[2].val == 2);
    assert(sm.data[3].row == 3 && sm.data[3].col == 3 && sm.data[3].val == 5);

    /* Transpose test */
    printf("\nTransposed Matrix:\n");
    SparseMatrix transposed = transpose_sparse(&sm);
    assert(transposed.rows == 5 && transposed.cols == 4);
    print_sparse(&transposed);

    free_sparse(&sm);
    free_sparse(&transposed);

    printf(">>> All Sparse Matrix tests passed successfully!\n\n");
    return 0;
}
