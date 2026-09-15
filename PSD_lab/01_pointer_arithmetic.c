/**
 * Problem Solving in C (PSD Lab) — Pointer Arithmetic & Double Pointers
 * Topics:
 *   - Pointer Declaration & Dereferencing
 *   - Pointer Arithmetic (Increment, Offset, Difference)
 *   - Array Traversal via Pointers
 *   - Pass-by-Reference using Pointers (Swap, Min-Max finding)
 *   - Pointer-to-Pointer (Double Pointers) & Dynamic Reference Reassignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Pass-by-reference swap */
void swap_integers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Array traversal via pointer arithmetic to compute sum */
int array_sum_pointer(const int *arr, int n) {
    int sum = 0;
    const int *ptr = arr;
    const int *end = arr + n;
    while (ptr < end) {
        sum += *ptr;
        ptr++;
    }
    return sum;
}

/* Find min and max in a single pass using output pointers */
void find_min_max(const int *arr, int n, int *min_out, int *max_out) {
    assert(n > 0);
    *min_out = *arr;
    *max_out = *arr;

    for (int i = 1; i < n; i++) {
        int val = *(arr + i);
        if (val < *min_out) *min_out = val;
        if (val > *max_out) *max_out = val;
    }
}

/* Double pointer: allocate and initialize buffer through double pointer */
void allocate_buffer(int **buf_ptr, int size, int initial_val) {
    *buf_ptr = (int *)malloc(sizeof(int) * size);
    if (!*buf_ptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        (*buf_ptr)[i] = initial_val;
    }
}

int main(void) {
    printf("========================================================\n");
    printf("   PSD Lab: Pointer Arithmetic & Reference Passing\n");
    printf("========================================================\n\n");

    /* 1. Swap test */
    int x = 42, y = 99;
    swap_integers(&x, &y);
    printf("Swap result: x = %d, y = %d\n", x, y);
    assert(x == 99 && y == 42);

    /* 2. Pointer array traversal */
    int nums[] = {10, 20, 30, 40, 50};
    int total = array_sum_pointer(nums, 5);
    printf("Array sum via pointer: %d (Expected: 150)\n", total);
    assert(total == 150);

    /* 3. Min/Max single pass */
    int min_val, max_val;
    find_min_max(nums, 5, &min_val, &max_val);
    printf("Min: %d, Max: %d\n", min_val, max_val);
    assert(min_val == 10 && max_val == 50);

    /* 4. Double pointer dynamic buffer */
    int *dynamic_buf = NULL;
    allocate_buffer(&dynamic_buf, 4, 7);
    assert(dynamic_buf != NULL);
    for (int i = 0; i < 4; i++) {
        assert(dynamic_buf[i] == 7);
    }
    free(dynamic_buf);

    printf("\n[PASS] All Pointer Arithmetic tests passed successfully!\n");
    return 0;
}
