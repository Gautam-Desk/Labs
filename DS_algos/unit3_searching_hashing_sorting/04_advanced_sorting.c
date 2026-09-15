/**
 * Unit 3 — Advanced Sorting Algorithms
 * Topics:
 *   - Quick Sort (Lomuto Partition & Hoare Partition, Invariants, O(n log n))
 *   - Merge Sort (Divide-and-Conquer, Stable Two-Way Merge, O(n log n))
 *   - Heap Sort (Max-Heapify, Build-Max-Heap, In-Place, O(n log n))
 *   - Radix Sort (LSD Decimal Radix Sort with Counting Sort Subroutine, O(d*(n+b)))
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
/* 1. Quick Sort (Lomuto Partition as specified in syllabus)                 */
/* ========================================================================= */

/**
 * Lomuto Partition Scheme:
 * Uses the rightmost element arr[r] as pivot.
 * Rearranges array so that elements <= pivot are on the left, > pivot on the right.
 */
int partition_lomuto(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void quicksort_helper(int arr[], int p, int r) {
    if (p < r) {
        int q = partition_lomuto(arr, p, r);
        quicksort_helper(arr, p, q - 1);
        quicksort_helper(arr, q + 1, r);
    }
}

void quicksort(int arr[], int n) {
    if (n > 1) {
        quicksort_helper(arr, 0, n - 1);
    }
}

/* ========================================================================= */
/* 2. Merge Sort                                                             */
/* ========================================================================= */

/**
 * Merge two sorted subarrays: arr[p..q] and arr[q+1..r]
 * Time Complexity: O(n1 + n2)
 * Space Complexity: O(n) auxiliary memory
 * Stability: STABLE (uses <= to prefer left subarray on equal keys)
 */
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) L[i] = arr[p + i];
    for (int j = 0; j < n2; j++) R[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_helper(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        merge_sort_helper(arr, p, q);
        merge_sort_helper(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge_sort(int arr[], int n) {
    if (n > 1) {
        merge_sort_helper(arr, 0, n - 1);
    }
}

/* ========================================================================= */
/* 3. Heap Sort (Max-Heap with 0-based indexing)                             */
/* ========================================================================= */

/**
 * Maintains the Max-Heap property for subtree rooted at index i.
 * Time Complexity: O(log n)
 */
void max_heapify(int arr[], int i, int heap_size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heap_size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < heap_size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, heap_size);
    }
}

/**
 * Builds max heap in linear O(n) time.
 */
void build_max_heap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(arr, i, n);
    }
}

/**
 * Heap Sort:
 * 1. Build max heap
 * 2. Repeatedly swap max element (root at 0) with last element and shrink heap
 * Time Complexity: O(n log n) Best/Average/Worst
 * Space Complexity: O(1) In-Place
 * Stability: NOT STABLE
 */
void heap_sort(int arr[], int n) {
    build_max_heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); /* Move current max to end */
        max_heapify(arr, 0, i);  /* Restore max-heap for reduced size */
    }
}

/* ========================================================================= */
/* 4. Radix Sort (LSD Decimal Radix Sort with Counting Sort Subroutine)      */
/* ========================================================================= */

static int get_max_value(const int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

/**
 * Stable Counting Sort on specific decimal digit place (1, 10, 100, etc.)
 */
void counting_sort_for_radix(int arr[], int n, int exp) {
    int *output = (int *)malloc(sizeof(int) * n);
    int count[10] = {0};

    /* Count occurrences of each digit */
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    /* Compute cumulative prefix sums */
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    /* Build output array by processing backwards to preserve STABILITY */
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    /* Copy back to original array */
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

/**
 * Least Significant Digit (LSD) Radix Sort
 * Time Complexity: O(d * (n + b)) where d = max digits, b = base 10
 * Space Complexity: O(n + b)
 * Stability: STABLE
 */
void radix_sort(int arr[], int n) {
    if (n <= 1) return;

    int max_val = get_max_value(arr, n);

    /* Run counting sort for each digit place (exp = 1, 10, 100, ...) */
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_for_radix(arr, n, exp);
    }
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 3: Advanced Sorting Algorithms\n");
    printf("====================================================\n\n");

    int raw[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(raw) / sizeof(raw[0]);

    printf("Original Dataset:\n  ");
    print_array(raw, n);
    printf("\n");

    /* 1. Quick Sort */
    {
        int arr[8];
        for (int i = 0; i < n; i++) arr[i] = raw[i];
        quicksort(arr, n);
        printf("1. Quick Sort (Lomuto Partition):\n  ");
        print_array(arr, n);
        assert(is_sorted(arr, n));
    }

    /* 2. Merge Sort */
    {
        int arr[8];
        for (int i = 0; i < n; i++) arr[i] = raw[i];
        merge_sort(arr, n);
        printf("\n2. Merge Sort (Divide & Conquer):\n  ");
        print_array(arr, n);
        assert(is_sorted(arr, n));
    }

    /* 3. Heap Sort */
    {
        int arr[8];
        for (int i = 0; i < n; i++) arr[i] = raw[i];
        heap_sort(arr, n);
        printf("\n3. Heap Sort (Max-Heap In-Place):\n  ");
        print_array(arr, n);
        assert(is_sorted(arr, n));
    }

    /* 4. Radix Sort (Decimal LSD with Counting Sort) */
    {
        int radix_test[] = {204, 343, 40, 939, 607, 100, 586, 730};
        int rn = sizeof(radix_test) / sizeof(radix_test[0]);
        printf("\n4. Radix Sort on Syllabus Example:\n  Input:  ");
        print_array(radix_test, rn);
        radix_sort(radix_test, rn);
        printf("  Output: ");
        print_array(radix_test, rn);
        assert(is_sorted(radix_test, rn));
    }

    printf("\n>>> All Advanced Sorting tests passed successfully! <<<\n");
    return 0;
}
