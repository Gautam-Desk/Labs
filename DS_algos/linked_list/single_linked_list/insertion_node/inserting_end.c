/*
 * Singly Linked List Insertion at End (User Input) in C
 *
 * Algorithm:
 * 1. Define a node structure with data and a next pointer.
 * 2. Read the number of nodes and values from the user.
 * 3. Build the initial linked list by appending nodes at the tail.
 * 4. Read the value to insert at the end of the list.
 * 5. Create a new node and set tail->next = newNode.
 * 6. Set newNode->next = NULL.
 * 7. Traverse and print the final list.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of nodes should be at least 1.\n");
        return 1;
    }

    int value;
    printf("Enter value for node 1: ");
    scanf("%d", &value);
    struct Node *head = createNode(value);
    struct Node *tail = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        tail->next = createNode(value);
        tail = tail->next;
    }

    printf("Original list:\n");
    traverseList(head);

    printf("Enter value to insert at the end: ");
    scanf("%d", &value);
    struct Node *newNode = createNode(value);
    tail->next = newNode;
    tail = newNode;

    printf("After inserting at the end:\n");
    traverseList(head);

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
 * - The program defines a linked list node with `data` and a `next` pointer.
 * - It reads the number of nodes and builds the list by appending each new node.
 * - The `tail` pointer always points to the last node in the list.
 * - To insert at the end, a new node is created and attached using `tail->next`.
 * - The tail pointer is updated to point to the new last node.
 * - The final list is traversed and printed to show the updated sequence.
 * - The program frees all allocated nodes before exiting.
 */
