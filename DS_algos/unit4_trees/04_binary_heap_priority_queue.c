/**
 * Unit 4 — Binary Heap & Priority Queue
 * Topics:
 *   - Complete Binary Tree Array Representation
 *   - Max-Heap & Min-Heap Invariants
 *   - Sift-Up (Heap Insertion, O(log n))
 *   - Sift-Down / Max-Heapify (O(log n))
 *   - Extract-Max (Priority Queue Dequeue, O(log n))
 *   - Linear-Time Heap Construction (Build-Heap, O(n))
 *   - In-Place Heap Sort (O(n log n))
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_HEAP_CAPACITY 128

typedef struct {
    int data[MAX_HEAP_CAPACITY];
    int size;
} MaxHeap;

void init_heap(MaxHeap *heap) {
    heap->size = 0;
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ========================================================================= */
/* 1. Sift-Down (Max-Heapify)                                                */
/* ========================================================================= */

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

/* ========================================================================= */
/* 2. Heap Insertion (Sift-Up)                                               */
/* ========================================================================= */

bool heap_insert(MaxHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_CAPACITY) {
        return false;
    }

    int i = heap->size++;
    heap->data[i] = value;

    /* Sift-up */
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return true;
}

/* ========================================================================= */
/* 3. Extract-Max (Priority Queue Pop)                                       */
/* ========================================================================= */

int heap_extract_max(MaxHeap *heap, bool *success) {
    if (heap->size <= 0) {
        if (success) *success = false;
        return -1;
    }

    int max_val = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    max_heapify(heap->data, heap->size, 0);

    if (success) *success = true;
    return max_val;
}

/* ========================================================================= */
/* 4. Build-Heap & Heap Sort                                                 */
/* ========================================================================= */

void build_max_heap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n) {
    build_max_heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 4: Binary Max-Heap & Priority Queue\n");
    printf("========================================================\n\n");

    MaxHeap pq;
    init_heap(&pq);

    /* Test Insertion */
    int elements[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        heap_insert(&pq, elements[i]);
    }

    printf("Priority Queue Max element: %d (Expected: 44)\n", pq.data[0]);
    assert(pq.data[0] == 44);

    /* Test Extract-Max (should extract in descending priority order) */
    printf("Extracting elements by priority: ");
    int prev = 99999;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        int val = heap_extract_max(&pq, &ok);
        assert(ok);
        printf("%d ", val);
        assert(val <= prev);
        prev = val;
    }
    printf("\n");
    assert(pq.size == 0);

    /* Test In-Place Heap Sort */
    int sort_arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int sort_n = sizeof(sort_arr) / sizeof(sort_arr[0]);

    printf("\nOriginal Array: ");
    for (int i = 0; i < sort_n; i++) printf("%d ", sort_arr[i]);
    printf("\n");

    heap_sort(sort_arr, sort_n);

    printf("Sorted by Heap Sort: ");
    for (int i = 0; i < sort_n; i++) printf("%d ", sort_arr[i]);
    printf("\n");

    for (int i = 0; i < sort_n - 1; i++) {
        assert(sort_arr[i] <= sort_arr[i + 1]);
    }

    printf("\n[PASS] All Binary Heap & Priority Queue tests passed successfully!\n");
    return 0;
}
