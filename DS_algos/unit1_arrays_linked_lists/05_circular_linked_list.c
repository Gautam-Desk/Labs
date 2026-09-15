/**
 * Unit 1 — Circular Singly Linked List (CLL)
 * Operations:
 *   - Creation
 *   - Traversal (cycle detection: stop when TEMP == HEAD)
 *   - Insertion: Beginning, End, and Arbitrary Position
 *   - Deletion: Beginning, End, and Arbitrary Position
 *   - Memory Cleanup
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct CLLNode {
    int data;
    struct CLLNode *next;
} CLLNode;

CLLNode* create_cll_node(int item) {
    CLLNode *node = (CLLNode *)malloc(sizeof(CLLNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    node->data = item;
    node->next = NULL;
    return node;
}

void traverse_cll(const CLLNode *head) {
    if (head == NULL) {
        printf("  List: [Empty]\n");
        return;
    }
    printf("  List: [");
    const CLLNode *temp = head;
    do {
        printf("%d%s", temp->data, (temp->next != head) ? " -> " : " -> (HEAD)]\n");
        temp = temp->next;
    } while (temp != head);
}

int insert_begin_cll(CLLNode **head, int item) {
    CLLNode *newNode = create_cll_node(item);
    if (newNode == NULL) return 0;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return 1;
    }

    CLLNode *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
    return 1;
}

int insert_end_cll(CLLNode **head, int item) {
    CLLNode *newNode = create_cll_node(item);
    if (newNode == NULL) return 0;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return 1;
    }

    CLLNode *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    return 1;
}

int insert_position_cll(CLLNode **head, int item, int pos) {
    if (pos < 1) {
        printf("  Error: Invalid position\n");
        return 0;
    }
    if (pos == 1) {
        return insert_begin_cll(head, item);
    }
    if (*head == NULL) {
        printf("  Error: Position out of bounds\n");
        return 0;
    }

    CLLNode *temp = *head;
    int i = 1;
    while (i < pos - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) {
        printf("  Error: Position out of range\n");
        return 0;
    }

    CLLNode *newNode = create_cll_node(item);
    if (newNode == NULL) return 0;

    newNode->next = temp->next;
    temp->next = newNode;
    return 1;
}

int delete_begin_cll(CLLNode **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }

    if ((*head)->next == *head) {
        *item = (*head)->data;
        free(*head);
        *head = NULL;
        return 1;
    }

    CLLNode *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    CLLNode *ptr = *head;
    *item = ptr->data;
    *head = (*head)->next;
    temp->next = *head;
    free(ptr);
    return 1;
}

int delete_end_cll(CLLNode **head, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }

    if ((*head)->next == *head) {
        *item = (*head)->data;
        free(*head);
        *head = NULL;
        return 1;
    }

    CLLNode *temp = *head;
    CLLNode *prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    *item = temp->data;
    prev->next = *head;
    free(temp);
    return 1;
}

int delete_position_cll(CLLNode **head, int pos, int *item) {
    if (*head == NULL) {
        printf("  Error: UNDERFLOW\n");
        return 0;
    }
    if (pos < 1) {
        printf("  Error: Invalid position\n");
        return 0;
    }
    if (pos == 1) {
        return delete_begin_cll(head, item);
    }

    CLLNode *temp = *head;
    int i = 1;
    while (i < pos - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    CLLNode *ptr = temp->next;
    if (ptr == *head) {
        printf("  Error: Position out of range\n");
        return 0;
    }

    *item = ptr->data;
    temp->next = ptr->next;
    free(ptr);
    return 1;
}

void free_cll(CLLNode **head) {
    if (*head == NULL) return;
    CLLNode *curr = *head;
    CLLNode *next_node = NULL;
    do {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    } while (curr != *head);
    *head = NULL;
}

int main(void) {
    printf("=== UNIT 1: Circular Linked List (CLL) Tests ===\n\n");

    CLLNode *head = NULL;

    /* 1. Insertion Tests */
    insert_end_cll(&head, 20);
    insert_begin_cll(&head, 10);
    insert_end_cll(&head, 40);
    insert_position_cll(&head, 30, 3);
    printf("1. List created: 10 -> 20 -> 30 -> 40 -> (HEAD)\n");
    traverse_cll(head);

    /* 2. Deletions */
    int val = 0;
    delete_begin_cll(&head, &val);
    printf("2. Deleted from beginning (val=%d):\n", val);
    traverse_cll(head);
    assert(val == 10);

    delete_end_cll(&head, &val);
    printf("3. Deleted from end (val=%d):\n", val);
    traverse_cll(head);
    assert(val == 40);

    delete_position_cll(&head, 2, &val);
    printf("4. Deleted position 2 (val=%d):\n", val);
    traverse_cll(head);
    assert(val == 30);

    /* 3. Free CLL */
    free_cll(&head);
    assert(head == NULL);
    printf("5. Circular list freed. Check empty:\n");
    traverse_cll(head);

    printf(">>> All Circular Linked List tests passed successfully!\n\n");
    return 0;
}
