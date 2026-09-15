/**
 * Unit 2 — Double-Ended Queue (Deque) Implementation Using Circular Array
 * Topics:
 *   - Deque ADT (Insertion and Deletion at BOTH ends)
 *   - INSERT_FRONT, INSERT_REAR
 *   - DELETE_FRONT, DELETE_REAR
 *   - Input-Restricted Deque (Insertion at one end, deletion at both)
 *   - Output-Restricted Deque (Deletion at one end, insertion at both)
 *   - All operations execute in optimal O(1) time
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEQUE_CAPACITY 6

typedef struct {
    int data[DEQUE_CAPACITY];
    int front;
    int rear;
} Deque;

void init_deque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int is_empty(const Deque *dq) {
    return (dq->front == -1);
}

int is_full(const Deque *dq) {
    return ((dq->front == 0 && dq->rear == DEQUE_CAPACITY - 1) ||
            (dq->front == dq->rear + 1));
}

/**
 * INSERT_FRONT: Insert item at the front end
 * Time Complexity: O(1)
 */
int insert_front(Deque *dq, int item) {
    if (is_full(dq)) {
        printf("  [Overflow] Deque is full! Cannot insert %d at FRONT.\n", item);
        return 0;
    }

    if (dq->front == -1) {
        /* Initial insertion */
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        /* Wrap around to the end of the array */
        dq->front = DEQUE_CAPACITY - 1;
    } else {
        dq->front--;
    }

    dq->data[dq->front] = item;
    printf("  Inserted FRONT: %d (front=%d, rear=%d)\n", item, dq->front, dq->rear);
    return 1;
}

/**
 * INSERT_REAR: Insert item at the rear end
 * Time Complexity: O(1)
 */
int insert_rear(Deque *dq, int item) {
    if (is_full(dq)) {
        printf("  [Overflow] Deque is full! Cannot insert %d at REAR.\n", item);
        return 0;
    }

    if (dq->front == -1) {
        /* Initial insertion */
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == DEQUE_CAPACITY - 1) {
        /* Wrap around to index 0 */
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->data[dq->rear] = item;
    printf("  Inserted REAR:  %d (front=%d, rear=%d)\n", item, dq->front, dq->rear);
    return 1;
}

/**
 * DELETE_FRONT: Remove item from the front end
 * Time Complexity: O(1)
 */
int delete_front(Deque *dq, int *deleted_item) {
    if (is_empty(dq)) {
        printf("  [Underflow] Deque is empty! Cannot delete from FRONT.\n");
        return 0;
    }

    *deleted_item = dq->data[dq->front];
    printf("  Deleted FRONT:  %d (from index %d) ", *deleted_item, dq->front);

    if (dq->front == dq->rear) {
        /* Single element consumed */
        dq->front = -1;
        dq->rear = -1;
        printf("-> Deque now empty\n");
    } else if (dq->front == DEQUE_CAPACITY - 1) {
        dq->front = 0;
        printf("-> front wrapped to 0\n");
    } else {
        dq->front++;
        printf("-> front is now %d\n", dq->front);
    }

    return 1;
}

/**
 * DELETE_REAR: Remove item from the rear end
 * Time Complexity: O(1)
 */
int delete_rear(Deque *dq, int *deleted_item) {
    if (is_empty(dq)) {
        printf("  [Underflow] Deque is empty! Cannot delete from REAR.\n");
        return 0;
    }

    *deleted_item = dq->data[dq->rear];
    printf("  Deleted REAR:   %d (from index %d) ", *deleted_item, dq->rear);

    if (dq->front == dq->rear) {
        /* Single element consumed */
        dq->front = -1;
        dq->rear = -1;
        printf("-> Deque now empty\n");
    } else if (dq->rear == 0) {
        dq->rear = DEQUE_CAPACITY - 1;
        printf("-> rear wrapped to %d\n", dq->rear);
    } else {
        dq->rear--;
        printf("-> rear is now %d\n", dq->rear);
    }

    return 1;
}

/**
 * GET_FRONT: Peek front element
 */
int get_front(const Deque *dq, int *item) {
    if (is_empty(dq)) return 0;
    *item = dq->data[dq->front];
    return 1;
}

/**
 * GET_REAR: Peek rear element
 */
int get_rear(const Deque *dq, int *item) {
    if (is_empty(dq)) return 0;
    *item = dq->data[dq->rear];
    return 1;
}

/**
 * DISPLAY_DEQUE: Traverse elements from FRONT to REAR
 */
void display_deque(const Deque *dq) {
    if (is_empty(dq)) {
        printf("  Deque is EMPTY\n");
        return;
    }

    printf("  Deque contents [front=%d to rear=%d]: ", dq->front, dq->rear);
    int i = dq->front;
    while (1) {
        printf("%d ", dq->data[i]);
        if (i == dq->rear) break;
        i = (i + 1) % DEQUE_CAPACITY;
    }
    printf("\n");
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 2: Deque (Double-Ended Queue) [Capacity = %d]\n", DEQUE_CAPACITY);
    printf("====================================================\n\n");

    Deque dq;
    init_deque(&dq);
    int val = 0;

    printf("1. General Deque Operations:\n");
    insert_rear(&dq, 10);
    insert_rear(&dq, 20);
    insert_front(&dq, 5);
    insert_front(&dq, 2);
    display_deque(&dq);

    printf("\n2. Peeking Ends:\n");
    get_front(&dq, &val); printf("  FRONT value: %d\n", val); assert(val == 2);
    get_rear(&dq, &val);  printf("  REAR value:  %d\n", val); assert(val == 20);

    printf("\n3. Deleting from Both Ends:\n");
    delete_front(&dq, &val); assert(val == 2);
    delete_rear(&dq, &val);  assert(val == 20);
    display_deque(&dq);

    printf("\n4. Testing Full Buffer & Circular Wrapping:\n");
    insert_front(&dq, 1);
    insert_rear(&dq, 30);
    insert_rear(&dq, 40);
    insert_rear(&dq, 50);
    display_deque(&dq);
    assert(is_full(&dq));

    printf("\n5. Testing Overflow:\n");
    int success = insert_front(&dq, 99);
    assert(success == 0);

    printf("\n6. Draining Deque completely:\n");
    while (!is_empty(&dq)) {
        delete_front(&dq, &val);
    }
    display_deque(&dq);
    assert(is_empty(&dq));

    printf("\n7. Input-Restricted Deque Demo (Insert at Rear ONLY, Delete Both Ends):\n");
    insert_rear(&dq, 100);
    insert_rear(&dq, 200);
    insert_rear(&dq, 300);
    display_deque(&dq);
    delete_front(&dq, &val); /* allowed */
    delete_rear(&dq, &val);  /* allowed */
    printf("  Input-restricted demo verified.\n");

    printf("\n8. Output-Restricted Deque Demo (Delete at Front ONLY, Insert Both Ends):\n");
    insert_front(&dq, 50);
    insert_rear(&dq, 60);
    display_deque(&dq);
    delete_front(&dq, &val);
    delete_front(&dq, &val);
    printf("  Output-restricted demo verified.\n");

    printf("\n>>> All Deque tests passed successfully! <<<\n");
    return 0;
}
