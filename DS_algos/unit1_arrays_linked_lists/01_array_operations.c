/**
 * Unit 1 — Array Operations and Address Calculation
 * Topics:
 *   - 1D Array Address Calculation
 *   - 2D Row-Major and Column-Major Address Calculation
 *   - N-Dimensional Row-Major Address Calculation (MAZE problem)
 *   - Array Traversal, Insertion, and Deletion
 *   - Matrix Addition
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ========================================================================= */
/* Address Calculation Functions                                             */
/* ========================================================================= */

/**
 * 1D Array Address Calculation:
 * LOC(A[K]) = BA + W * (K - LB)
 */
long address_1d(long ba, int w, int k, int lb) {
    long offset = (long)(k - lb);
    return ba + (w * offset);
}

/**
 * 2D Row-Major Address Calculation:
 * LOC(A[i][j]) = BA + W * ((i - LR) * COLS + (j - LC))
 */
long address_2d_row_major(long ba, int w, int i, int j, int lr, int lc, int num_cols) {
    long er = i - lr;
    long ec = j - lc;
    long offset = (er * num_cols) + ec;
    return ba + (w * offset);
}

/**
 * 2D Column-Major Address Calculation:
 * LOC(A[i][j]) = BA + W * ((j - LC) * ROWS + (i - LR))
 */
long address_2d_column_major(long ba, int w, int i, int j, int lr, int lc, int num_rows) {
    long er = i - lr;
    long ec = j - lc;
    long offset = (ec * num_rows) + er;
    return ba + (w * offset);
}

/**
 * N-Dimensional Row-Major Address Calculation:
 * Generalized Horner-style offset calculation:
 * OFFSET = ((E1 * L2 + E2) * L3 + E3)...
 */
long address_nd_row_major(long base, int w, int n, const int *indices, const int *lbs, const int *ubs) {
    assert(n >= 1);
    long offset = indices[0] - lbs[0];
    for (int i = 1; i < n; i++) {
        long length_i = ubs[i] - lbs[i] + 1;
        long effective_idx = indices[i] - lbs[i];
        offset = (offset * length_i) + effective_idx;
    }
    return base + (w * offset);
}

/* ========================================================================= */
/* Array Primitive Operations                                                */
/* ========================================================================= */

void print_array(const int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

/**
 * Traversal: visit each element once
 */
void traverse_array(const int *arr, int lb, int ub) {
    printf("  Traversing: ");
    for (int k = lb; k <= ub; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

/**
 * Insertion: insert ITEM at index K (0-based)
 * Returns 1 on success, 0 on overflow/invalid index
 */
int insert_array(int *arr, int *n, int max_capacity, int k, int item) {
    if (*n >= max_capacity) {
        printf("  Error: Array Overflow\n");
        return 0;
    }
    if (k < 0 || k > *n) {
        printf("  Error: Invalid insertion index %d\n", k);
        return 0;
    }
    /* Shift elements right from the end */
    for (int j = *n; j > k; j--) {
        arr[j] = arr[j - 1];
    }
    arr[k] = item;
    (*n)++;
    return 1;
}

/**
 * Deletion: remove element from index K (0-based)
 * Returns 1 on success, 0 on underflow/invalid index
 */
int delete_array(int *arr, int *n, int k, int *deleted_item) {
    if (*n <= 0) {
        printf("  Error: Array Underflow\n");
        return 0;
    }
    if (k < 0 || k >= *n) {
        printf("  Error: Invalid deletion index %d\n", k);
        return 0;
    }
    *deleted_item = arr[k];
    /* Shift elements left */
    for (int j = k; j < *n - 1; j++) {
        arr[j] = arr[j + 1];
    }
    (*n)--;
    return 1;
}

/**
 * Matrix Addition: C[i][j] = A[i][j] + B[i][j]
 */
void matrix_add(int rows, int cols, const int a[rows][cols], const int b[rows][cols], int c[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

/* ========================================================================= */
/* Self-Test Suite                                                           */
/* ========================================================================= */

int main(void) {
    printf("=== UNIT 1: Array Operations & Address Calculation Tests ===\n\n");

    /* 1. 1D Address Calculation Test: A[1300...1900], BA = 1020, W = 2, find A[1700] */
    long addr1d = address_1d(1020, 2, 1700, 1300);
    printf("1. 1D Address A[1700] in A[1300..1900] (BA=1020, W=2): %ld\n", addr1d);
    assert(addr1d == 1820);

    /* 2. 2D Row-Major & Column-Major: 3x4 matrix, LB_R=0, LB_C=0, BA=1000, W=4, find A[2][1] */
    long addr2d_rm = address_2d_row_major(1000, 4, 2, 1, 0, 0, 4);
    long addr2d_cm = address_2d_column_major(1000, 4, 2, 1, 0, 0, 3);
    printf("2. 2D Address A[2][1] (BA=1000, W=4):\n   Row-Major = %ld | Column-Major = %ld\n",
           addr2d_rm, addr2d_cm);
    assert(addr2d_rm == 1000 + 4 * (2 * 4 + 1)); /* 1036 */
    assert(addr2d_cm == 1000 + 4 * (1 * 3 + 2)); /* 1020 */

    /* 3. N-D Address Calculation: MAZE(2:8, -4:1, 6:10), target MAZE[5, -1, 8], BA=200, W=4 */
    int indices[3] = {5, -1, 8};
    int lbs[3] = {2, -4, 6};
    int ubs[3] = {8, 1, 10};
    long addr_nd = address_nd_row_major(200, 4, 3, indices, lbs, ubs);
    printf("3. 3D MAZE[5, -1, 8] Address (BA=200, W=4): %ld\n", addr_nd);
    assert(addr_nd == 628);

    /* 4. Array Traversal, Insertion, and Deletion */
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    printf("\n4. Array Operations:\n   Original: ");
    print_array(arr, n);

    traverse_array(arr, 0, n - 1);

    /* Insert 25 at index 2 */
    int ok_ins = insert_array(arr, &n, 10, 2, 25);
    assert(ok_ins == 1);
    printf("   After inserting 25 at index 2: ");
    print_array(arr, n);
    assert(arr[2] == 25 && n == 6);

    /* Delete element at index 4 (which was 40) */
    int deleted_val = 0;
    int ok_del = delete_array(arr, &n, 4, &deleted_val);
    assert(ok_del == 1);
    printf("   After deleting element at index 4 (val=%d): ", deleted_val);
    print_array(arr, n);
    assert(deleted_val == 40 && n == 5);

    /* 5. Matrix Addition */
    int mat_a[2][2] = {{1, 2}, {3, 4}};
    int mat_b[2][2] = {{10, 20}, {30, 40}};
    int mat_c[2][2] = {{0, 0}, {0, 0}};
    matrix_add(2, 2, mat_a, mat_b, mat_c);
    printf("\n5. Matrix Addition Result:\n");
    printf("   [%2d %2d]\n   [%2d %2d]\n", mat_c[0][0], mat_c[0][1], mat_c[1][0], mat_c[1][1]);
    assert(mat_c[0][0] == 11 && mat_c[1][1] == 44);

    printf("\n>>> All Unit 1 Array & Address Calculation tests passed successfully!\n\n");
    return 0;
}
