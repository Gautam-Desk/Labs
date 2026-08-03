/*
 * Singly Linked List Traversal Example in C
 *
 * Algorithm:
 * 1. Define a node structure with a data field and a pointer to the next node.
 * 2. Create the head node and link additional nodes to build the list.
 * 3. Start traversal from the head node.
 * 4. While the current node is not NULL:
 *       a. Visit the current node (print its data).
 *       b. Move to the next node.
 * 5. End when the current node becomes NULL.
 *
 * This example builds a simple list with 4 nodes and prints all values in order.
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure for a singly linked list */
struct Node {
    int data;
    struct Node *next;
};

/* Create a new node with a given value. */
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Print all nodes in the linked list starting from head. */
void traverseList(struct Node *head) {
    struct Node *current = head;
    printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    /* Build a linked list: 10 -> 20 -> 30 -> 40 */
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    traverseList(head);

    /* Free the list nodes to avoid memory leak. */
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/*
 * Explanation:
 *
 * - A singly linked list node is defined using a struct with `data` and `next`.
 * - `createNode` allocates a new node, sets its value, and initializes the next
 *   pointer to NULL.
 * - The list is built by creating the head node and chaining further nodes using
 *   the `next` pointer.
 * - `traverseList` starts from the head and visits each node until the end of
 *   the list is reached (when current becomes NULL).
 * - Each visited node's data is printed during traversal.
 * - After traversal, the code frees each allocated node to release memory.
 *
 * This implementation demonstrates the core linked list operations:
 * node creation, linking nodes, traversal, and cleanup.
 */
