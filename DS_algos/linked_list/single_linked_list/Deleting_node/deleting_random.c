/*
Friendly Linked List Deletion at a Given Position

This program lets the user:
- build a singly linked list by entering node values
- choose a position to delete from the list
- see the list before and after deletion

Deletion rules:
- position 1 removes the first node
- valid positions are from 1 to list length
- if the list is empty or the position is invalid, the program prints a friendly message
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
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

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

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position. Enter a positive position starting from 1.\n");
        return;
    }

    if (position == 1) {
        struct Node *temp = *head;
        printf("Deleting node with value %d at position 1.\n", temp->data);
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;
    int index = 1;

    while (current != NULL && index < position) {
        previous = current;
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Position %d is not valid. The list has fewer nodes.\n", position);
        return;
    }

    printf("Deleting node with value %d at position %d.\n", current->data, position);
    previous->next = current->next;
    free(current);
}

int main(void) {
    struct Node *head = NULL;
    int n, value, position;

    printf("Enter the number of nodes to add: ");
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

    printf("Enter the position to delete: ");
    if (scanf("%d", &position) != 1) {
        printf("Invalid input. Please enter an integer for position.\n");
        return 1;
    }

    deleteAtPosition(&head, position);
    printList(head);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
