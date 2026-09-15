/**
 * Unit 4 — Binary Tree Traversals
 * Topics:
 *   - Binary Tree Node Definition & Creation
 *   - Depth-First Traversals (DFS): Inorder, Preorder, Postorder (Recursive)
 *   - Iterative Inorder Traversal using an Explicit Stack
 *   - Breadth-First Traversal (BFS): Level-Order Traversal using a Queue
 *   - Properties & Utilities: Height, Node Count, Leaf Count, Tree Memory Freeing
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ========================================================================= */
/* 1. Tree Node Structure & Creation                                         */
/* ========================================================================= */

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *create_node(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Free tree memory (Postorder cleanup) */
void free_tree(TreeNode *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/* ========================================================================= */
/* 2. Recursive Traversals (DFS)                                             */
/* ========================================================================= */

void preorder_recursive(const TreeNode *root, int *buffer, int *count) {
    if (!root) return;
    buffer[(*count)++] = root->data;
    preorder_recursive(root->left, buffer, count);
    preorder_recursive(root->right, buffer, count);
}

void inorder_recursive(const TreeNode *root, int *buffer, int *count) {
    if (!root) return;
    inorder_recursive(root->left, buffer, count);
    buffer[(*count)++] = root->data;
    inorder_recursive(root->right, buffer, count);
}

void postorder_recursive(const TreeNode *root, int *buffer, int *count) {
    if (!root) return;
    postorder_recursive(root->left, buffer, count);
    postorder_recursive(root->right, buffer, count);
    buffer[(*count)++] = root->data;
}

/* ========================================================================= */
/* 3. Iterative Inorder Traversal using Explicit Stack                       */
/* ========================================================================= */

#define MAX_STACK 128

void inorder_iterative(TreeNode *root, int *buffer, int *count) {
    *count = 0;
    TreeNode *stack[MAX_STACK];
    int top = -1;
    TreeNode *curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        buffer[(*count)++] = curr->data;
        curr = curr->right;
    }
}

/* ========================================================================= */
/* 4. Level-Order Traversal (BFS) using Queue                                */
/* ========================================================================= */

#define MAX_QUEUE 128

void level_order_traversal(TreeNode *root, int *buffer, int *count) {
    *count = 0;
    if (!root) return;

    TreeNode *queue[MAX_QUEUE];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode *curr = queue[front++];
        buffer[(*count)++] = curr->data;

        if (curr->left && rear < MAX_QUEUE) {
            queue[rear++] = curr->left;
        }
        if (curr->right && rear < MAX_QUEUE) {
            queue[rear++] = curr->right;
        }
    }
}

/* ========================================================================= */
/* 5. Tree Properties & Metrics                                              */
/* ========================================================================= */

int tree_height(const TreeNode *root) {
    if (!root) return 0;
    int lh = tree_height(root->left);
    int rh = tree_height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int count_nodes(const TreeNode *root) {
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_leaves(const TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return count_leaves(root->left) + count_leaves(root->right);
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 4: Binary Tree Traversals & Properties\n");
    printf("========================================================\n\n");

    /* Construct sample tree:
     *            1
     *          /   \
     *         2     3
     *        / \   / \
     *       4   5 6   7
     */
    TreeNode *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    int buffer[64];
    int count = 0;

    /* Test Preorder: 1, 2, 4, 5, 3, 6, 7 */
    count = 0;
    preorder_recursive(root, buffer, &count);
    printf("Preorder Traversal:   ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    assert(buffer[0] == 1 && buffer[1] == 2 && buffer[2] == 4 && buffer[6] == 7);

    /* Test Inorder (Recursive): 4, 2, 5, 1, 6, 3, 7 */
    count = 0;
    inorder_recursive(root, buffer, &count);
    printf("Inorder (Recursive):  ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    assert(buffer[0] == 4 && buffer[1] == 2 && buffer[2] == 5 && buffer[3] == 1);

    /* Test Inorder (Iterative): 4, 2, 5, 1, 6, 3, 7 */
    count = 0;
    inorder_iterative(root, buffer, &count);
    printf("Inorder (Iterative):  ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    assert(buffer[0] == 4 && buffer[1] == 2 && buffer[3] == 1 && buffer[6] == 7);

    /* Test Postorder: 4, 5, 2, 6, 7, 3, 1 */
    count = 0;
    postorder_recursive(root, buffer, &count);
    printf("Postorder Traversal:  ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    assert(buffer[0] == 4 && buffer[1] == 5 && buffer[6] == 1);

    /* Test Level-Order: 1, 2, 3, 4, 5, 6, 7 */
    count = 0;
    level_order_traversal(root, buffer, &count);
    printf("Level-Order (BFS):    ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    for (int i = 0; i < 7; i++) assert(buffer[i] == i + 1);

    /* Metrics */
    int h = tree_height(root);
    int total = count_nodes(root);
    int leaves = count_leaves(root);

    printf("\nTree Height:       %d (Expected: 3)\n", h);
    printf("Total Nodes:       %d (Expected: 7)\n", total);
    printf("Total Leaf Nodes:  %d (Expected: 4)\n", leaves);

    assert(h == 3);
    assert(total == 7);
    assert(leaves == 4);

    free_tree(root);
    printf("\n[PASS] All Binary Tree Traversal tests passed successfully!\n");
    return 0;
}
