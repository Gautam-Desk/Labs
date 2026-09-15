/**
 * Unit 2 — Circular Queue Implementation Using Array
 * Topics:
 *   - Circular Queue ADT (Modulo wrap-around buffer)
 *   - OVERFLOW condition: ((FRONT == 0 && REAR == N - 1) || (REAR == FRONT - 1))
 *   - UNDERFLOW condition: FRONT == -1
 *   - Circular ENQUEUE & DEQUEUE operations
 *   - Circular DISPLAY operation
 *   - Optimal O(1) space reuse overcoming linear queue limitations
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CQUEUE_CAPACITY 5

typedef struct {
    int data[CQUEUE_CAPACITY];
    int front;
    int rear;
} CircularQueue;

/* Initialize circular queue to empty state */
void init_cqueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Check if circular queue is empty */
int is_empty(const CircularQueue *q) {
    return (q->front == -1);
}

/* Check if circular queue is full */
int is_full(const CircularQueue *q) {
    return ((q->front == 0 && q->rear == CQUEUE_CAPACITY - 1) ||
            (q->rear == q->front - 1));
}

/**
 * ENQUEUE: Insert element at REAR with circular wrap-around
 * Time Complexity: O(1)
 */
int enqueue(CircularQueue *q, int item) {
    if (is_full(q)) {
        printf("  [Overflow] Circular Queue is FULL! Cannot enqueue %d (front=%d, rear=%d)\n",
               item, q->front, q->rear);
        return 0;
    }

    if (q->front == -1) {
        /* First element being inserted */
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == CQUEUE_CAPACITY - 1 && q->front != 0) {
        /* Wrap-around to the beginning */
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->data[q->rear] = item;
    printf("  Enqueued: %d at index %d (front=%d, rear=%d)\n", item, q->rear, q->front, q->rear);
    return 1;
}

/**
 * DEQUEUE: Remove element from FRONT with circular wrap-around
 * Time Complexity: O(1)
 */
int dequeue(CircularQueue *q, int *deleted_item) {
    if (is_empty(q)) {
        printf("  [Underflow] Circular Queue is EMPTY! Cannot dequeue.\n");
        return 0;
    }

    *deleted_item = q->data[q->front];
    printf("  Dequeued: %d from index %d ", *deleted_item, q->front);

    if (q->front == q->rear) {
        /* Only one element was in the queue; reset to empty */
        q->front = -1;
        q->rear = -1;
        printf("-> Queue is now empty (front=rear=-1)\n");
    } else if (q->front == CQUEUE_CAPACITY - 1) {
        /* Wrap-around to index 0 */
        q->front = 0;
        printf("-> front wrapped around to 0\n");
    } else {
        q->front++;
        printf("-> front advanced to %d\n", q->front);
    }

    return 1;
}

/**
 * PEEK: Get element at FRONT without removing it
 * Time Complexity: O(1)
 */
int peek(const CircularQueue *q, int *front_item) {
    if (is_empty(q)) return 0;
    *front_item = q->data[q->front];
    return 1;
}

/**
 * DISPLAY: Print elements in circular order from FRONT to REAR
 * Time Complexity: O(n)
 */
void display_cqueue(const CircularQueue *q) {
    if (is_empty(q)) {
        printf("  Circular Queue is EMPTY (front = -1, rear = -1)\n");
        return;
    }

    printf("  Circular Queue [front=%d, rear=%d]: ", q->front, q->rear);
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % CQUEUE_CAPACITY;
    }
    printf("\n");
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 2: Circular Queue Using Array (Capacity = %d)\n", CQUEUE_CAPACITY);
    printf("====================================================\n\n");

    CircularQueue q;
    init_cqueue(&q);

    int val;
    printf("1. Initial state:\n");
    assert(is_empty(&q));
    display_cqueue(&q);

    printf("\n2. Enqueueing 5 elements (filling the circular buffer):\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display_cqueue(&q);
    assert(is_full(&q));

    printf("\n3. Testing OVERFLOW on full circular queue:\n");
    int success = enqueue(&q, 60);
    assert(success == 0);

    printf("\n4. Dequeueing 2 elements (freeing indices 0 and 1):\n");
    dequeue(&q, &val); assert(val == 10);
    dequeue(&q, &val); assert(val == 20);
    display_cqueue(&q);
    assert(!is_full(&q));

    printf("\n5. Enqueueing new items (Testing WRAP-AROUND into indices 0 and 1):\n");
    enqueue(&q, 60); /* enters at index 0 */
    enqueue(&q, 70); /* enters at index 1 */
    display_cqueue(&q);
    assert(is_full(&q));

    printf("\n6. Testing PEEK on wrapped queue:\n");
    if (peek(&q, &val)) {
        printf("  FRONT element is: %d\n", val);
        assert(val == 30);
    }

    printf("\n7. Dequeueing all remaining elements:\n");
    dequeue(&q, &val); assert(val == 30);
    dequeue(&q, &val); assert(val == 40);
    dequeue(&q, &val); assert(val == 50);
    dequeue(&q, &val); assert(val == 60);
    dequeue(&q, &val); assert(val == 70);
    display_cqueue(&q);
    assert(is_empty(&q));

    printf("\n8. Testing UNDERFLOW on empty circular queue:\n");
    success = dequeue(&q, &val);
    assert(success == 0);

    printf("\n>>> All Circular Queue tests passed successfully! <<<\n");
    return 0;
}
