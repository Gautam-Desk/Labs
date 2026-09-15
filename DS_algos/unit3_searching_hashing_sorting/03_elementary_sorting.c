/**
 * Unit 3 — Elementary Sorting Algorithms
 * Topics:
 *   - Insertion Sort (Adaptive, Stable, In-Place)
 *   - Selection Sort (Min-Element Swap, Minimal Data Movement, In-Place)
 *   - Bubble Sort (Standard & Optimized with Early-Exit Flag)
 *   - Step/Comparison Counters & Stability Demonstrations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

static bool is_sorted(const int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

/* ========================================================================= */
/* 1. Insertion Sort                                                         */
/* ========================================================================= */

/**
 * Builds the sorted portion one element at a time by shifting larger items right.
 * Time Complexity: Best O(n), Average O(n^2), Worst O(n^2)
 * Space Complexity: O(1) in-place
 * Stability: STABLE
 */
void insertion_sort(int arr[], int n, long long *comparisons, long long *shifts) {
    if (comparisons) *comparisons = 0;
    if (shifts) *shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            if (comparisons) (*comparisons)++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j]; /* Shift right */
                if (shifts) (*shifts)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

/* ========================================================================= */
/* 2. Selection Sort                                                         */
/* ========================================================================= */

/**
 * Finds the minimum element from the unsorted sub-array and swaps it into place.
 * Time Complexity: Best O(n^2), Average O(n^2), Worst O(n^2)
 * Space Complexity: O(1) in-place
 * Data Movement: O(n) swaps (minimal among elementary sorts)
 * Stability: NOT STABLE (due to long swaps)
 */
void selection_sort(int arr[], int n, long long *comparisons, long long *swaps) {
    if (comparisons) *comparisons = 0;
    if (swaps) *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (comparisons) (*comparisons)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            if (swaps) (*swaps)++;
        }
    }
}

/* ========================================================================= */
/* 3. Bubble Sort (Standard & Optimized)                                    */
/* ========================================================================= */

/**
 * Standard Bubble Sort: Always performs n*(n-1)/2 comparisons.
 */
void bubble_sort_standard(int arr[], int n, long long *comparisons, long long *swaps) {
    if (comparisons) *comparisons = 0;
    if (swaps) *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparisons) (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                if (swaps) (*swaps)++;
            }
        }
    }
}

/**
 * Optimized Bubble Sort: Uses early-exit flag 'swapped'.
 * Time Complexity: Best O(n) for nearly-sorted data, Worst O(n^2)
 * Stability: STABLE
 */
void bubble_sort_optimized(int arr[], int n, long long *comparisons, long long *swaps) {
    if (comparisons) *comparisons = 0;
    if (swaps) *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparisons) (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                if (swaps) (*swaps)++;
                swapped = true;
            }
        }
        /* If no elements were swapped in this entire pass, array is already sorted */
        if (!swapped) break;
    }
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 3: Elementary Sorting Algorithms\n");
    printf("====================================================\n\n");

    int raw[] = {64, 25, 12, 22, 11, 90, 34};
    int n = sizeof(raw) / sizeof(raw[0]);

    printf("Original Array:\n  ");
    print_array(raw, n);
    printf("\n");

    /* 1. Test Insertion Sort */
    {
        int arr[7];
        for (int i = 0; i < n; i++) arr[i] = raw[i];
        long long cmp = 0, shifts = 0;
        insertion_sort(arr, n, &cmp, &shifts);
        printf("1. Insertion Sort Result:\n  ");
        print_array(arr, n);
        printf("   Comparisons: %lld, Shifts: %lld\n\n", cmp, shifts);
        assert(is_sorted(arr, n));
    }

    /* 2. Test Selection Sort */
    {
        int arr[7];
        for (int i = 0; i < n; i++) arr[i] = raw[i];
        long long cmp = 0, swaps = 0;
        selection_sort(arr, n, &cmp, &swaps);
        printf("2. Selection Sort Result:\n  ");
        print_array(arr, n);
        printf("   Comparisons: %lld, Swaps: %lld\n\n", cmp, swaps);
        assert(is_sorted(arr, n));
    }

    /* 3. Test Bubble Sort Standard vs Optimized on Already-Sorted Array */
    {
        int sorted_arr[] = {11, 12, 22, 25, 34, 64, 90};
        long long cmp_std = 0, swp_std = 0;
        long long cmp_opt = 0, swp_opt = 0;

        int a1[7], a2[7];
        for (int i = 0; i < 7; i++) { a1[i] = sorted_arr[i]; a2[i] = sorted_arr[i]; }

        bubble_sort_standard(a1, 7, &cmp_std, &swp_std);
        bubble_sort_optimized(a2, 7, &cmp_opt, &swp_opt);

        printf("3. Already-Sorted Array Best-Case Comparison (N = 7):\n");
        printf("   - Standard Bubble Sort:  Comparisons = %lld, Swaps = %lld\n", cmp_std, swp_std);
        printf("   - Optimized Bubble Sort: Comparisons = %lld, Swaps = %lld (Early break!)\n\n", cmp_opt, swp_opt);
        assert(cmp_opt == 6); /* Only one pass needed */
    }

    printf(">>> All Elementary Sorting tests passed successfully! <<<\n");
    return 0;
}
