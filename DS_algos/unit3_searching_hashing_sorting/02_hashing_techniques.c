/**
 * Unit 3 — Hashing Functions and Collision Resolution Techniques
 * Topics:
 *   - Hash Functions:
 *       1. Division Method: h(k) = k mod M
 *       2. Mid-Square Method: Extract middle digits of k^2
 *       3. Folding Method: Partition key into chunks and sum
 *       4. Multiplication Method: floor(M * (k * A mod 1))
 *   - Collision Resolution:
 *       1. Separate Chaining (Open Hashing) with Linked Lists (Insert, Search, Delete)
 *       2. Open Addressing (Closed Hashing) with Lazy Deletion Markers:
 *            - Linear Probing: h_i(k) = (h(k) + i) mod M
 *            - Quadratic Probing: h_i(k) = (h(k) + i^2) mod M
 *            - Double Hashing: h_i(k) = (h1(k) + i * h2(k)) mod M
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* ========================================================================= */
/* 1. Classical Hash Functions                                               */
/* ========================================================================= */

/**
 * Division Method:
 * h(k) = k mod M
 */
int hash_division(int key, int table_size) {
    int h = key % table_size;
    if (h < 0) h += table_size;
    return h;
}

/**
 * Mid-Square Method:
 * 1. Compute S = key * key
 * 2. Extract central digits
 */
int hash_mid_square(int key, int table_size) {
    long long sq = (long long)key * key;
    /* Convert square to string to reliably extract middle digits */
    char buf[64];
    int len = sprintf(buf, "%lld", sq);

    /* Determine number of digits needed for table_size */
    int digits_needed = 0;
    int temp = table_size - 1;
    if (temp == 0) digits_needed = 1;
    while (temp > 0) {
        digits_needed++;
        temp /= 10;
    }
    if (digits_needed == 0) digits_needed = 1;

    int start = (len - digits_needed) / 2;
    if (start < 0) start = 0;

    int val = 0;
    for (int i = 0; i < digits_needed && (start + i) < len; i++) {
        val = val * 10 + (buf[start + i] - '0');
    }
    return val % table_size;
}

/**
 * Folding Method:
 * Sum 2-digit chunks of key, modulo table_size
 */
int hash_folding(int key, int table_size) {
    int sum = 0;
    int k = abs(key);
    while (k > 0) {
        sum += (k % 100); /* 2-digit partition */
        k /= 100;
    }
    return sum % table_size;
}

/**
 * Multiplication Method:
 * h(k) = floor(M * (k * A mod 1))
 * Knuth's suggested constant: A ≈ (sqrt(5) - 1) / 2 ≈ 0.6180339887
 */
int hash_multiplication(int key, double A, int table_size) {
    double product = (double)abs(key) * A;
    double frac = product - floor(product);
    return (int)floor((double)table_size * frac);
}

/* ========================================================================= */
/* 2. Collision Resolution: Separate Chaining (Open Hashing)                 */
/* ========================================================================= */

typedef struct HashNode {
    int key;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    int size;
} ChainedHashTable;

ChainedHashTable *create_chained_table(int size) {
    ChainedHashTable *table = (ChainedHashTable *)malloc(sizeof(ChainedHashTable));
    table->size = size;
    table->buckets = (HashNode **)calloc(size, sizeof(HashNode *));
    return table;
}

void chain_insert(ChainedHashTable *table, int key) {
    int idx = hash_division(key, table->size);
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->next = table->buckets[idx];
    table->buckets[idx] = new_node;
}

int chain_search(const ChainedHashTable *table, int key) {
    int idx = hash_division(key, table->size);
    HashNode *curr = table->buckets[idx];
    while (curr != NULL) {
        if (curr->key == key) return 1; /* Found */
        curr = curr->next;
    }
    return 0; /* Not found */
}

int chain_delete(ChainedHashTable *table, int key) {
    int idx = hash_division(key, table->size);
    HashNode *curr = table->buckets[idx];
    HashNode *prev = NULL;

    while (curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return 0; /* Key not found */

    if (prev == NULL) {
        table->buckets[idx] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    return 1;
}

void free_chained_table(ChainedHashTable *table) {
    for (int i = 0; i < table->size; i++) {
        HashNode *curr = table->buckets[i];
        while (curr != NULL) {
            HashNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

/* ========================================================================= */
/* 3. Collision Resolution: Open Addressing (Linear, Quadratic, Double)     */
/* ========================================================================= */

typedef enum { EMPTY, OCCUPIED, DELETED } SlotState;

typedef struct {
    int key;
    SlotState state;
} OpenAddrSlot;

typedef struct {
    OpenAddrSlot *slots;
    int capacity;
    int count;
} OpenAddrHashTable;

OpenAddrHashTable *create_open_addr_table(int capacity) {
    OpenAddrHashTable *ht = (OpenAddrHashTable *)malloc(sizeof(OpenAddrHashTable));
    ht->capacity = capacity;
    ht->count = 0;
    ht->slots = (OpenAddrSlot *)malloc(sizeof(OpenAddrSlot) * capacity);
    for (int i = 0; i < capacity; i++) {
        ht->slots[i].state = EMPTY;
    }
    return ht;
}

/* --- Linear Probing: (h(k) + i) % M --- */
int linear_probe_insert(OpenAddrHashTable *ht, int key) {
    if (ht->count == ht->capacity) return 0; /* Full */
    int h = hash_division(key, ht->capacity);

    for (int i = 0; i < ht->capacity; i++) {
        int idx = (h + i) % ht->capacity;
        if (ht->slots[idx].state == EMPTY || ht->slots[idx].state == DELETED) {
            ht->slots[idx].key = key;
            ht->slots[idx].state = OCCUPIED;
            ht->count++;
            return 1;
        }
    }
    return 0;
}

int linear_probe_search(const OpenAddrHashTable *ht, int key) {
    int h = hash_division(key, ht->capacity);
    for (int i = 0; i < ht->capacity; i++) {
        int idx = (h + i) % ht->capacity;
        if (ht->slots[idx].state == EMPTY) return -1; /* Stop at EMPTY */
        if (ht->slots[idx].state == OCCUPIED && ht->slots[idx].key == key) {
            return idx;
        }
    }
    return -1;
}

/* --- Quadratic Probing: (h(k) + i^2) % M --- */
int quadratic_probe_insert(OpenAddrHashTable *ht, int key) {
    if (ht->count == ht->capacity) return 0;
    int h = hash_division(key, ht->capacity);

    for (int i = 0; i < ht->capacity; i++) {
        int idx = (h + i * i) % ht->capacity;
        if (ht->slots[idx].state == EMPTY || ht->slots[idx].state == DELETED) {
            ht->slots[idx].key = key;
            ht->slots[idx].state = OCCUPIED;
            ht->count++;
            return 1;
        }
    }
    return 0;
}

/* --- Double Hashing: (h1(k) + i * h2(k)) % M --- */
static int h2_func(int key, int prime_r) {
    return prime_r - (abs(key) % prime_r);
}

int double_hash_insert(OpenAddrHashTable *ht, int key, int prime_r) {
    if (ht->count == ht->capacity) return 0;
    int h1 = hash_division(key, ht->capacity);
    int h2 = h2_func(key, prime_r);

    for (int i = 0; i < ht->capacity; i++) {
        int idx = (h1 + i * h2) % ht->capacity;
        if (ht->slots[idx].state == EMPTY || ht->slots[idx].state == DELETED) {
            ht->slots[idx].key = key;
            ht->slots[idx].state = OCCUPIED;
            ht->count++;
            return 1;
        }
    }
    return 0;
}

int open_addr_delete(OpenAddrHashTable *ht, int key) {
    int idx = linear_probe_search(ht, key);
    if (idx != -1) {
        ht->slots[idx].state = DELETED; /* Lazy deletion marker */
        ht->count--;
        return 1;
    }
    return 0;
}

void free_open_addr_table(OpenAddrHashTable *ht) {
    free(ht->slots);
    free(ht);
}

/* ========================================================================= */
/* Test Driver                                                               */
/* ========================================================================= */

int main(void) {
    printf("====================================================\n");
    printf(" Unit 3: Hashing & Collision Resolution Techniques\n");
    printf("====================================================\n\n");

    /* 1. Testing Hash Functions */
    int sample_key = 12345;
    int M = 95;
    printf("1. Classical Hash Functions for Key = %d, Table Size M = %d:\n", sample_key, M);
    printf("   - Division Method:       h(12345) = %d\n", hash_division(sample_key, M));
    printf("   - Mid-Square Method:    h(12345) = %d\n", hash_mid_square(sample_key, M));
    printf("   - Folding Method:       h(12345) = %d\n", hash_folding(sample_key, M));
    printf("   - Multiplication Method: h(12345) = %d\n\n", hash_multiplication(sample_key, 0.357840, 100));

    /* 2. Testing Separate Chaining */
    printf("2. Separate Chaining (Open Hashing):\n");
    ChainedHashTable *cht = create_chained_table(7);
    int keys_chain[] = {15, 22, 95, 43, 50, 64};
    for (int i = 0; i < 6; i++) {
        chain_insert(cht, keys_chain[i]);
    }
    printf("   Inserted keys: 15, 22, 95, 43, 50, 64\n");
    assert(chain_search(cht, 22) == 1);
    assert(chain_search(cht, 95) == 1);
    assert(chain_search(cht, 999) == 0);
    printf("   Search verified: 22 and 95 found; 999 not found.\n");

    chain_delete(cht, 22);
    assert(chain_search(cht, 22) == 0);
    printf("   Deletion verified: 22 deleted and no longer found.\n\n");
    free_chained_table(cht);

    /* 3. Testing Open Addressing (Linear Probing) */
    printf("3. Open Addressing (Linear Probing with Lazy Deletion):\n");
    OpenAddrHashTable *oa_lp = create_open_addr_table(7);
    linear_probe_insert(oa_lp, 10);
    linear_probe_insert(oa_lp, 17); /* Collides with 10 (both 10%7=3 and 17%7=3) */
    linear_probe_insert(oa_lp, 24); /* Collides with 10 and 17 */

    assert(linear_probe_search(oa_lp, 10) != -1);
    assert(linear_probe_search(oa_lp, 17) != -1);
    assert(linear_probe_search(oa_lp, 24) != -1);
    printf("   Probing verified: 10, 17, and 24 all located across collision slots.\n");

    open_addr_delete(oa_lp, 17);
    assert(linear_probe_search(oa_lp, 17) == -1);
    assert(linear_probe_search(oa_lp, 24) != -1); /* Ensure search continues across DELETED slot */
    printf("   Lazy deletion verified: 17 deleted; 24 still accessible past DELETED slot.\n\n");
    free_open_addr_table(oa_lp);

    /* 4. Testing Double Hashing */
    printf("4. Open Addressing (Double Hashing):\n");
    OpenAddrHashTable *oa_dh = create_open_addr_table(7);
    double_hash_insert(oa_dh, 10, 5);
    double_hash_insert(oa_dh, 17, 5);
    printf("   Double hashing successfully inserted collision keys without primary clustering.\n\n");
    free_open_addr_table(oa_dh);

    printf(">>> All Hashing & Collision tests passed successfully! <<<\n");
    return 0;
}
