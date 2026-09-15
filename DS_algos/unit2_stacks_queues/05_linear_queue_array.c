/**
 * Unit 2 — Linear Queue Implementation Using Array
 * Topics:
 *   - Linear Queue ADT (FIFO: First In, First Out)
 *   - ENQUEUE operation with OVERFLOW check
 *   - DEQUEUE operation with UNDERFLOW check
 *   - PEEK and DISPLAY operations
 *   - Demonstration of Linear Queue Limitation (unusable freed slots / false overflow)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} LinearQueue;

/* Initialize queue to empty state */
void init_queue(LinearQueue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Check if queue is empty */
int is_empty(const LinearQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

/* Check if rear has reached array capacity (false or real overflow) */
int is_full(const LinearQueue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

/**
 * ENQUEUE: Insert element at REAR
 * Time Complexity: O(1)
 */
int enqueue(LinearQueue *q, int item) {
    if (is_full(q)) {
        printf("  [Overflow] Cannot enqueue %d: REAR reached MAX (%d).\n", item, MAX_QUEUE_SIZE);
        return 0;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = item;
    printf("  Enqueued: %d (FRONT = %d, REAR = %d)\n", item, q->front, q->rear);
    return 1;
}

/**
 * DEQUEUE: Remove element from FRONT
 * Time Complexity: O(1)
 */
int dequeue(LinearQueue *q, int *deleted_item) {
    if (is_empty(q)) {
        printf("  [Underflow] Cannot dequeue: Queue is empty.\n");
        return 0;
    }
    *deleted_item = q->data[q->front];
    printf("  Dequeued: %d (from index %d)\n", *deleted_item, q->front);
    q->front++;

    /* Reset indices if queue becomes empty after dequeue */
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
        printf("  (Queue became completely empty, FRONT & REAR reset to -1)\n");
    }
    return 1;
}

/**
 * PEEK: Inspect element at FRONT without removing it
 * Time Complexity: O(1)
 */
int peek(const LinearQueue *q, int *front_item) {
    if (is_empty(q)) {
        return 0;
    }
    *front_item = q->data[q->front];
    return 1;
}

/**
 * DISPLAY: Print all elements from FRONT to REAR
 * Time Complexity: O(n)
 */
void display_queue(const LinearQueue *q) {
    if (is_empty(q)) {
        printf("  Queue is EMPTY (front = %d, rear = %d)\n", q->front, q->rear);
        return;
    }
    printf("  Queue [front=%d to rear=%d]: ", q->front, q->rear);
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 2: Linear Queue Using Array (Capacity = %d)\n", MAX_QUEUE_SIZE);
    printf("====================================================\n\n");

    LinearQueue q;
    init_queue(&q);

    int val;
    printf("1. Initial State:\n");
    assert(is_empty(&q));
    display_queue(&q);

    printf("\n2. Enqueueing 5 elements (filling to capacity):\n");
    for (int i = 10; i <= 50; i += 10) {
        enqueue(&q, i);
    }
    display_queue(&q);

    printf("\n3. Testing OVERFLOW:\n");
    assert(is_full(&q));
    enqueue(&q, 60); /* Should fail */

    printf("\n4. Testing PEEK:\n");
    if (peek(&q, &val)) {
        printf("  FRONT element is: %d\n", val);
        assert(val == 10);
    }

    printf("\n5. Dequeueing 2 elements:\n");
    dequeue(&q, &val); assert(val == 10);
    dequeue(&q, &val); assert(val == 20);
    display_queue(&q);

    printf("\n6. Demonstrating the limitation of Linear Array Queue:\n");
    printf("  Even though 2 slots are vacant at the front, is_full() is STILL true because REAR == MAX - 1.\n");
    printf("  Attempting to enqueue 60:\n");
    int success = enqueue(&q, 60);
    assert(success == 0);
    printf("  -> This limitation is solved by Circular Queue (Unit 2, Section 56)!\n");

    printf("\n7. Dequeueing remaining elements until empty:\n");
    dequeue(&q, &val); assert(val == 30);
    dequeue(&q, &val); assert(val == 40);
    dequeue(&q, &val); assert(val == 50);
    display_queue(&q);

    printf("\n8. Testing UNDERFLOW:\n");
    assert(is_empty(&q));
    success = dequeue(&q, &val);
    assert(success == 0);

    printf("\n>>> All Linear Queue Array tests passed successfully! <<<\n");
    return 0;
}
