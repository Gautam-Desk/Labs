/*
Complete Singly Linked List Program in C

This program provides a friendly, menu-driven interface for linked list
operations with optimized size tracking and clear user feedback.

Supported operations:
- insert at beginning
- insert at end
- insert at a specific position
- delete from beginning
- delete from end
- delete from a specific position
- search for a value
- display the list and node count
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }
}

int readInt(const char *prompt, int *value) {
    printf("%s", prompt);
    if (scanf("%d", value) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        clearInput();
        return 0;
    }
    clearInput();
    return 1;
}

struct Node *createNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void printDivider(void) {
    printf("------------------------------------------------------------\n");
}

void printList(const struct Node *head, int size) {
    if (head == NULL) {
        printf("The list is empty. (size = 0)\n");
        return;
    }
    printf("Current list (%d node%s): ", size, size == 1 ? "" : "s");
    const struct Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

int insertAtPosition(struct Node **head, int value, int position, int size) {
    if (position < 1 || position > size + 1) {
        printf("Invalid position. You can insert between 1 and %d.\n", size + 1);
        return 0;
    }
    if (position == 1) {
        insertBeginning(head, value);
        return 1;
    }
    struct Node *current = *head;
    for (int index = 1; index < position - 1; index++) {
        current = current->next;
    }
    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
    return 1;
}

int deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return 0;
    }
    struct Node *temp = *head;
    *head = temp->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
    return 1;
}

int deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return 0;
    }
    if ((*head)->next == NULL) {
        printf("Deleted %d from the list. The list is now empty.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return 1;
    }
    struct Node *current = *head;
    struct Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    printf("Deleted %d from the end.\n", current->data);
    previous->next = NULL;
    free(current);
    return 1;
}

int deleteAtPosition(struct Node **head, int position, int size) {
    if (position < 1 || position > size) {
        printf("Invalid position. You can delete between 1 and %d.\n", size);
        return 0;
    }
    if (position == 1) {
        return deleteBeginning(head);
    }
    if (position == size) {
        return deleteEnd(head);
    }
    struct Node *current = *head;
    for (int index = 1; index < position; index++) {
        current = current->next;
    }
    struct Node *previous = *head;
    for (int index = 1; index < position - 1; index++) {
        previous = previous->next;
    }
    previous->next = current->next;
    printf("Deleted %d from position %d.\n", current->data, position);
    free(current);
    return 1;
}

int searchList(const struct Node *head, int key) {
    const struct Node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0;
}

void freeList(struct Node **head) {
    struct Node *current = *head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void showMenu(void) {
    printDivider();
    printf("Complete Linked List Program\n");
    printDivider();
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from position\n");
    printf("7. Search for value\n");
    printf("8. Display list\n");
    printf("9. Exit\n");
    printDivider();
}

int main(void) {
    struct Node *head = NULL;
    int size = 0;
    int choice;
    int value;
    int position;

    while (1) {
        showMenu();
        if (!readInt("Choose an option (1-9): ", &choice)) {
            continue;
        }

        switch (choice) {
            case 1:
                if (readInt("Enter value to insert at beginning: ", &value)) {
                    insertBeginning(&head, value);
                    size++;
                    printList(head, size);
                }
                break;
            case 2:
                if (readInt("Enter value to insert at end: ", &value)) {
                    insertEnd(&head, value);
                    size++;
                    printList(head, size);
                }
                break;
            case 3:
                if (readInt("Enter value to insert: ", &value) &&
                    readInt("Enter position to insert at: ", &position)) {
                    if (insertAtPosition(&head, value, position, size)) {
                        size++;
                        printList(head, size);
                    }
                }
                break;
            case 4:
                if (deleteBeginning(&head)) {
                    size--;
                }
                printList(head, size);
                break;
            case 5:
                if (deleteEnd(&head)) {
                    size--;
                }
                printList(head, size);
                break;
            case 6:
                if (readInt("Enter position to delete: ", &position)) {
                    if (deleteAtPosition(&head, position, size)) {
                        size--;
                    }
                    printList(head, size);
                }
                break;
            case 7:
                if (readInt("Enter value to search: ", &value)) {
                    int found = searchList(head, value);
                    if (found) {
                        printf("Value %d found at position %d.\n", value, found);
                    } else {
                        printf("Value %d not found in the list.\n", value);
                    }
                }
                break;
            case 8:
                printList(head, size);
                break;
            case 9:
                freeList(&head);
                printf("Exiting program. Memory cleaned up.\n");
                return 0;
            default:
                printf("Invalid option. Please select a number from 1 to 9.\n");
                break;
        }
    }
}
