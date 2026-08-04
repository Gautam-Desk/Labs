

/*
Algorithm: Delete node from the end of a singly linked list

1. Check if the list is empty.
   - If head is NULL, print a friendly message and return.

2. Check if the list has only one node.
   - If head->next is NULL, free head and set head to NULL.
   - This removes the only node cleanly.

3. Otherwise, traverse the list to find the last node.
   - Keep two pointers: previous and current.
   - Move current forward until current->next is NULL.
   - previous always points to the node before current.

4. Delete the last node.
   - Set previous->next to NULL.
   - free(current).

5. Print the list before and after deletion so the user can see the change.

Example:
- List before deletion: 5 -> 10 -> 15
- Deleted value: 15
- List after deletion: 5 -> 10
*/


#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Allocate a new node with the given value
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the list
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete the last node of the list
void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("Deleting the only node with value %d.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    printf("Deleting node with value %d from the end.\n", current->data);
    previous->next = NULL;
    free(current);
}

// Print the current list contents
void printList(const struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Current list: ");
    const struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    struct Node *head = NULL;
    int n, value;

    printf("Enter how many nodes you want to add: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }
        insertEnd(&head, value);
    }

    printList(head);
    deleteEnd(&head);
    printList(head);

    // Free any remaining nodes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/*
Algorithm: Delete node from the end of a singly linked list

1. Check if the list is empty.
   - If head is NULL, print a friendly message and return.

2. Check if the list has only one node.
   - If head->next is NULL, free head and set head to NULL.
   - This removes the only node cleanly.

3. Otherwise, traverse the list to find the last node.
   - Keep two pointers: previous and current.
   - Move current forward until current->next is NULL.
   - previous always points to the node before current.

4. Delete the last node.
   - Set previous->next to NULL.
   - free(current).

5. Print the list before and after deletion so the user can see the change.

Example:
- List before deletion: 5 -> 10 -> 15
- Deleted value: 15
- List after deletion: 5 -> 10
*/
