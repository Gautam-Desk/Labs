/**
 * Unit 2 — Stack Implementation Using Linked List
 * Eliminates fixed capacity constraints of arrays.
 * TOP is maintained at the head of the linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    int size;
} LinkedStack;

void init_linked_stack(LinkedStack *s) {
    s->top = NULL;
    s->size = 0;
}

int is_empty_ll(const LinkedStack *s) {
    return (s->top == NULL);
}

int push_ll(LinkedStack *s, int item) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed (OVERFLOW)\n");
        return 0;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    return 1;
}

int pop_ll(LinkedStack *s, int *item) {
    if (is_empty_ll(s)) {
        printf("  Error: UNDERFLOW (Empty linked stack)\n");
        return 0;
    }
    StackNode *temp = s->top;
    *item = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return 1;
}

int peek_ll(const LinkedStack *s, int *item) {
    if (is_empty_ll(s)) {
        printf("  Error: Empty stack\n");
        return 0;
    }
    *item = s->top->data;
    return 1;
}

void display_linked_stack(const LinkedStack *s) {
    if (is_empty_ll(s)) {
        printf("  Stack is Empty\n");
        return;
    }
    printf("  Stack (TOP -> BOTTOM): ");
    StackNode *curr = s->top;
    while (curr != NULL) {
        printf("[%d]%s", curr->data, (curr->next != NULL) ? " -> " : "");
        curr = curr->next;
    }
    printf("\n");
}

void free_linked_stack(LinkedStack *s) {
    int dummy;
    while (!is_empty_ll(s)) {
        pop_ll(s, &dummy);
    }
}

int main(void) {
    printf("=== UNIT 2: Linked List Stack Tests ===\n\n");

    LinkedStack s;
    init_linked_stack(&s);

    assert(is_empty_ll(&s));

    /* Push elements */
    push_ll(&s, 100);
    push_ll(&s, 200);
    push_ll(&s, 300);
    printf("1. Pushed 100, 200, 300:\n");
    display_linked_stack(&s);
    assert(s.size == 3);

    /* Peek */
    int top_val = 0;
    peek_ll(&s, &top_val);
    printf("2. PEEK value = %d (Expected: 300)\n", top_val);
    assert(top_val == 300);

    /* Pop */
    int popped = 0;
    pop_ll(&s, &popped);
    printf("3. Popped = %d\n", popped);
    display_linked_stack(&s);
    assert(popped == 300 && s.size == 2);

    /* Free stack safely */
    free_linked_stack(&s);
    assert(is_empty_ll(&s));
    printf("4. Linked stack freed safely.\n");

    printf(">>> All Linked List Stack tests passed successfully!\n\n");
    return 0;
}
