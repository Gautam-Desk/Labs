/**
 * Unit 4 — Binary Search Tree (BST)
 * Topics:
 *   - BST Definition & Ordering Property (Left < Node < Right)
 *   - BST Insertion
 *   - BST Search (Recursive & Iterative)
 *   - Finding Minimum & Maximum Keys
 *   - BST Deletion (Leaf, One Child, Two Children with Inorder Successor)
 *   - Inorder Traversal (Yields Sorted Keys)
 *   - BST Invariant Validation
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

/* ========================================================================= */
/* 1. BST Node & Helper Functions                                            */
/* ========================================================================= */

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *create_bst_node(int key) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (!node) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_bst(BSTNode *root) {
    if (!root) return;
    free_bst(root->left);
    free_bst(root->right);
    free(root);
}

/* ========================================================================= */
/* 2. BST Insertion                                                          */
/* ========================================================================= */

BSTNode *bst_insert(BSTNode *root, int key) {
    if (root == NULL) {
        return create_bst_node(key);
    }
    if (key < root->key) {
        root->left = bst_insert(root->left, key);
    } else if (key > root->key) {
        root->right = bst_insert(root->right, key);
    }
    /* Duplicate keys are ignored */
    return root;
}

/* ========================================================================= */
/* 3. BST Search                                                             */
/* ========================================================================= */

BSTNode *bst_search_recursive(BSTNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return bst_search_recursive(root->left, key);
    }
    return bst_search_recursive(root->right, key);
}

BSTNode *bst_search_iterative(BSTNode *root, int key) {
    BSTNode *curr = root;
    while (curr != NULL) {
        if (curr->key == key) return curr;
        if (key < curr->key) curr = curr->left;
        else curr = curr->right;
    }
    return NULL;
}

/* ========================================================================= */
/* 4. Extremes: Min and Max                                                  */
/* ========================================================================= */

BSTNode *bst_find_min(BSTNode *root) {
    if (!root) return NULL;
    BSTNode *curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

BSTNode *bst_find_max(BSTNode *root) {
    if (!root) return NULL;
    BSTNode *curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

/* ========================================================================= */
/* 5. BST Deletion                                                           */
/* ========================================================================= */

BSTNode *bst_delete(BSTNode *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = bst_delete(root->left, key);
    } else if (key > root->key) {
        root->right = bst_delete(root->right, key);
    } else {
        /* Node with key found */

        /* Case 1: Leaf node (no children) */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Case 2: One child */
        if (root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: Two children
         * Replace with inorder successor (smallest in the right subtree)
         */
        BSTNode *successor = bst_find_min(root->right);
        root->key = successor->key;
        root->right = bst_delete(root->right, successor->key);
    }
    return root;
}

/* ========================================================================= */
/* 6. Inorder Traversal & Validation                                         */
/* ========================================================================= */

void bst_inorder(const BSTNode *root, int *buffer, int *count) {
    if (!root) return;
    bst_inorder(root->left, buffer, count);
    buffer[(*count)++] = root->key;
    bst_inorder(root->right, buffer, count);
}

bool is_valid_bst(const BSTNode *root, long min_val, long max_val) {
    if (root == NULL) return true;
    if (root->key <= min_val || root->key >= max_val) return false;
    return is_valid_bst(root->left, min_val, root->key) &&
           is_valid_bst(root->right, root->key, max_val);
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 4: Binary Search Tree (BST) Operations\n");
    printf("========================================================\n\n");

    BSTNode *root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = bst_insert(root, keys[i]);
    }

    assert(is_valid_bst(root, LONG_MIN, LONG_MAX));

    /* Inorder check: must be sorted 20, 30, 40, 50, 60, 70, 80 */
    int buffer[32];
    int count = 0;
    bst_inorder(root, buffer, &count);

    printf("Initial BST Inorder (Sorted): ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 7);
    int expected_sorted[] = {20, 30, 40, 50, 60, 70, 80};
    for (int i = 0; i < count; i++) assert(buffer[i] == expected_sorted[i]);

    /* Search tests */
    BSTNode *found1 = bst_search_recursive(root, 40);
    assert(found1 != NULL && found1->key == 40);
    BSTNode *found2 = bst_search_iterative(root, 99);
    assert(found2 == NULL);

    /* Min and Max tests */
    BSTNode *min_node = bst_find_min(root);
    BSTNode *max_node = bst_find_max(root);
    printf("Minimum Key: %d (Expected: 20)\n", min_node->key);
    printf("Maximum Key: %d (Expected: 80)\n", max_node->key);
    assert(min_node->key == 20);
    assert(max_node->key == 80);

    /* Deletion Case 1: Leaf node (20) */
    root = bst_delete(root, 20);
    count = 0;
    bst_inorder(root, buffer, &count);
    assert(count == 6);
    assert(bst_search_iterative(root, 20) == NULL);
    assert(is_valid_bst(root, LONG_MIN, LONG_MAX));

    /* Deletion Case 2: One child (30 now has only right child 40) */
    root = bst_delete(root, 30);
    count = 0;
    bst_inorder(root, buffer, &count);
    assert(count == 5);
    assert(bst_search_iterative(root, 30) == NULL);
    assert(is_valid_bst(root, LONG_MIN, LONG_MAX));

    /* Deletion Case 3: Two children (50 has left child 40 and right child 70) */
    root = bst_delete(root, 50);
    count = 0;
    bst_inorder(root, buffer, &count);
    assert(count == 4);
    assert(bst_search_iterative(root, 50) == NULL);
    assert(is_valid_bst(root, LONG_MIN, LONG_MAX));

    printf("Inorder after Deletions (20, 30, 50): ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(buffer[0] == 40 && buffer[1] == 60 && buffer[2] == 70 && buffer[3] == 80);

    free_bst(root);
    printf("\n[PASS] All Binary Search Tree tests passed successfully!\n");
    return 0;
}
