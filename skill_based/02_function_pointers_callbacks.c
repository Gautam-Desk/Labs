/**
 * Skill-Based C Programming — Function Pointers & Callbacks
 * Topics:
 *   - Function Pointer Declarations & Typedefs
 *   - Higher-Order Array Operations:
 *       - Map: transform every element via unary function
 *       - Filter: select elements matching predicate function
 *       - Reduce: accumulate elements into single scalar
 *   - Custom Generic Bubble Sort using Comparator Callbacks
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* ========================================================================= */
/* 1. Higher-Order Functions: Map, Filter, Reduce                            */
/* ========================================================================= */

typedef int (*TransformFn)(int);
typedef bool (*PredicateFn)(int);
typedef int (*ReducerFn)(int, int);

void array_map(const int src[], int dest[], int n, TransformFn fn) {
    for (int i = 0; i < n; i++) {
        dest[i] = fn(src[i]);
    }
}

int array_filter(const int src[], int dest[], int n, PredicateFn predicate) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (predicate(src[i])) {
            dest[count++] = src[i];
        }
    }
    return count;
}

int array_reduce(const int src[], int n, int initial_val, ReducerFn fn) {
    int acc = initial_val;
    for (int i = 0; i < n; i++) {
        acc = fn(acc, src[i]);
    }
    return acc;
}

/* Sample Callbacks */
int square(int x) { return x * x; }
bool is_even(int x) { return (x % 2) == 0; }
int sum_reducer(int acc, int x) { return acc + x; }
int product_reducer(int acc, int x) { return acc * x; }

/* ========================================================================= */
/* 2. Custom Sort with Comparator Callback                                   */
/* ========================================================================= */

typedef int (*ComparatorFn)(int, int);

int ascending_comparator(int a, int b) {
    return a - b;
}

int descending_comparator(int a, int b) {
    return b - a;
}

void custom_sort(int arr[], int n, ComparatorFn comp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (comp(arr[j], arr[j + 1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Skill-Based Lab: Function Pointers & Callbacks\n");
    printf("========================================================\n\n");

    int numbers[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    /* 1. Map Test: Square all elements */
    int squared[6];
    array_map(numbers, squared, n, square);
    printf("Mapped (squared): ");
    for (int i = 0; i < n; i++) printf("%d ", squared[i]);
    printf("\n");
    assert(squared[0] == 1 && squared[2] == 9 && squared[5] == 36);

    /* 2. Filter Test: Even numbers only */
    int evens[6];
    int even_count = array_filter(numbers, evens, n, is_even);
    printf("Filtered (evens): ");
    for (int i = 0; i < even_count; i++) printf("%d ", evens[i]);
    printf("\n");
    assert(even_count == 3);
    assert(evens[0] == 2 && evens[1] == 4 && evens[2] == 6);

    /* 3. Reduce Test: Sum and Product */
    int sum = array_reduce(numbers, n, 0, sum_reducer);
    int product = array_reduce(numbers, n, 1, product_reducer);
    printf("Reduced Sum:     %d (Expected: 21)\n", sum);
    printf("Reduced Product: %d (Expected: 720)\n", product);
    assert(sum == 21);
    assert(product == 720);

    /* 4. Comparator Sort Test */
    int sort_test[] = {45, 12, 89, 34, 23};
    int sn = 5;

    custom_sort(sort_test, sn, ascending_comparator);
    printf("\nSorted Ascending: ");
    for (int i = 0; i < sn; i++) printf("%d ", sort_test[i]);
    printf("\n");
    assert(sort_test[0] == 12 && sort_test[sn - 1] == 89);

    custom_sort(sort_test, sn, descending_comparator);
    printf("Sorted Descending: ");
    for (int i = 0; i < sn; i++) printf("%d ", sort_test[i]);
    printf("\n");
    assert(sort_test[0] == 89 && sort_test[sn - 1] == 12);

    printf("\n[PASS] All Function Pointer & Callback tests passed successfully!\n");
    return 0;
}
