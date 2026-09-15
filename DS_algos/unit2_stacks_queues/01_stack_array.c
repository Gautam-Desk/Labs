/**
 * Unit 2 — Stack Implementation Using Array
 * Operations:
 *   - PUSH with OVERFLOW check
 *   - POP with UNDERFLOW check
 *   - PEEK / TOP inspection
 *   - DISPLAY stack contents from TOP down to 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STACK_SIZE 5

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} ArrayStack;

void init_stack(ArrayStack *s) {
    s->top = -1;
}

int is_empty(const ArrayStack *s) {
    return (s->top == -1);
}

int is_full(const ArrayStack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

int push(ArrayStack *s, int item) {
    if (is_full(s)) {
        printf("  Error: Stack OVERFLOW (Capacity %d reached)\n", MAX_STACK_SIZE);
        return 0;
    }
    s->top++;
    s->data[s->top] = item;
    return 1;
}

int pop(ArrayStack *s, int *item) {
    if (is_empty(s)) {
        printf("  Error: Stack UNDERFLOW (Empty stack)\n");
        return 0;
    }
    *item = s->data[s->top];
    s->top--;
    return 1;
}

int peek(const ArrayStack *s, int *item) {
    if (is_empty(s)) {
        printf("  Error: Stack is empty (Cannot peek)\n");
        return 0;
    }
    *item = s->data[s->top];
    return 1;
}

void display_stack(const ArrayStack *s) {
    if (is_empty(s)) {
        printf("  Stack is Empty\n");
        return;
    }
    printf("  Stack (TOP -> BOTTOM): ");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d]%s", s->data[i], (i == 0) ? "" : " -> ");
    }
    printf("\n");
}

int main(void) {
    printf("=== UNIT 2: Array-Based Stack Tests ===\n\n");

    ArrayStack s;
    init_stack(&s);

    assert(is_empty(&s));

    /* 1. Push elements */
    printf("1. Pushing 10, 20, 30:\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display_stack(&s);

    /* 2. Peek test */
    int top_val = 0;
    peek(&s, &top_val);
    printf("2. PEEK value = %d (Expected: 30)\n", top_val);
    assert(top_val == 30);

    /* 3. Fill up to capacity and trigger overflow */
    push(&s, 40);
    push(&s, 50);
    printf("3. Pushed up to full capacity:\n");
    display_stack(&s);
    assert(is_full(&s));

    printf("4. Attempting push onto full stack (should report OVERFLOW):\n");
    int ok = push(&s, 60);
    assert(ok == 0);

    /* 4. Pop until empty */
    printf("\n5. Popping elements:\n");
    int popped = 0;
    pop(&s, &popped);
    assert(popped == 50);
    pop(&s, &popped);
    assert(popped == 40);
    display_stack(&s);

    pop(&s, &popped);
    pop(&s, &popped);
    pop(&s, &popped);
    assert(is_empty(&s));

    printf("6. Attempting pop on empty stack (should report UNDERFLOW):\n");
    ok = pop(&s, &popped);
    assert(ok == 0);

    printf("\n>>> All Array-Based Stack tests passed successfully!\n\n");
    return 0;
}
