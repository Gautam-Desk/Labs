/**
 * Unit 2 — Queue Implementation Using Linked List
 * Topics:
 *   - Linked Queue ADT (Dynamic FIFO structure)
 *   - ENQUEUE operation (insertion at REAR) with malloc overflow check
 *   - DEQUEUE operation (deletion from FRONT) with UNDERFLOW check
 *   - PEEK and DISPLAY operations
 *   - Dynamic cleanup (no fixed capacity limits)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} LinkedQueue;

/* Initialize empty linked queue */
void init_queue(LinkedQueue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

/* Check if queue is empty */
int is_empty(const LinkedQueue *q) {
    return (q->front == NULL);
}

/**
 * ENQUEUE: Insert at the REAR of the list
 * Time Complexity: O(1)
 * Space Complexity: O(1) per node
 */
int enqueue(LinkedQueue *q, int item) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        printf("  [Overflow] Memory allocation failed for new node!\n");
        return 0;
    }
    new_node->data = item;
    new_node->next = NULL;

    if (q->front == NULL) {
        /* Queue was empty: new node is both FRONT and REAR */
        q->front = new_node;
        q->rear = new_node;
    } else {
        /* Attach to current REAR and advance REAR */
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
    printf("  Enqueued: %d (Queue Size = %d)\n", item, q->size);
    return 1;
}

/**
 * DEQUEUE: Remove from the FRONT of the list
 * Time Complexity: O(1)
 */
int dequeue(LinkedQueue *q, int *deleted_item) {
    if (is_empty(q)) {
        printf("  [Underflow] Cannot dequeue: Linked Queue is empty.\n");
        return 0;
    }

    QueueNode *temp = q->front;
    *deleted_item = temp->data;
    q->front = q->front->next;

    /* If queue is now empty, set REAR to NULL as well */
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    printf("  Dequeued: %d (Remaining Size = %d)\n", *deleted_item, q->size);
    return 1;
}

/**
 * PEEK: Inspect front element without deleting
 * Time Complexity: O(1)
 */
int peek(const LinkedQueue *q, int *front_item) {
    if (is_empty(q)) {
        return 0;
    }
    *front_item = q->front->data;
    return 1;
}

/**
 * DISPLAY: Print nodes from FRONT to REAR
 * Time Complexity: O(n)
 */
void display_queue(const LinkedQueue *q) {
    if (is_empty(q)) {
        printf("  Queue is EMPTY (Size = 0)\n");
        return;
    }
    printf("  Linked Queue [FRONT -> REAR]: ");
    QueueNode *curr = q->front;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL (Size = %d)\n", q->size);
}

/**
 * DESTROY: Free all remaining allocated nodes
 */
void destroy_queue(LinkedQueue *q) {
    QueueNode *curr = q->front;
    while (curr != NULL) {
        QueueNode *next = curr->next;
        free(curr);
        curr = next;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 2: Queue Using Singly Linked List\n");
    printf("====================================================\n\n");

    LinkedQueue q;
    init_queue(&q);

    int val;
    printf("1. Initial state:\n");
    assert(is_empty(&q));
    display_queue(&q);

    printf("\n2. Enqueueing elements 100, 200, 300, 400:\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    display_queue(&q);
    assert(q.size == 4);

    printf("\n3. Testing PEEK:\n");
    if (peek(&q, &val)) {
        printf("  Front element is: %d\n", val);
        assert(val == 100);
    }

    printf("\n4. Dequeueing two elements:\n");
    dequeue(&q, &val); assert(val == 100);
    dequeue(&q, &val); assert(val == 200);
    display_queue(&q);
    assert(q.size == 2);

    printf("\n5. Enqueueing additional elements (dynamically expands without limit):\n");
    enqueue(&q, 500);
    enqueue(&q, 600);
    display_queue(&q);

    printf("\n6. Dequeueing until empty:\n");
    dequeue(&q, &val); assert(val == 300);
    dequeue(&q, &val); assert(val == 400);
    dequeue(&q, &val); assert(val == 500);
    dequeue(&q, &val); assert(val == 600);
    display_queue(&q);
    assert(is_empty(&q));

    printf("\n7. Testing UNDERFLOW:\n");
    int success = dequeue(&q, &val);
    assert(success == 0);

    printf("\n8. Testing memory cleanup:\n");
    enqueue(&q, 999);
    destroy_queue(&q);
    assert(is_empty(&q));
    printf("  Queue successfully destroyed and cleared.\n");

    printf("\n>>> All Linked Queue tests passed successfully! <<<\n");
    return 0;
}
