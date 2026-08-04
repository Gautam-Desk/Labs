
/*
Algorithm: Delete node from the beginning of a singly linked list

1. Check if the list is empty.
   - If head is NULL, the list is empty and there is nothing to delete.
   - Print a friendly message and stop.

2. Save the first node in a temporary pointer.
   - temp = head

3. Move the head pointer to the second node.
   - head = head->next

4. Free the memory of the removed first node.
   - free(temp)

5. The list now begins from the former second node.

Example walkthrough:
- Initial list: 10 -> 20 -> 30
- After deletion: 20 -> 30
- The deleted value was 10.

This program also prints the list before and after deletion so the user can clearly see the change.
*/



#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Create a new node with the given value
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the list
void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete the first node of the list
void deleteBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleting node with value %d from the beginning.\n", temp->data);
    free(temp);
}

// Print the linked list
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("Current list: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter the number of nodes to add to the list: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }
        insertEnd(&head, value);
    }

    printList(head);
    deleteBeginning(&head);
    printList(head);

    // Free remaining nodes
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/*
Algorithm: Delete node from the beginning of a singly linked list

1. Check if the list is empty.
   - If head is NULL, the list is empty and there is nothing to delete.
   - Print a friendly message and stop.

2. Save the first node in a temporary pointer.
   - temp = head

3. Move the head pointer to the second node.
   - head = head->next

4. Free the memory of the removed first node.
   - free(temp)

5. The list now begins from the former second node.

Example walkthrough:
- Initial list: 10 -> 20 -> 30
- After deletion: 20 -> 30
- The deleted value was 10.

This program also prints the list before and after deletion so the user can clearly see the change.
*/