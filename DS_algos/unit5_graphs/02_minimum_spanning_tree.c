/**
 * Unit 5 — Minimum Spanning Tree (MST)
 * Topics:
 *   - Minimum Spanning Tree Invariant: V vertices, V-1 edges, minimum total weight, no cycles
 *   - Kruskal's Algorithm (Edge-centric, Disjoint Set Union with Path Compression)
 *   - Prim's Algorithm (Vertex-centric greedy selection)
 *   - Verification that both algorithms yield the same optimal MST weight
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_V 20
#define MAX_E 100

/* ========================================================================= */
/* 1. Edge & Disjoint Set Union (DSU) for Kruskal                             */
/* ========================================================================= */

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int parent[MAX_V];
    int rank[MAX_V];
} DSU;

void dsu_init(DSU *dsu, int n) {
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

int dsu_find(DSU *dsu, int i) {
    if (dsu->parent[i] == i) {
        return i;
    }
    return dsu->parent[i] = dsu_find(dsu, dsu->parent[i]); /* Path compression */
}

bool dsu_union(DSU *dsu, int x, int y) {
    int root_x = dsu_find(dsu, x);
    int root_y = dsu_find(dsu, y);

    if (root_x == root_y) {
        return false; /* Cycle detected */
    }

    /* Union by rank */
    if (dsu->rank[root_x] < dsu->rank[root_y]) {
        dsu->parent[root_x] = root_y;
    } else if (dsu->rank[root_x] > dsu->rank[root_y]) {
        dsu->parent[root_y] = root_x;
    } else {
        dsu->parent[root_y] = root_x;
        dsu->rank[root_x]++;
    }
    return true;
}

static int compare_edges(const void *a, const void *b) {
    const Edge *e1 = (const Edge *)a;
    const Edge *e2 = (const Edge *)b;
    return e1->weight - e2->weight;
}

int kruskal_mst(Edge edges[], int num_edges, int num_vertices, Edge mst_out[]) {
    qsort(edges, num_edges, sizeof(Edge), compare_edges);

    DSU dsu;
    dsu_init(&dsu, num_vertices);

    int mst_count = 0;
    int total_weight = 0;

    for (int i = 0; i < num_edges && mst_count < num_vertices - 1; i++) {
        if (dsu_union(&dsu, edges[i].src, edges[i].dest)) {
            mst_out[mst_count++] = edges[i];
            total_weight += edges[i].weight;
        }
    }
    return total_weight;
}

/* ========================================================================= */
/* 2. Prim's Algorithm                                                       */
/* ========================================================================= */

int prim_mst(int graph[MAX_V][MAX_V], int num_vertices, int parent_out[]) {
    int key[MAX_V];
    bool in_mst[MAX_V];

    for (int i = 0; i < num_vertices; i++) {
        key[i] = INT_MAX;
        in_mst[i] = false;
    }

    key[0] = 0;
    parent_out[0] = -1;

    for (int count = 0; count < num_vertices - 1; count++) {
        /* Find min key vertex not yet included in MST */
        int min_val = INT_MAX, u = -1;
        for (int v = 0; v < num_vertices; v++) {
            if (!in_mst[v] && key[v] < min_val) {
                min_val = key[v];
                u = v;
            }
        }

        if (u == -1) break;
        in_mst[u] = true;

        /* Update key values of adjacent vertices */
        for (int v = 0; v < num_vertices; v++) {
            if (graph[u][v] && !in_mst[v] && graph[u][v] < key[v]) {
                parent_out[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total_weight = 0;
    for (int i = 1; i < num_vertices; i++) {
        total_weight += graph[i][parent_out[i]];
    }
    return total_weight;
}

/* ========================================================================= */
/* Verification & Test Harness                                               */
/* ========================================================================= */

int main(void) {
    printf("========================================================\n");
    printf("   Unit 5: Minimum Spanning Tree (MST)\n");
    printf("========================================================\n\n");

    /* Graph with 5 vertices (0 to 4):
     * (0)-(1) w:2
     * (0)-(3) w:6
     * (1)-(2) w:3
     * (1)-(3) w:8
     * (1)-(4) w:5
     * (2)-(4) w:7
     * (3)-(4) w:9
     */
    int num_vertices = 5;

    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    /* Test Kruskal's */
    Edge kruskal_result[MAX_V];
    int kruskal_weight = kruskal_mst(edges, num_edges, num_vertices, kruskal_result);

    printf("Kruskal's MST Edges:\n");
    for (int i = 0; i < num_vertices - 1; i++) {
        printf("  (%d - %d) weight: %d\n", kruskal_result[i].src, kruskal_result[i].dest, kruskal_result[i].weight);
    }
    printf("Kruskal's MST Total Weight: %d\n", kruskal_weight);

    /* Test Prim's */
    int adj_matrix[MAX_V][MAX_V] = {0};
    for (int i = 0; i < num_edges; i++) {
        adj_matrix[edges[i].src][edges[i].dest] = edges[i].weight;
        adj_matrix[edges[i].dest][edges[i].src] = edges[i].weight;
    }

    int prim_parents[MAX_V];
    int prim_weight = prim_mst(adj_matrix, num_vertices, prim_parents);

    printf("\nPrim's MST Edges:\n");
    for (int i = 1; i < num_vertices; i++) {
        printf("  (%d - %d) weight: %d\n", prim_parents[i], i, adj_matrix[i][prim_parents[i]]);
    }
    printf("Prim's MST Total Weight: %d\n", prim_weight);

    /* Both must produce identical minimum weight (2 + 3 + 5 + 6 = 16) */
    assert(kruskal_weight == 16);
    assert(prim_weight == 16);

    printf("\n[PASS] All Minimum Spanning Tree tests passed successfully!\n");
    return 0;
}
