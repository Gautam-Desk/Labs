/**
 * Unit 1 — Array-Based Linked List
 * Simulates a linked list using parallel arrays:
 *   INFO[]  - stores data elements
 *   LINK[]  - stores indices of the next elements
 *   START   - index of the first active element (-1 if empty)
 *   AVAIL   - index of the first free slot in the available-space pool
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NODES 10

typedef struct {
    int info[MAX_NODES];
    int link[MAX_NODES];
    int start;
    int avail;
} ArrayLinkedList;

void init_array_ll(ArrayLinkedList *list) {
    list->start = -1;
    list->avail = 0;
    for (int i = 0; i < MAX_NODES - 1; i++) {
        list->link[i] = i + 1;
    }
    list->link[MAX_NODES - 1] = -1; /* End of free pool */
}

void traverse_array_ll(const ArrayLinkedList *list) {
    printf("  Array-LL: [");
    int ptr = list->start;
    while (ptr != -1) {
        printf("%d (idx:%d)%s", list->info[ptr], ptr, (list->link[ptr] != -1) ? " -> " : "");
        ptr = list->link[ptr];
    }
    printf("]\n");
}

/**
 * Inserts ITEM after index LOC. If LOC == -1, inserts at beginning (new START).
 */
int insert_array_ll(ArrayLinkedList *list, int item, int loc) {
    if (list->avail == -1) {
        printf("  Error: OVERFLOW (No available slots)\n");
        return -1;
    }

    /* Allocate slot from AVAIL pool */
    int new_idx = list->avail;
    list->avail = list->link[list->avail];

    list->info[new_idx] = item;

    if (loc == -1) {
        /* Insert at beginning */
        list->link[new_idx] = list->start;
        list->start = new_idx;
    } else {
        /* Insert after loc */
        list->link[new_idx] = list->link[loc];
        list->link[loc] = new_idx;
    }

    return new_idx;
}

/**
 * Deletes node after index PREV_LOC. If PREV_LOC == -1, deletes START node.
 */
int delete_array_ll(ArrayLinkedList *list, int prev_loc, int *deleted_item) {
    if (list->start == -1) {
        printf("  Error: UNDERFLOW (List is empty)\n");
        return 0;
    }

    int del_idx;
    if (prev_loc == -1) {
        del_idx = list->start;
        list->start = list->link[del_idx];
    } else {
        del_idx = list->link[prev_loc];
        if (del_idx == -1) {
            printf("  Error: Invalid deletion location\n");
            return 0;
        }
        list->link[prev_loc] = list->link[del_idx];
    }

    *deleted_item = list->info[del_idx];

    /* Return deleted slot back to AVAIL pool */
    list->link[del_idx] = list->avail;
    list->avail = del_idx;

    return 1;
}

int main(void) {
    printf("=== UNIT 1: Array-Based Linked List Simulation Tests ===\n\n");

    ArrayLinkedList list;
    init_array_ll(&list);

    /* Insert 10 at beginning (START) */
    int idx10 = insert_array_ll(&list, 10, -1);
    /* Insert 30 after 10 */
    int idx30 = insert_array_ll(&list, 30, idx10);
    /* Insert 20 between 10 and 30 */
    int idx20 = insert_array_ll(&list, 20, idx10);
    /* Insert 5 at beginning */
    int idx5 = insert_array_ll(&list, 5, -1);

    printf("1. List after insertions (Expected: 5 -> 10 -> 20 -> 30):\n");
    traverse_array_ll(&list);
    assert(list.info[list.start] == 5);
    (void)idx30;
    (void)idx20;
    (void)idx5;

    /* Delete from beginning (5) */
    int val = 0;
    delete_array_ll(&list, -1, &val);
    printf("\n2. Deleted from beginning (val=%d):\n", val);
    traverse_array_ll(&list);
    assert(val == 5);

    /* Delete 20 (which is after idx10) */
    delete_array_ll(&list, idx10, &val);
    printf("3. Deleted 20 after index %d (val=%d):\n", idx10, val);
    traverse_array_ll(&list);
    assert(val == 20);

    printf("\n>>> All Array-Based Linked List tests passed successfully!\n\n");
    return 0;
}
