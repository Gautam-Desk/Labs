/**
 * Unit 3 — Searching Algorithms
 * Topics:
 *   - Linear Search (Sequential Search)
 *   - Indexed Sequential Search (Block-based index lookup)
 *   - Binary Search (Iterative Implementation)
 *   - Binary Search (Recursive Implementation)
 *   - Empirical Comparison of Search Step Counts & Boundary Edge Cases
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ========================================================================= */
/* 1. Linear Search                                                          */
/* ========================================================================= */

/**
 * Sequential search through array elements.
 * Time Complexity: Best O(1), Average O(n), Worst O(n)
 * Space Complexity: O(1)
 */
int linear_search(const int arr[], int n, int item, int *comparisons) {
    if (comparisons) *comparisons = 0;
    for (int i = 0; i < n; i++) {
        if (comparisons) (*comparisons)++;
        if (arr[i] == item) {
            return i; /* Found at index i */
        }
    }
    return -1; /* Not found */
}

/* ========================================================================= */
/* 2. Indexed Sequential Search                                              */
/* ========================================================================= */

typedef struct {
    int key;       /* Highest key in the block */
    int start_idx; /* Starting index of the block in main array */
} BlockIndex;

/**
 * Indexed Sequential Search on a sorted array:
 * 1. An auxiliary index table stores the max key and starting index of each block.
 * 2. Search index table to locate candidate block.
 * 3. Perform linear search only inside the identified block.
 *
 * Time Complexity: O(k + (n/k)) where k is block size, optimized when k = sqrt(n).
 */
int indexed_sequential_search(const int arr[], int n, int item, int block_size, int *comparisons) {
    if (comparisons) *comparisons = 0;
    if (n <= 0 || block_size <= 0) return -1;

    int num_blocks = (n + block_size - 1) / block_size;
    BlockIndex *index_table = (BlockIndex *)malloc(sizeof(BlockIndex) * num_blocks);
    if (!index_table) return -1;

    /* Build the index table */
    for (int b = 0; b < num_blocks; b++) {
        int start = b * block_size;
        int end = start + block_size - 1;
        if (end >= n) end = n - 1;

        index_table[b].start_idx = start;
        index_table[b].key = arr[end]; /* Maximum key in this block */
    }

    /* Step 1: Search index table to find candidate block */
    int target_block = -1;
    for (int b = 0; b < num_blocks; b++) {
        if (comparisons) (*comparisons)++;
        if (item <= index_table[b].key) {
            target_block = b;
            break;
        }
    }

    /* If item is greater than the maximum key of the last block, it is not present */
    if (target_block == -1) {
        free(index_table);
        return -1;
    }

    /* Step 2: Linear search inside candidate block */
    int block_start = index_table[target_block].start_idx;
    int block_end = block_start + block_size - 1;
    if (block_end >= n) block_end = n - 1;

    free(index_table);

    for (int i = block_start; i <= block_end; i++) {
        if (comparisons) (*comparisons)++;
        if (arr[i] == item) {
            return i;
        }
    }

    return -1;
}

/* ========================================================================= */
/* 3. Binary Search — Iterative                                              */
/* ========================================================================= */

/**
 * Halves the search space on each comparison. Requires sorted array.
 * Time Complexity: Best O(1), Average O(log n), Worst O(log n)
 * Space Complexity: O(1)
 */
int binary_search_iterative(const int arr[], int n, int item, int *comparisons) {
    if (comparisons) *comparisons = 0;
    int beg = 0;
    int end = n - 1;

    while (beg <= end) {
        /* Prevents arithmetic overflow compared to (beg + end) / 2 */
        int mid = beg + (end - beg) / 2;

        if (comparisons) (*comparisons)++;
        if (arr[mid] == item) {
            return mid;
        } else if (item < arr[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    return -1;
}

/* ========================================================================= */
/* 4. Binary Search — Recursive                                              */
/* ========================================================================= */

/**
 * Recursive divide-and-conquer implementation.
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) call stack frames
 */
int binary_search_recursive_helper(const int arr[], int beg, int end, int item, int *comparisons) {
    if (beg > end) {
        return -1;
    }

    int mid = beg + (end - beg) / 2;

    if (comparisons) (*comparisons)++;
    if (arr[mid] == item) {
        return mid;
    } else if (item < arr[mid]) {
        return binary_search_recursive_helper(arr, beg, mid - 1, item, comparisons);
    } else {
        return binary_search_recursive_helper(arr, mid + 1, end, item, comparisons);
    }
}

int binary_search_recursive(const int arr[], int n, int item, int *comparisons) {
    if (comparisons) *comparisons = 0;
    return binary_search_recursive_helper(arr, 0, n - 1, item, comparisons);
}

/* ========================================================================= */
/* Test Driver & Empirical Comparison                                        */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 3: Searching Algorithms Comparison\n");
    printf("====================================================\n\n");

    int sorted_data[] = {12, 18, 25, 33, 40, 48, 55, 62, 70, 85, 91, 105, 120, 135, 150, 180};
    int n = sizeof(sorted_data) / sizeof(sorted_data[0]);

    printf("Sorted Dataset (N = %d):\n  ", n);
    for (int i = 0; i < n; i++) printf("%d ", sorted_data[i]);
    printf("\n\n");

    int targets[] = {12, 70, 180, 99}; /* Best, Middle, Worst, Missing */
    int num_targets = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < num_targets; t++) {
        int target = targets[t];
        int cmp_lin = 0, cmp_idx = 0, cmp_bs_iter = 0, cmp_bs_rec = 0;

        int res_lin = linear_search(sorted_data, n, target, &cmp_lin);
        int res_idx = indexed_sequential_search(sorted_data, n, target, 4, &cmp_idx);
        int res_iter = binary_search_iterative(sorted_data, n, target, &cmp_bs_iter);
        int res_rec = binary_search_recursive(sorted_data, n, target, &cmp_bs_rec);

        /* All methods must agree on whether the element exists and its index */
        assert(res_lin == res_iter);
        assert(res_idx == res_iter);
        assert(res_rec == res_iter);

        printf("Searching for ITEM = %3d:\n", target);
        if (res_iter != -1) {
            printf("  Result: FOUND at index %d\n", res_iter);
        } else {
            printf("  Result: NOT FOUND\n");
        }
        printf("  - Linear Search:             Comparisons = %2d\n", cmp_lin);
        printf("  - Indexed Sequential Search: Comparisons = %2d\n", cmp_idx);
        printf("  - Binary Search (Iterative): Comparisons = %2d\n", cmp_bs_iter);
        printf("  - Binary Search (Recursive): Comparisons = %2d\n\n", cmp_bs_rec);
    }

    printf(">>> All Searching tests and assertions passed! <<<\n");
    return 0;
}
