/**
 * Unit 1 — Doubly Linked List (DLL)
 * Operations:
 *   - Creation
 *   - Forward and Backward Traversal
 *   - Insertion: Beginning, End, and Arbitrary Position
 *   - Deletion: Beginning, End, and Arbitrary Position
 *   - Memory safety and 4-way link verification
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

DLLNode* create_dll_node(int item) {
    DLLNode *node = (DLLNode *)malloc(sizeof(DLLNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed (OVERFLOW)\n");
        return NULL;
    }
    node->data = item;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void forward_traverse_dll(const DLLNode *head) {
    printf("  Forward:  [");
    const DLLNode *ptr = head;
    while (ptr != NULL) {
        printf("%d%s", ptr->data, (ptr->next != NULL) ? " <-> " : "");
        ptr = ptr->next;
    }
    printf("]\n");
}

void backward_traverse_dll(const DLLNode *head) {
    if (head == NULL) {
        printf("  Backward: []\n");
        return;
    }
    const DLLNode *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    printf("  Backward: [");
    while (ptr != NULL) {
        printf("%d%s", ptr->data, (ptr->prev != NULL) ? " <-> " : "");
        ptr = ptr->prev;
    }
    printf("]\n");
}

int insert_begin_dll(DLLNode **head, int item) {
    DLLNode *newNode = create_dll_node(item);
    if (newNode == NULL) return 0;

    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    return 1;
}

int insert_end_dll(DLLNode **head, int item) {
    DLLNode *newNode = create_dll_node(item);
    if (newNode == NULL) return 0;

    if (*head == NULL) {
        *head = newNode;
        return 1;
    }

    DLLNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return 1;
}

int insert_position_dll(DLLNode **head, int item, int pos) {
    if (pos < 1) {
        printf("  Error: Invalid position %d\n", pos);
        return 0;
    }
    if (pos == 1) {
        return insert_begin_dll(head, item);
    }

    DLLNode *temp = *head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("  Error: Position %d out of bounds\n", pos);
        return 0;
    }

    DLLNode *newNode = create_dll_node(item);
    if (newNode == NULL) return 0;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return 1;
}

int delete_begin_dll(DLLNode **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }
    DLLNode *ptr = *head;
    *item = ptr->data;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(ptr);
    return 1;
}

int delete_end_dll(DLLNode **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }
    if ((*head)->next == NULL) {
        *item = (*head)->data;
        free(*head);
        *head = NULL;
        return 1;
    }

    DLLNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    *item = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return 1;
}

int delete_position_dll(DLLNode **head, int pos, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }
    if (pos < 1) {
        printf("  Error: Invalid position %d\n", pos);
        return 0;
    }
    if (pos == 1) {
        return delete_begin_dll(head, item);
    }

    DLLNode *temp = *head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("  Error: Position %d out of bounds\n", pos);
        return 0;
    }

    *item = temp->data;
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return 1;
}

void free_dll(DLLNode **head) {
    DLLNode *curr = *head;
    while (curr != NULL) {
        DLLNode *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int main(void) {
    printf("=== UNIT 1: Doubly Linked List (DLL) Tests ===\n\n");

    DLLNode *head = NULL;

    /* 1. Build List: 10 <-> 20 <-> 30 */
    insert_end_dll(&head, 20);
    insert_begin_dll(&head, 10);
    insert_end_dll(&head, 30);
    printf("1. List created (10, 20, 30):\n");
    forward_traverse_dll(head);
    backward_traverse_dll(head);

    /* 2. Insert 25 at position 3 */
    printf("\n2. Insert 25 at position 3:\n");
    insert_position_dll(&head, 25, 3);
    forward_traverse_dll(head);
    backward_traverse_dll(head);
    /* Expect: 10 <-> 20 <-> 25 <-> 30 */

    /* 3. Delete operations */
    int val = 0;
    delete_begin_dll(&head, &val);
    printf("\n3. Deleted from beginning (val=%d):\n", val);
    forward_traverse_dll(head);
    assert(val == 10);

    delete_end_dll(&head, &val);
    printf("4. Deleted from end (val=%d):\n", val);
    forward_traverse_dll(head);
    assert(val == 30);

    /* Remaining: 20 <-> 25 */
    delete_position_dll(&head, 2, &val);
    printf("5. Deleted at position 2 (val=%d):\n", val);
    forward_traverse_dll(head);
    backward_traverse_dll(head);
    assert(val == 25);

    free_dll(&head);
    assert(head == NULL);
    printf("\n6. List successfully freed.\n");

    printf(">>> All Doubly Linked List tests passed successfully!\n\n");
    return 0;
}
