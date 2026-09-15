/**
 * Unit 4 — Self-Balancing AVL Tree
 * Topics:
 *   - AVL Tree Invariant: Balance Factor BF = height(left) - height(right) in {-1, 0, +1}
 *   - Rotations:
 *       - Left Rotation (RR imbalance)
 *       - Right Rotation (LL imbalance)
 *       - Left-Right Rotation (LR imbalance)
 *       - Right-Left Rotation (RL imbalance)
 *   - Insertion with Automatic Rebalancing
 *   - Deletion with Automatic Rebalancing
 *   - Verification of Heights and Inorder Order
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* ========================================================================= */
/* 1. AVL Node & Helpers                                                     */
/* ========================================================================= */

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int get_height(const AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int get_balance(const AVLNode *node) {
    return (node == NULL) ? 0 : get_height(node->left) - get_height(node->right);
}

AVLNode *create_avl_node(int key) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->height = 1; /* New node initialized at height 1 */
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_avl(AVLNode *root) {
    if (!root) return;
    free_avl(root->left);
    free_avl(root->right);
    free(root);
}

/* ========================================================================= */
/* 2. AVL Rotations                                                          */
/* ========================================================================= */

/**
 * Right Rotation (for LL Case)
 *        y                               x
 *       / \     Right Rotation          /  \
 *      x   T3   -------------->        T1   y
 *     / \                                  / \
 *    T1  T2                               T2  T3
 */
AVLNode *rotate_right(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x; /* New root of subtree */
}

/**
 * Left Rotation (for RR Case)
 *      x                               y
 *     / \      Left Rotation          / \
 *    T1  y    -------------->        x   T3
 *       / \                         / \
 *      T2  T3                      T1  T2
 */
AVLNode *rotate_left(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y; /* New root of subtree */
}

/* ========================================================================= */
/* 3. AVL Insertion with Rebalancing                                         */
/* ========================================================================= */

AVLNode *avl_insert(AVLNode *node, int key) {
    /* 1. Perform standard BST insertion */
    if (node == NULL) {
        return create_avl_node(key);
    }

    if (key < node->key) {
        node->left = avl_insert(node->left, key);
    } else if (key > node->key) {
        node->right = avl_insert(node->right, key);
    } else {
        return node; /* Duplicate keys not allowed */
    }

    /* 2. Update height of ancestor */
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    /* 3. Check balance factor */
    int balance = get_balance(node);

    /* Case 1: Left-Left (LL) */
    if (balance > 1 && key < node->left->key) {
        return rotate_right(node);
    }

    /* Case 2: Right-Right (RR) */
    if (balance < -1 && key > node->right->key) {
        return rotate_left(node);
    }

    /* Case 3: Left-Right (LR) */
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    /* Case 4: Right-Left (RL) */
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

/* ========================================================================= */
/* 4. AVL Deletion with Rebalancing                                          */
/* ========================================================================= */

static AVLNode *min_value_node(AVLNode *node) {
    AVLNode *curr = node;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

AVLNode *avl_delete(AVLNode *root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = avl_delete(root->left, key);
    } else if (key > root->key) {
        root->right = avl_delete(root->right, key);
    } else {
        /* Node with target key found */
        if (root->left == NULL || root->right == NULL) {
            AVLNode *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp; /* Copy child contents */
            }
            free(temp);
        } else {
            AVLNode *temp = min_value_node(root->right);
            root->key = temp->key;
            root->right = avl_delete(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    /* Update height */
    root->height = 1 + max(get_height(root->left), get_height(root->right));

    /* Check balance factor */
    int balance = get_balance(root);

    /* Left-Left */
    if (balance > 1 && get_balance(root->left) >= 0) {
        return rotate_right(root);
    }

    /* Left-Right */
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    /* Right-Right */
    if (balance < -1 && get_balance(root->right) <= 0) {
        return rotate_left(root);
    }

    /* Right-Left */
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

/* ========================================================================= */
/* 5. Inorder & AVL Invariant Verification                                   */
/* ========================================================================= */

void avl_inorder(const AVLNode *root, int *buffer, int *count) {
    if (!root) return;
    avl_inorder(root->left, buffer, count);
    buffer[(*count)++] = root->key;
    avl_inorder(root->right, buffer, count);
}

bool check_avl_properties(const AVLNode *root) {
    if (!root) return true;
    int bf = get_balance(root);
    if (bf < -1 || bf > 1) return false;
    return check_avl_properties(root->left) && check_avl_properties(root->right);
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 4: Self-Balancing AVL Tree Operations\n");
    printf("========================================================\n\n");

    AVLNode *root = NULL;

    /* Insert strictly increasing values (which would degenerate an ordinary BST to O(n) skew) */
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = avl_insert(root, values[i]);
        assert(check_avl_properties(root));
    }

    /* The root should be balanced and tree height should be <= log2(n) + 1 */
    printf("Root of AVL: %d (Height: %d)\n", root->key, root->height);
    assert(check_avl_properties(root));
    assert(root->height <= 4);

    int buffer[32];
    int count = 0;
    avl_inorder(root, buffer, &count);
    printf("Inorder Traversal: ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");

    assert(count == 6);
    int expected[] = {10, 20, 25, 30, 40, 50};
    for (int i = 0; i < count; i++) assert(buffer[i] == expected[i]);

    /* Test Deletions with Rebalancing */
    root = avl_delete(root, 30);
    assert(check_avl_properties(root));

    count = 0;
    avl_inorder(root, buffer, &count);
    assert(count == 5);

    root = avl_delete(root, 40);
    assert(check_avl_properties(root));

    count = 0;
    avl_inorder(root, buffer, &count);
    printf("Inorder after deleting 30 & 40: ");
    for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
    printf("\n");
    assert(count == 4);

    free_avl(root);
    printf("\n[PASS] All AVL Tree self-balancing tests passed successfully!\n");
    return 0;
}
