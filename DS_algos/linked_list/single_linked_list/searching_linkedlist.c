/*
 * Singly Linked List Search Example in C
 *
 * Algorithm:
 * 1. Define a node structure with data and a next pointer.
 * 2. Build a small linked list by linking nodes together.
 * 3. Read the value to search for from the user.
 * 4. Start traversal from the head node.
 * 5. While the current node is not NULL:
 *       a. If current->data equals the search key, return found.
 *       b. Otherwise, move to the next node.
 * 6. If traversal ends without finding the value, report not found.
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

int searchList(struct Node *head, int key) {
    struct Node *current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0; /* Not found */
}

int main(void) {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    int pos = searchList(head, key);
    if (pos > 0) {
        printf("Value %d found at position %d in the linked list.\n", key, pos);
    } else {
        printf("Value %d not found in the linked list.\n", key);
    }

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
 * - The linked list node is defined with an integer `data` field and a `next`
 *   pointer.
 * - `createNode` allocates a new node and initializes its data and next pointer.
 * - The list is built manually: 10 -> 20 -> 30 -> 40.
 * - `searchList` traverses the list from the head and compares each node's data
 *   with the search key.
 * - If the key is found, the function returns the 1-based position of the node.
 * - If the traversal reaches the end of the list without finding the key, it
 *   returns 0 to indicate not found.
 * - The main function prints the search result and then frees the allocated nodes.
 */
