/*
 * Singly Linked List Insertion at a Given Position (User Input) in C
 *
 * Algorithm:
 * 1. Define the node structure with `data` and `next`.
 * 2. Read the number of nodes and values from the user.
 * 3. Build the initial list by appending each new node at the tail.
 * 4. Read the new value and the target insertion position.
 * 5. If position == 1, insert the new node at the beginning.
 * 6. Otherwise, move to the node before the insertion position.
 * 7. Link the new node into the list by adjusting pointers.
 * 8. Print the updated linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void traverseList(struct Node *head)
{
    struct Node *current = head;
    printf("Linked list: ");
    while (current != NULL)
    {
        printf("[%d] ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter at least 1 node.\n");
        return 1;
    }

    int value;
    printf("Enter value for node 1: ");
    scanf("%d", &value);
    struct Node *head = createNode(value);
    struct Node *tail = head;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        tail->next = createNode(value);
        tail = tail->next;
    }

    printf("\nOriginal linked list:\n");
    traverseList(head);

    int position;
    printf("\nEnter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1)
    {
        printf("Invalid position. Please choose between 1 and %d.\n", n + 1);
        return 1;
    }

    struct Node *newNode = createNode(value);
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        for (int i = 1; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("\nLinked list after insertion at position %d:\n", position);
    traverseList(head);

    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/*
 * Explanation:
 *
 * - Each linked list node stores an integer value and a pointer to the next node.
 * - The list is built from user input values and stored in the order entered.
 * - To insert a new node at a given position:
 *     1. If position is 1, make the new node the new head.
 *     2. Otherwise, move to the node that currently occupies position-1.
 *     3. Set the new node's `next` pointer to the next node.
 *     4. Set the previous node's `next` pointer to the new node.
 * - The updated list is printed in a readable format.
 * - Finally, the program releases memory by freeing every node.
 */
