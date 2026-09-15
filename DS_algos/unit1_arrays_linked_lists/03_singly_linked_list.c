/**
 * Unit 1 — Singly Linked List (SLL)
 * Operations:
 *   - Creation & Traversal
 *   - Search
 *   - Insertion: Beginning, End, and Arbitrary Position
 *   - Deletion: Beginning, End, and Arbitrary Position
 *   - Memory safety and leak-free destruction
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * Allocate a new node safely
 */
Node* create_node(int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed (OVERFLOW)\n");
        return NULL;
    }
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

/**
 * Traversal: prints all elements in the list
 */
void traverse_sll(const Node *head) {
    printf("  List: [");
    const Node *ptr = head;
    while (ptr != NULL) {
        printf("%d%s", ptr->data, (ptr->next != NULL) ? " -> " : "");
        ptr = ptr->next;
    }
    printf("]\n");
}

/**
 * Search: returns 1-based position if found, or -1 if not found
 */
int search_sll(const Node *head, int item) {
    const Node *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == item) {
            return pos;
        }
        ptr = ptr->next;
        pos++;
    }
    return -1;
}

/**
 * Insert at Beginning: O(1)
 */
int insert_begin_sll(Node **head, int item) {
    Node *newNode = create_node(item);
    if (newNode == NULL) return 0;

    newNode->next = *head;
    *head = newNode;
    return 1;
}

/**
 * Insert at End: O(n)
 */
int insert_end_sll(Node **head, int item) {
    Node *newNode = create_node(item);
    if (newNode == NULL) return 0;

    if (*head == NULL) {
        *head = newNode;
        return 1;
    }

    Node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return 1;
}

/**
 * Insert at Position (1-based index)
 */
int insert_position_sll(Node **head, int item, int pos) {
    if (pos < 1) {
        printf("  Error: Invalid position %d\n", pos);
        return 0;
    }
    if (pos == 1) {
        return insert_begin_sll(head, item);
    }

    Node *temp = *head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("  Error: Position %d out of bounds\n", pos);
        return 0;
    }

    Node *newNode = create_node(item);
    if (newNode == NULL) return 0;

    newNode->next = temp->next;
    temp->next = newNode;
    return 1;
}

/**
 * Delete from Beginning: O(1)
 */
int delete_begin_sll(Node **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW (Empty list)\n");
        return 0;
    }
    Node *ptr = *head;
    *item = ptr->data;
    *head = (*head)->next;
    free(ptr);
    return 1;
}

/**
 * Delete from End: O(n)
 */
int delete_end_sll(Node **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW (Empty list)\n");
        return 0;
    }
    if ((*head)->next == NULL) {
        *item = (*head)->data;
        free(*head);
        *head = NULL;
        return 1;
    }

    Node *ptr = *head;
    Node *prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    *item = ptr->data;
    prev->next = NULL;
    free(ptr);
    return 1;
}

/**
 * Delete at Position (1-based index)
 */
int delete_position_sll(Node **head, int pos, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }
    if (pos < 1) {
        printf("  Error: Invalid position %d\n", pos);
        return 0;
    }
    if (pos == 1) {
        return delete_begin_sll(head, item);
    }

    Node *temp = *head;
    int i = 1;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("  Error: Position %d out of bounds\n", pos);
        return 0;
    }

    Node *ptr = temp->next;
    *item = ptr->data;
    temp->next = ptr->next;
    free(ptr);
    return 1;
}

/**
 * Free all nodes safely to prevent leaks
 */
void free_sll(Node **head) {
    Node *curr = *head;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int main(void) {
    printf("=== UNIT 1: Singly Linked List (SLL) Tests ===\n\n");

    Node *head = NULL;

    /* 1. Insertion Tests */
    printf("1. Inserting 10, 20 at end:\n");
    insert_end_sll(&head, 10);
    insert_end_sll(&head, 20);
    traverse_sll(head);

    printf("2. Inserting 5 at beginning:\n");
    insert_begin_sll(&head, 5);
    traverse_sll(head);

    printf("3. Inserting 15 at position 3:\n");
    insert_position_sll(&head, 15, 3);
    traverse_sll(head);
    /* Expect list: 5 -> 10 -> 15 -> 20 */

    /* 2. Search Tests */
    int pos15 = search_sll(head, 15);
    int pos99 = search_sll(head, 99);
    printf("\n4. Search 15: found at position %d (Expected: 3)\n", pos15);
    printf("   Search 99: result = %d (Expected: -1)\n", pos99);
    assert(pos15 == 3);
    assert(pos99 == -1);

    /* 3. Deletion Tests */
    int val = 0;
    delete_begin_sll(&head, &val);
    printf("\n5. Deleted from beginning (val=%d):\n", val);
    traverse_sll(head);
    assert(val == 5);

    delete_end_sll(&head, &val);
    printf("6. Deleted from end (val=%d):\n", val);
    traverse_sll(head);
    assert(val == 20);

    /* Current: 10 -> 15. Delete pos 2 (15) */
    delete_position_sll(&head, 2, &val);
    printf("7. Deleted at position 2 (val=%d):\n", val);
    traverse_sll(head);
    assert(val == 15);

    /* 4. Memory Cleanup */
    free_sll(&head);
    assert(head == NULL);
    printf("\n8. List freed successfully. Empty check:\n");
    traverse_sll(head);

    printf(">>> All Singly Linked List tests passed successfully!\n\n");
    return 0;
}
