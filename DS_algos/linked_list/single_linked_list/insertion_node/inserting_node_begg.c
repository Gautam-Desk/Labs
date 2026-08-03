/*
 * Singly Linked List Insertion at Beginning (User Input) in C
 *
 * Algorithm:
 * 1. Define a node structure with a data field and a pointer to the next node.
 * 2. Read the number of nodes and values from the user.
 * 3. Build the linked list by appending nodes in the entered order.
 * 4. Read a new value to insert at the beginning.
 * 5. Create a new node and set newNode->next = head.
 * 6. Update head = newNode.
 * 7. Traverse and print the updated list.
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void traverseList(struct Node *head)
{
    struct Node *current = head;
    printf("Linked list elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
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
        printf("Number of nodes should be at least 1.\n");
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

    printf("Original list:\n");
    traverseList(head);

    printf("Enter value to insert at the beginning: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;

    printf("After inserting at the beginning:\n");
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
 * - The program defines a linked list node with `data` and a `next` pointer.
 * - It reads the number of nodes from the user and then reads each node value.
 * - The list is built by appending nodes to the tail, preserving input order.
 * - To insert at the beginning, a new node is created and its `next` pointer is
 *   set to the current head.
 * - The head pointer is updated to point to the new node.
 * - The updated linked list is then traversed and printed.
 * - Finally, the program frees all allocated nodes.
 */
