/**
 * Unit 2 — Priority Queue Implementations
 * Topics:
 *   - Priority Queue ADT (Items served based on priority)
 *   - Ascending vs Descending Priority Queues
 *   - Implementation 1: Sorted Array Priority Queue (Linear shifting, O(n) insert, O(1) delete)
 *   - Implementation 2: Binary Min-Heap Priority Queue (Optimal O(log n) insert, O(log n) extract)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_PQ_SIZE 10

/* ========================================================================= */
/* Implementation 1: Sorted Array Priority Queue                             */
/* (Ascending: lower priority number = higher urgency, e.g., Priority 1 first)*/
/* ========================================================================= */

typedef struct {
    int data;
    int priority; /* Lower number means higher priority */
} PQElement;

typedef struct {
    PQElement elements[MAX_PQ_SIZE];
    int size;
} ArrayPriorityQueue;

void init_array_pq(ArrayPriorityQueue *pq) {
    pq->size = 0;
}

int is_array_pq_empty(const ArrayPriorityQueue *pq) {
    return (pq->size == 0);
}

int is_array_pq_full(const ArrayPriorityQueue *pq) {
    return (pq->size == MAX_PQ_SIZE);
}

/**
 * Insert maintaining sorted order by priority (lowest priority number at index 0)
 * Time Complexity: O(n) due to shifting
 */
int array_pq_insert(ArrayPriorityQueue *pq, int item, int priority) {
    if (is_array_pq_full(pq)) {
        printf("  [Overflow] Array Priority Queue is full!\n");
        return 0;
    }

    /* Find position to insert (maintain ascending order of priority) */
    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority > priority) {
        pq->elements[i + 1] = pq->elements[i]; /* Shift right */
        i--;
    }

    pq->elements[i + 1].data = item;
    pq->elements[i + 1].priority = priority;
    pq->size++;

    printf("  [Array PQ] Inserted (Data: %d, Pri: %d) at index %d (Total: %d)\n",
           item, priority, i + 1, pq->size);
    return 1;
}

/**
 * Remove element with highest priority (index 0)
 * Time Complexity: O(n) shift
 */
int array_pq_delete_min(ArrayPriorityQueue *pq, int *deleted_item, int *priority) {
    if (is_array_pq_empty(pq)) {
        printf("  [Underflow] Array Priority Queue is empty!\n");
        return 0;
    }

    *deleted_item = pq->elements[0].data;
    *priority = pq->elements[0].priority;

    /* Shift all elements left by 1 */
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;

    printf("  [Array PQ] Deleted highest priority: (Data: %d, Pri: %d)\n", *deleted_item, *priority);
    return 1;
}

void display_array_pq(const ArrayPriorityQueue *pq) {
    if (is_array_pq_empty(pq)) {
        printf("  Array PQ is EMPTY\n");
        return;
    }
    printf("  Array PQ Elements [Data(Pri)]: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d(Pri:%d) ", pq->elements[i].data, pq->elements[i].priority);
    }
    printf("\n");
}

/* ========================================================================= */
/* Implementation 2: Binary Min-Heap Priority Queue (Optimal O(log n))       */
/* ========================================================================= */

typedef struct {
    PQElement heap[MAX_PQ_SIZE];
    int size;
} HeapPriorityQueue;

void init_heap_pq(HeapPriorityQueue *pq) {
    pq->size = 0;
}

static void swap_nodes(PQElement *a, PQElement *b) {
    PQElement temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Insert into Min-Heap (Bubble-Up / Heapify-Up)
 * Time Complexity: O(log n)
 */
int heap_pq_insert(HeapPriorityQueue *pq, int item, int priority) {
    if (pq->size == MAX_PQ_SIZE) {
        printf("  [Overflow] Heap Priority Queue is full!\n");
        return 0;
    }

    int i = pq->size;
    pq->heap[i].data = item;
    pq->heap[i].priority = priority;
    pq->size++;

    /* Bubble-up while parent has higher priority number (lower priority) */
    while (i != 0 && pq->heap[(i - 1) / 2].priority > pq->heap[i].priority) {
        swap_nodes(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("  [Heap PQ] Inserted (Data: %d, Pri: %d). Heap size = %d\n", item, priority, pq->size);
    return 1;
}

/**
 * Extract minimum element (root) and Heapify-Down
 * Time Complexity: O(log n)
 */
int heap_pq_extract_min(HeapPriorityQueue *pq, int *item, int *priority) {
    if (pq->size <= 0) {
        printf("  [Underflow] Heap Priority Queue is empty!\n");
        return 0;
    }

    *item = pq->heap[0].data;
    *priority = pq->heap[0].priority;

    /* Move last element to root and sift down */
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size && pq->heap[left].priority < pq->heap[smallest].priority) {
            smallest = left;
        }
        if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority) {
            smallest = right;
        }

        if (smallest != i) {
            swap_nodes(&pq->heap[i], &pq->heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    printf("  [Heap PQ] Extracted Min: (Data: %d, Pri: %d)\n", *item, *priority);
    return 1;
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 2: Priority Queue Implementations\n");
    printf("====================================================\n\n");

    printf("--- PART A: Sorted Array Priority Queue (Ascending Priority) ---\n");
    ArrayPriorityQueue apq;
    init_array_pq(&apq);

    array_pq_insert(&apq, 101, 3);
    array_pq_insert(&apq, 102, 1); /* Highest priority (lowest number) */
    array_pq_insert(&apq, 103, 4);
    array_pq_insert(&apq, 104, 2);
    display_array_pq(&apq);

    int data = 0, pri = 0;
    array_pq_delete_min(&apq, &data, &pri); assert(data == 102 && pri == 1);
    array_pq_delete_min(&apq, &data, &pri); assert(data == 104 && pri == 2);
    display_array_pq(&apq);

    printf("\n--- PART B: Binary Min-Heap Priority Queue (Optimal O(log n)) ---\n");
    HeapPriorityQueue hpq;
    init_heap_pq(&hpq);

    heap_pq_insert(&hpq, 500, 5);
    heap_pq_insert(&hpq, 100, 1);
    heap_pq_insert(&hpq, 300, 3);
    heap_pq_insert(&hpq, 200, 2);
    heap_pq_insert(&hpq, 400, 4);

    printf("\nExtracting all elements in priority order:\n");
    heap_pq_extract_min(&hpq, &data, &pri); assert(data == 100 && pri == 1);
    heap_pq_extract_min(&hpq, &data, &pri); assert(data == 200 && pri == 2);
    heap_pq_extract_min(&hpq, &data, &pri); assert(data == 300 && pri == 3);
    heap_pq_extract_min(&hpq, &data, &pri); assert(data == 400 && pri == 4);
    heap_pq_extract_min(&hpq, &data, &pri); assert(data == 500 && pri == 5);

    printf("\nTesting heap underflow:\n");
    int success = heap_pq_extract_min(&hpq, &data, &pri);
    assert(success == 0);

    printf("\n>>> All Priority Queue tests passed successfully! <<<\n");
    return 0;
}
